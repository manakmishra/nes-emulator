#include "CPU.h"

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