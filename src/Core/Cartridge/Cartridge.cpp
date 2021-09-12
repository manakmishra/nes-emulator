#include "Cartridge.h"
#include <iostream>

Cartridge::Cartridge(uint8_t* prg, uint8_t* chr, int mp, int mr, bool b) {
	PRG = prg;
	CHR = chr;
	Mapper = mp;
	Mirror = mr;
	Battery = b;
}

uint8_t Cartridge::Read(uint16_t address) {
	int index = (int(address) - 0x8000) % (sizeof(PRG) / sizeof(PRG[0]));
	return PRG[index];
}