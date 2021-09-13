#include "CPU.h"
#include <iostream>

CPU::CPU(Memory mem) {
	memory = mem;
	Reset();
}

void CPU::Reset() {
	PC = memory.Read16(0xFFFC);
}

uint8_t CPU::ReadPC() {
	uint8_t res = memory.Read(PC);
	PC++;
	return res;
}

uint16_t CPU::ReadPC16() {
	uint8_t res = memory.Read16(PC);
	PC += 2;
	return res;
}

void CPU::Step() {
	std::cout << "PC: " << (int)PC << "\n";
	std::cout << "SP: " << (int)SP << "\n";
	std::cout << "A: " << (int)A << "\tX: " << (int)X << "\tY: "<< (int)Y << "\n";
	std::cout << "C: " << (int)C << "\tZ: " << (int)Z << "\tI: " << (int)I << "\tD: " << (int)D << "\n";
	std::cout << "B: " << (int)B << "\tV: " << (int)V << "\tN: " << (int)N << "\n";
	ExecuteInstruction();

	std::cout << "\n\n";
}

void CPU::ExecuteInstruction() {
	auto opcode = ReadPC();
	std::cout << "opcode: " << opcode << "\n";

	switch(opcode){
	case 0x69:
		ADC(Immediate());
	case 0x78:
		SEI();
	case 0x9A:
		TXS();
	case 0xA2:
		LDX(Immediate());
	case 0xAD:
		LDA(Absolute());
	case 0xD8:
		CLD();
	default:
		std::cout << "Unrecognized opcode: 0x%02x " << opcode << "\n";
	}
}

uint8_t CPU::Flags() {
	uint8_t flags = 0x00;
	flags |= C << 0;
	flags |= Z << 1;
	flags |= I << 2;
	flags |= D << 3;
	flags |= B << 4;
	flags |= V << 6;
	flags |= N << 7;

	return flags;
}

void CPU::setFlags(uint8_t flags) {
	C = (flags >> 0) & 1;
	Z = (flags >> 1) & 1;
	I = (flags >> 2) & 1;
	D = (flags >> 3) & 1;
	B = (flags >> 4) & 1;
	V = (flags >> 6) & 1;
	N = (flags >> 7) & 1;
}

void CPU::SetZ(uint8_t value) {
	if (value == 0) {
		Z = 1;
	}
	else
	{
		Z = 0;
	}
}

void CPU::SetN(uint8_t value) {
	if ((value & 0x80) != 0) {
		N = 1;
	}
	else
	{
		N = 0;
	}
}

uint16_t CPU::Immediate() {
	auto res = PC;
	PC++;
	return res;
}

uint16_t CPU::ZeroPage() {
	return uint16_t(ReadPC());
}

uint16_t CPU::ZeroPageX() {
	return uint16_t(ReadPC() + X);
}

uint16_t CPU::ZeroPageY() {
	return uint16_t(ReadPC() + Y);
}

uint16_t CPU::Relative() {
	uint16_t offset = uint16_t(ReadPC());
	if (offset < 0x80) {
		return PC + offset;
	}
	else
	{
		return PC + offset - 0x100;
	}
}

uint16_t CPU::Absolute() {
	return ReadPC16();
}

uint16_t CPU::AbsoluteX() {
	return ReadPC16() + uint16_t(X);
}

uint16_t CPU::AbsoluteY() {
	return ReadPC16() + uint16_t(Y);
}

uint16_t CPU::Indirect() {
	uint16_t a = ReadPC16();
	uint16_t b = (a & 0xFF00) | uint16_t(uint8_t(a) + 1);
	uint8_t lo = memory.Read(a);
	uint8_t hi = memory.Read(b);

	return uint16_t(hi) << 8 | uint16_t(lo);
}

uint16_t CPU::IndexedIndirect() {
	return memory.Read16(uint16_t(ReadPC() + X));
}

uint16_t CPU::IndirectIndexed() {
	return memory.Read16(uint16_t(ReadPC())) + uint16_t(Y);
}

void CPU::ADC(uint16_t address) {
	//TODO: implement Add with Carry
}

void CPU::CLD() {
	D = 0;
}

void CPU::LDA(uint16_t address) {
	A = memory.Read(address);
	SetZ(A);
	SetN(A);
}

void CPU::LDX(uint16_t address) {
	X = memory.Read(address);
	SetZ(X);
	SetN(X);
}

void CPU::SEI() {
	I = 1;
}

void CPU::TXS() {
	SP = X;
}
