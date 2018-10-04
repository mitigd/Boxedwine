void dynamic_addr8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
        instCPUReg('+', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adde8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_addr8e8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instCPUReg('+', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_add8_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('+', OFFSET_REG8(op->reg), DYN_8bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('+', DYN_DEST, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_add8_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('+', DYN_ADDRESS, DYN_8bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_addr16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adde16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_addr16e16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_add16_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('+', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('+', DYN_DEST, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_add16_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('+', DYN_ADDRESS, DYN_16bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_addr32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adde32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_addr32e32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_add32_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('+', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('+', DYN_DEST, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_add32_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('+', DYN_ADDRESS, DYN_32bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADD32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_orr8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
        instCPUReg('|', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('|', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_ore8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        instMemReg('|', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('|', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_orr8e8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instCPUReg('|', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('|', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_or8_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('|', OFFSET_REG8(op->reg), DYN_8bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('|', DYN_DEST, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_or8_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('|', DYN_ADDRESS, DYN_8bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('|', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_orr16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
        instCPUReg('|', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('|', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_ore16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        instMemReg('|', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('|', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_orr16e16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instCPUReg('|', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('|', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_or16_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('|', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('|', DYN_DEST, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_or16_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('|', DYN_ADDRESS, DYN_16bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('|', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_orr32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
        instCPUReg('|', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('|', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_ore32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instMemReg('|', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('|', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_orr32e32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instCPUReg('|', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('|', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_or32_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('|', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('|', DYN_DEST, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_or32_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('|', DYN_ADDRESS, DYN_32bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('|', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_OR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adcr8r8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_8bit, true);
        instCPUReg('+', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adce8r8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_8bit, true);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToRegFromReg(DYN_DEST, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        instRegReg('+', DYN_CALL_RESULT, DYN_DEST, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adcr8e8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_DEST, OFFSET_REG8(op->reg), DYN_8bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, true);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adc8_reg(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_8bit, op->imm);
        instCPUReg('+', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('+', DYN_DEST, DYN_8bit, op->imm);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adc8_mem(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToRegFromReg(DYN_SRC, DYN_8bit, DYN_CALL_RESULT, DYN_8bit, true);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_8bit, op->imm);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adcr16r16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_16bit, true);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adce16r16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_16bit, true);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToRegFromReg(DYN_DEST, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        instRegReg('+', DYN_CALL_RESULT, DYN_DEST, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adcr16e16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, true);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adc16_reg(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_16bit, op->imm);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('+', DYN_DEST, DYN_16bit, op->imm);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adc16_mem(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToRegFromReg(DYN_SRC, DYN_16bit, DYN_CALL_RESULT, DYN_16bit, true);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_16bit, op->imm);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adcr32r32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_32bit, true);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_32bit, true);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adce32r32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_32bit, true);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToRegFromReg(DYN_DEST, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        instRegReg('+', DYN_CALL_RESULT, DYN_DEST, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adcr32e32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        instRegReg('+', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adc32_reg(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        instRegImm('+', DYN_CALL_RESULT, DYN_32bit, op->imm);
        instCPUReg('+', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('+', DYN_DEST, DYN_32bit, op->imm);
        instRegReg('+', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_adc32_mem(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instRegImm('+', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToRegFromReg(DYN_SRC, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        instMemReg('+', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_32bit, op->imm);
        instRegReg('+', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_ADC32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbr8r8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_8bit, true);
        instCPUReg('-', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbe8r8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_8bit, true);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToRegFromReg(DYN_DEST, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        instRegReg('-', DYN_CALL_RESULT, DYN_DEST, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbr8e8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_DEST, OFFSET_REG8(op->reg), DYN_8bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, true);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbb8_reg(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_8bit, op->imm);
        instCPUReg('-', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('-', DYN_DEST, DYN_8bit, op->imm);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbb8_mem(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromReg(DYN_CALL_RESULT, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToRegFromReg(DYN_SRC, DYN_8bit, DYN_CALL_RESULT, DYN_8bit, true);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_8bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('-', DYN_CALL_RESULT, DYN_8bit, op->imm);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbr16r16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_16bit, true);
        instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbe16r16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_16bit, true);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToRegFromReg(DYN_DEST, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        instRegReg('-', DYN_CALL_RESULT, DYN_DEST, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbr16e16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, true);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbb16_reg(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_16bit, op->imm);
        instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('-', DYN_DEST, DYN_16bit, op->imm);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbb16_mem(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromReg(DYN_CALL_RESULT, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, false);
        instRegImm('+', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToRegFromReg(DYN_SRC, DYN_16bit, DYN_CALL_RESULT, DYN_16bit, true);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_16bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('-', DYN_CALL_RESULT, DYN_16bit, op->imm);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbr32r32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_32bit, true);
        instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_32bit, true);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbe32r32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instRegReg('+', DYN_SRC, DYN_CALL_RESULT, DYN_32bit, true);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToRegFromReg(DYN_DEST, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        instRegReg('-', DYN_CALL_RESULT, DYN_DEST, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbbr32e32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbb32_reg(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        instRegImm('+', DYN_CALL_RESULT, DYN_32bit, op->imm);
        instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('-', DYN_DEST, DYN_32bit, op->imm);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sbb32_mem(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_getCF, true, 1, 0, DYN_PARAM_CPU, false);
    movToCpuFromReg(CPU_OFFSET_OF(oldCF), DYN_CALL_RESULT, DYN_32bit, false);
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instRegImm('+', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToRegFromReg(DYN_SRC, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToRegFromReg(DYN_SRC, DYN_32bit, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('-', DYN_CALL_RESULT, DYN_32bit, op->imm);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SBB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_andr8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
        instCPUReg('&', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_ande8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        instMemReg('&', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('&', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_andr8e8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instCPUReg('&', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_and8_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('&', OFFSET_REG8(op->reg), DYN_8bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('&', DYN_DEST, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_and8_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('&', DYN_ADDRESS, DYN_8bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('&', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_andr16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
        instCPUReg('&', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_ande16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        instMemReg('&', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('&', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_andr16e16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instCPUReg('&', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_and16_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('&', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('&', DYN_DEST, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_and16_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('&', DYN_ADDRESS, DYN_16bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('&', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_andr32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
        instCPUReg('&', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_ande32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instMemReg('&', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('&', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_andr32e32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instCPUReg('&', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_and32_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('&', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('&', DYN_DEST, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_and32_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('&', DYN_ADDRESS, DYN_32bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('&', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_AND32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_subr8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        if (op->rm==op->reg) {
            movToCpu(OFFSET_REG8(op->reg), DYN_8bit, 0);
        } else {
            movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
            instCPUReg('-', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
        }
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sube8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_subr8e8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instCPUReg('-', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sub8_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('-', OFFSET_REG8(op->reg), DYN_8bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('-', DYN_DEST, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sub8_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('-', DYN_ADDRESS, DYN_8bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('-', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_subr16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        if (op->rm==op->reg) {
            movToCpu(CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, 0);
        } else {
            movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
            instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
        }
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sube16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_subr16e16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sub16_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('-', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('-', DYN_DEST, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sub16_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('-', DYN_ADDRESS, DYN_16bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('-', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_subr32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        if (op->rm==op->reg) {
            movToCpu(CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, 0);
        } else {
            movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
            instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
        }
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sube32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instMemReg('-', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_subr32e32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instCPUReg('-', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sub32_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('-', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('-', DYN_DEST, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_sub32_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('-', DYN_ADDRESS, DYN_32bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('-', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_SUB32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xorr8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        if (op->rm==op->reg) {
            movToCpu(OFFSET_REG8(op->reg), DYN_8bit, 0);
        } else {
            movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->rm), DYN_8bit);
            instCPUReg('^', OFFSET_REG8(op->reg), DYN_SRC, DYN_8bit, true);
        }
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('^', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xore8r8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, OFFSET_REG8(op->reg), DYN_8bit);
        instMemReg('^', DYN_ADDRESS, DYN_SRC, DYN_8bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegReg('^', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xorr8e8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_8bit, DYN_ADDRESS, true);
        instCPUReg('^', OFFSET_REG8(op->reg), DYN_CALL_RESULT, DYN_8bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('^', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xor8_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('^', OFFSET_REG8(op->reg), DYN_8bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegImm('^', DYN_DEST, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xor8_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('^', DYN_ADDRESS, DYN_8bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instRegImm('^', DYN_CALL_RESULT, DYN_8bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xorr16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        if (op->rm==op->reg) {
            movToCpu(CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, 0);
        } else {
            movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
            instCPUReg('^', CPU_OFFSET_OF(reg[op->reg].u16), DYN_SRC, DYN_16bit, true);
        }
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('^', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xore16r16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
        instMemReg('^', DYN_ADDRESS, DYN_SRC, DYN_16bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegReg('^', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xorr16e16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_16bit, DYN_ADDRESS, true);
        instCPUReg('^', CPU_OFFSET_OF(reg[op->reg].u16), DYN_CALL_RESULT, DYN_16bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('^', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xor16_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('^', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegImm('^', DYN_DEST, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xor16_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('^', DYN_ADDRESS, DYN_16bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instRegImm('^', DYN_CALL_RESULT, DYN_16bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xorr32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        if (op->rm==op->reg) {
            movToCpu(CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, 0);
        } else {
            movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
            instCPUReg('^', CPU_OFFSET_OF(reg[op->reg].u32), DYN_SRC, DYN_32bit, true);
        }
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('^', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xore32r32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
        instMemReg('^', DYN_ADDRESS, DYN_SRC, DYN_32bit, true, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegReg('^', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xorr32e32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        movFromMem(DYN_32bit, DYN_ADDRESS, true);
        instCPUReg('^', CPU_OFFSET_OF(reg[op->reg].u32), DYN_CALL_RESULT, DYN_32bit, true);
    } else {
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('^', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xor32_reg(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPUImm('^', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, op->imm);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegImm('^', DYN_DEST, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_xor32_mem(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        calculateEaa(op, DYN_ADDRESS);
        instMemImm('^', DYN_ADDRESS, DYN_32bit, op->imm, true);
    } else {
        movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
        calculateEaa(op, DYN_ADDRESS);
        movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instRegImm('^', DYN_CALL_RESULT, DYN_32bit, op->imm);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_XOR32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_cmpr8r8(DynamicData* data, DecodedOp* op) {
    if (op->rm == op->reg) {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromReg(CPU_OFFSET_OF(dst.u8), DYN_SRC, DYN_8bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, true);
    }

    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP8);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpe8r8(DynamicData* data, DecodedOp* op) {
    movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, true, false);
    instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP8);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpr8e8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, true, false);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
    instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_8bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP8);
    INCREMENT_EIP(op->len);
}
void dynamic_cmp8_reg(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
    instRegImm('-', DYN_DEST, DYN_8bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP8);
    INCREMENT_EIP(op->len);
}
void dynamic_cmp8_mem(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, true, false);
    instRegImm('-', DYN_CALL_RESULT, DYN_8bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP8);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpr16r16(DynamicData* data, DecodedOp* op) {
    if (op->rm == op->reg) {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromReg(CPU_OFFSET_OF(dst.u16), DYN_SRC, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, true);
    }

    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP16);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpe16r16(DynamicData* data, DecodedOp* op) {
    movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, true, false);
    instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP16);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpr16e16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, true, false);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
    instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_16bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP16);
    INCREMENT_EIP(op->len);
}
void dynamic_cmp16_reg(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
    instRegImm('-', DYN_DEST, DYN_16bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP16);
    INCREMENT_EIP(op->len);
}
void dynamic_cmp16_mem(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, true, false);
    instRegImm('-', DYN_CALL_RESULT, DYN_16bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP16);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpr32r32(DynamicData* data, DecodedOp* op) {
    if (op->rm == op->reg) {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromReg(CPU_OFFSET_OF(dst.u32), DYN_SRC, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('-', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, true);
    }

    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP32);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpe32r32(DynamicData* data, DecodedOp* op) {
    movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, true, false);
    instRegReg('-', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP32);
    INCREMENT_EIP(op->len);
}
void dynamic_cmpr32e32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, true, false);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
    instRegReg('-', DYN_DEST, DYN_CALL_RESULT, DYN_32bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP32);
    INCREMENT_EIP(op->len);
}
void dynamic_cmp32_reg(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
    instRegImm('-', DYN_DEST, DYN_32bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP32);
    INCREMENT_EIP(op->len);
}
void dynamic_cmp32_mem(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, true, false);
    instRegImm('-', DYN_CALL_RESULT, DYN_32bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_CMP32);
    INCREMENT_EIP(op->len);
}
void dynamic_testr8r8(DynamicData* data, DecodedOp* op) {
    if (op->rm == op->reg) {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromReg(CPU_OFFSET_OF(dst.u8), DYN_SRC, DYN_8bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_SRC, DYN_8bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->rm), DYN_8bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_SRC, DYN_8bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, true);
    }

    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST8);
    INCREMENT_EIP(op->len);
}
void dynamic_teste8r8(DynamicData* data, DecodedOp* op) {
    movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_SRC, false);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, true, false);
    instRegReg('&', DYN_CALL_RESULT, DYN_SRC, DYN_8bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST8);
    INCREMENT_EIP(op->len);
}
void dynamic_test8_reg(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
    instRegImm('&', DYN_DEST, DYN_8bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST8);
    INCREMENT_EIP(op->len);
}
void dynamic_test8_mem(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u8), DYN_8bit, op->imm);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u8), DYN_8bit, DYN_ADDRESS, true, false);
    instRegImm('&', DYN_CALL_RESULT, DYN_8bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST8);
    INCREMENT_EIP(op->len);
}
void dynamic_testr16r16(DynamicData* data, DecodedOp* op) {
    if (op->rm == op->reg) {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromReg(CPU_OFFSET_OF(dst.u16), DYN_SRC, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_SRC, DYN_16bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_SRC, DYN_16bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, true);
    }

    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST16);
    INCREMENT_EIP(op->len);
}
void dynamic_teste16r16(DynamicData* data, DecodedOp* op) {
    movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_SRC, false);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, true, false);
    instRegReg('&', DYN_CALL_RESULT, DYN_SRC, DYN_16bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST16);
    INCREMENT_EIP(op->len);
}
void dynamic_test16_reg(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
    instRegImm('&', DYN_DEST, DYN_16bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST16);
    INCREMENT_EIP(op->len);
}
void dynamic_test16_mem(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u16), DYN_16bit, op->imm);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u16), DYN_16bit, DYN_ADDRESS, true, false);
    instRegImm('&', DYN_CALL_RESULT, DYN_16bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST16);
    INCREMENT_EIP(op->len);
}
void dynamic_testr32r32(DynamicData* data, DecodedOp* op) {
    if (op->rm == op->reg) {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromReg(CPU_OFFSET_OF(dst.u32), DYN_SRC, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_SRC, DYN_32bit, true);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit, DYN_SRC, false);
        movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instRegReg('&', DYN_DEST, DYN_SRC, DYN_32bit, true);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, true);
    }

    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST32);
    INCREMENT_EIP(op->len);
}
void dynamic_teste32r32(DynamicData* data, DecodedOp* op) {
    movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_SRC, false);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, true, false);
    instRegReg('&', DYN_CALL_RESULT, DYN_SRC, DYN_32bit, true);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST32);
    INCREMENT_EIP(op->len);
}
void dynamic_test32_reg(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
    movToCpuFromCpu(CPU_OFFSET_OF(dst.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
    instRegImm('&', DYN_DEST, DYN_32bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST32);
    INCREMENT_EIP(op->len);
}
void dynamic_test32_mem(DynamicData* data, DecodedOp* op) {
    movToCpu(CPU_OFFSET_OF(src.u32), DYN_32bit, op->imm);
    calculateEaa(op, DYN_ADDRESS);
    movToCpuFromMem(CPU_OFFSET_OF(dst.u32), DYN_32bit, DYN_ADDRESS, true, false);
    instRegImm('&', DYN_CALL_RESULT, DYN_32bit, op->imm);
    movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, true);
    movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_TEST32);
    INCREMENT_EIP(op->len);
}
void dynamic_notr8(DynamicData* data, DecodedOp* op) {
instCPU('~', OFFSET_REG8(op->reg), DYN_8bit);
    INCREMENT_EIP(op->len);
}
void dynamic_note8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    instMem('~', DYN_ADDRESS, DYN_8bit, true);
    INCREMENT_EIP(op->len);
}
void dynamic_notr16(DynamicData* data, DecodedOp* op) {
instCPU('~', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
    INCREMENT_EIP(op->len);
}
void dynamic_note16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    instMem('~', DYN_ADDRESS, DYN_16bit, true);
    INCREMENT_EIP(op->len);
}
void dynamic_notr32(DynamicData* data, DecodedOp* op) {
instCPU('~', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
    INCREMENT_EIP(op->len);
}
void dynamic_note32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    instMem('~', DYN_ADDRESS, DYN_32bit, true);
    INCREMENT_EIP(op->len);
}
void dynamic_negr8(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPU('-', OFFSET_REG8(op->reg), DYN_8bit);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u8), OFFSET_REG8(op->reg), DYN_8bit, DYN_DEST, false);
        instReg('-', DYN_DEST, DYN_8bit);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_DEST, DYN_8bit, false);
        movToCpuFromReg(OFFSET_REG8(op->reg), DYN_DEST, DYN_8bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NEG8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_nege8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    if (!op->needsToSetFlags()) {
        instMem('-', DYN_ADDRESS, DYN_8bit, true);
    } else {
        movToCpuFromMem(CPU_OFFSET_OF(src.u8), DYN_8bit, DYN_ADDRESS, false, false);
        instReg('-', DYN_CALL_RESULT, DYN_8bit);
        movToCpuFromReg(CPU_OFFSET_OF(result.u8), DYN_CALL_RESULT, DYN_8bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_8bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NEG8);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_negr16(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPU('-', CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u16), CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit, DYN_DEST, false);
        instReg('-', DYN_DEST, DYN_16bit);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_DEST, DYN_16bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u16), DYN_DEST, DYN_16bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NEG16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_nege16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    if (!op->needsToSetFlags()) {
        instMem('-', DYN_ADDRESS, DYN_16bit, true);
    } else {
        movToCpuFromMem(CPU_OFFSET_OF(src.u16), DYN_16bit, DYN_ADDRESS, false, false);
        instReg('-', DYN_CALL_RESULT, DYN_16bit);
        movToCpuFromReg(CPU_OFFSET_OF(result.u16), DYN_CALL_RESULT, DYN_16bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_16bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NEG16);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_negr32(DynamicData* data, DecodedOp* op) {
    if (!op->needsToSetFlags()) {
        instCPU('-', CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
    } else {
        movToCpuFromCpu(CPU_OFFSET_OF(src.u32), CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit, DYN_DEST, false);
        instReg('-', DYN_DEST, DYN_32bit);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_DEST, DYN_32bit, false);
        movToCpuFromReg(CPU_OFFSET_OF(reg[op->reg].u32), DYN_DEST, DYN_32bit, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NEG32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_nege32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS);
    if (!op->needsToSetFlags()) {
        instMem('-', DYN_ADDRESS, DYN_32bit, true);
    } else {
        movToCpuFromMem(CPU_OFFSET_OF(src.u32), DYN_32bit, DYN_ADDRESS, false, false);
        instReg('-', DYN_CALL_RESULT, DYN_32bit);
        movToCpuFromReg(CPU_OFFSET_OF(result.u32), DYN_CALL_RESULT, DYN_32bit, false);
        movToMemFromReg(DYN_ADDRESS, DYN_CALL_RESULT, DYN_32bit, true, true);
        movToCpu(CPU_OFFSET_OF(lazyFlags), Dyn_PtrSize, (DYN_PTR_SIZE)FLAGS_NEG32);
    }
    INCREMENT_EIP(op->len);
}
void dynamic_mulR8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_mul8, false, 2, 0, DYN_PARAM_CPU, false, OFFSET_REG8(op->reg), DYN_PARAM_CPU_ADDRESS_8, false);
    INCREMENT_EIP(op->len);
}
void dynamic_mulE8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_8bit, DYN_ADDRESS, true);
    callHostFunction(common_mul8, false, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_8, true);
    INCREMENT_EIP(op->len);
}
void dynamic_imulR8(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_imul8, false, 2, 0, DYN_PARAM_CPU, false, OFFSET_REG8(op->reg), DYN_PARAM_CPU_ADDRESS_8, false);
    INCREMENT_EIP(op->len);
}
void dynamic_imulE8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_8bit, DYN_ADDRESS, true);
    callHostFunction(common_imul8, false, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_8, true);
    INCREMENT_EIP(op->len);
}
void dynamic_mulR16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_mul16, false, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u16), DYN_PARAM_CPU_ADDRESS_16, false);
    INCREMENT_EIP(op->len);
}
void dynamic_mulE16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_16bit, DYN_ADDRESS, true);
    callHostFunction(common_mul16, false, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_16, true);
    INCREMENT_EIP(op->len);
}
void dynamic_imulR16(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_imul16, false, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u16), DYN_PARAM_CPU_ADDRESS_16, false);
    INCREMENT_EIP(op->len);
}
void dynamic_imulE16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_16bit, DYN_ADDRESS, true);
    callHostFunction(common_imul16, false, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_16, true);
    INCREMENT_EIP(op->len);
}
void dynamic_mulR32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_mul32, false, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u32), DYN_PARAM_CPU_ADDRESS_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_mulE32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_32bit, DYN_ADDRESS, true);
    callHostFunction(common_mul32, false, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_32, true);
    INCREMENT_EIP(op->len);
}
void dynamic_imulR32(DynamicData* data, DecodedOp* op) {
    callHostFunction(common_imul32, false, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u32), DYN_PARAM_CPU_ADDRESS_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_imulE32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_32bit, DYN_ADDRESS, true);
    callHostFunction(common_imul32, false, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_32, true);
    INCREMENT_EIP(op->len);
}
void dynamic_divR8(DynamicData* data, DecodedOp* op) {
    callHostFunction(div8, true, 2, 0, DYN_PARAM_CPU, false, OFFSET_REG8(op->reg), DYN_PARAM_CPU_ADDRESS_8, false);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_divE8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_8bit, DYN_ADDRESS, true);
    callHostFunction(div8, true, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_8, true);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_idivR8(DynamicData* data, DecodedOp* op) {
    callHostFunction(idiv8, true, 2, 0, DYN_PARAM_CPU, false, OFFSET_REG8(op->reg), DYN_PARAM_CPU_ADDRESS_8, false);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_idivE8(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_8bit, DYN_ADDRESS, true);
    callHostFunction(idiv8, true, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_8, true);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_divR16(DynamicData* data, DecodedOp* op) {
    callHostFunction(div16, true, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u16), DYN_PARAM_CPU_ADDRESS_16, false);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_divE16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_16bit, DYN_ADDRESS, true);
    callHostFunction(div16, true, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_16, true);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_idivR16(DynamicData* data, DecodedOp* op) {
    callHostFunction(idiv16, true, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u16), DYN_PARAM_CPU_ADDRESS_16, false);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_idivE16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_16bit, DYN_ADDRESS, true);
    callHostFunction(idiv16, true, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_16, true);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_divR32(DynamicData* data, DecodedOp* op) {
    callHostFunction(div32, true, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u32), DYN_PARAM_CPU_ADDRESS_32, false);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_divE32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_32bit, DYN_ADDRESS, true);
    callHostFunction(div32, true, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_32, true);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_idivR32(DynamicData* data, DecodedOp* op) {
    callHostFunction(idiv32, true, 2, 0, DYN_PARAM_CPU, false, CPU_OFFSET_OF(reg[op->reg].u32), DYN_PARAM_CPU_ADDRESS_32, false);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_idivE32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_32bit, DYN_ADDRESS, true);
    callHostFunction(idiv32, true, 2, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_32, true);
    startIf(DYN_CALL_RESULT, DYN_EQUALS_ZERO, true);
    blockDone();
    endIf();
    INCREMENT_EIP(op->len);
}
void dynamic_dimulcr16r16(DynamicData* data, DecodedOp* op) {
    movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
    callHostFunction(common_dimul16, false, 4, 0, DYN_PARAM_CPU, false, DYN_DEST, DYN_PARAM_REG_16, true, op->imm, DYN_PARAM_CONST_16, false, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulcr16e16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_16bit, DYN_ADDRESS, true);
    callHostFunction(common_dimul16, false, 4, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_16, true, op->imm, DYN_PARAM_CONST_16, false, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulcr32r32(DynamicData* data, DecodedOp* op) {
    movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
    callHostFunction(common_dimul32, false, 4, 0, DYN_PARAM_CPU, false, DYN_DEST, DYN_PARAM_REG_32, true, op->imm, DYN_PARAM_CONST_32, false, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulcr32e32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_32bit, DYN_ADDRESS, true);
    callHostFunction(common_dimul32, false, 4, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_32, true, op->imm, DYN_PARAM_CONST_32, false, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulr16r16(DynamicData* data, DecodedOp* op) {
    movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->rm].u16), DYN_16bit);
    movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
    callHostFunction(common_dimul16, false, 4, 0, DYN_PARAM_CPU, false, DYN_DEST, DYN_PARAM_REG_16, true, DYN_SRC, DYN_PARAM_REG_16, true, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulr16e16(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_16bit, DYN_ADDRESS, true);
    movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u16), DYN_16bit);
    callHostFunction(common_dimul16, false, 4, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_16, true, DYN_SRC, DYN_PARAM_REG_16, true, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulr32r32(DynamicData* data, DecodedOp* op) {
    movToRegFromCpu(DYN_DEST, CPU_OFFSET_OF(reg[op->rm].u32), DYN_32bit);
    movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
    callHostFunction(common_dimul32, false, 4, 0, DYN_PARAM_CPU, false, DYN_DEST, DYN_PARAM_REG_32, true, DYN_SRC, DYN_PARAM_REG_32, true, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
void dynamic_dimulr32e32(DynamicData* data, DecodedOp* op) {
    calculateEaa(op, DYN_ADDRESS); movFromMem(DYN_32bit, DYN_ADDRESS, true);
    movToRegFromCpu(DYN_SRC, CPU_OFFSET_OF(reg[op->reg].u32), DYN_32bit);
    callHostFunction(common_dimul32, false, 4, 0, DYN_PARAM_CPU, false, DYN_CALL_RESULT, DYN_PARAM_REG_32, true, DYN_SRC, DYN_PARAM_REG_32, true, op->reg, DYN_PARAM_CONST_32, false);
    INCREMENT_EIP(op->len);
}
