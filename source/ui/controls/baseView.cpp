#include "boxedwine.h"
#include "../boxedwineui.h"

BaseView::BaseView(const std::string& viewName) : errorMsg(NULL), tabIndex(0), viewName(viewName) {
    this->toolTipWidth = (float)ImGui::CalcTextSize("(?)").x + GlobalSettings::scaleIntUI(18);
    this->extraVerticalSpacing = (float)GlobalSettings::scaleIntUI(5);
}

void BaseView::toolTip(const char* desc) {
    SAFE_IMGUI_TEXT_DISABLED("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(GlobalSettings::scaleFloatUI(8.0f), GlobalSettings::scaleFloatUI(8.0f)));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, GlobalSettings::scaleFloatUI(7.0f));
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
        ImGui::PopStyleVar(2);
    }
}

void BaseView::addTab(const std::string& name, int index) {
    ImGui::Dummy(ImVec2(this->extraVerticalSpacing, 0.0f));
    ImGui::SameLine();
    ImVec2 pos = ImGui::GetCursorPos();
    ImVec2 s = ImGui::CalcTextSize(name.c_str(), NULL, true);
    s.x = 0;
    s.y += this->extraVerticalSpacing * 2;
    std::string nameId = "##" + name;
    ImGui::PushStyleColor(ImGuiCol_Header, ImGui::GetColorU32(ImGuiCol_WindowBg) | 0xFF000000);
    if (ImGui::Selectable(nameId.c_str(), tabIndex == index, ImGuiSelectableFlags_AllowRightClick, s)) {
        tabIndex = index;
    }
    ImGui::PopStyleColor();
    pos.y += this->extraVerticalSpacing;
    ImGui::SetCursorPos(pos);
    SAFE_IMGUI_TEXT(name.c_str());
    pos = ImGui::GetCursorPos();
    pos.y += this->extraVerticalSpacing;
    ImGui::SetCursorPos(pos);
}

void BaseView::run(const ImVec2& size) {
    ImVec2 leftSize = ImGui::GetContentRegionAvail();
    ImVec2 rightSize = leftSize;
    leftSize.x = leftSize.x / 4 - 2 * ImGui::GetStyle().FramePadding.x;
    leftSize.y = 0;
    rightSize.x = rightSize.x * 3 / 4 - 2 * ImGui::GetStyle().FramePadding.x;
    rightSize.y = 0;
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::GetColorU32(ImGuiCol_WindowBg) | 0xFF000000);
    ImGui::BeginChild(110, size, false, 0);

    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::GetColorU32(ImGuiCol_TabUnfocusedActive) | 0xFF000000);
    ImGui::BeginChild(111, leftSize, false, 0);
    ImGui::PushFont(GlobalSettings::mediumFont);

    ImGui::Dummy(ImVec2(0.0f, this->extraVerticalSpacing));
    for (int i=0;i<this->tabs.size();i++) {
        addTab(this->tabs[i].name, i);
    }
    ImGui::PopFont();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::BeginChild(112, rightSize, false, 0);
    
    this->tabs[this->tabIndex].drawTab();

    ImGui::EndChild();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    if (this->errorMsg) {
        runErrorMsg(false);
    }
}

void BaseView::runErrorMsg(bool open) {
    if (!showMessageBox(this->viewName + "ErrorMsg", open, getTranslation(GENERIC_DLG_ERROR_TITLE), this->errorMsg)) {
        this->errorMsg = NULL;
    }
}

void BaseView::addTab(const std::string& name, std::function<void()> drawTab) {
    this->tabs.push_back(BaseViewTab(name, drawTab));
}