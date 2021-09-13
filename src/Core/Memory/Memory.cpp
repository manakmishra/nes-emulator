#include "Memory.h"
#include "../NES.h"

Memory::Memory(NES* nesObj) {
	RAM = new uint8_t[2048];
	nes = nesObj;
}

uint8_t Memory::Read(uint16_t address) {
	std::cout << address << "\n";

	if (address < 0x2000) {
		return RAM[address % 0x8000];
	}
	else if (address >= 0x8000) {
		return nes->cartridge->Read(address);
	}
	
	return 0;
}

uint16_t Memory::Read16(uint16_t address) {
	auto lo = uint16_t(Read(address));
	auto hi = uint16_t(Read(address + 1));

	return hi << 8 | lo;
}
void Memory::Write(uint16_t address, uint8_t value) {
	if (address < 0x2000) {
		RAM[address % 0x8000] = value;
	}
}