#include "Cartridge.h"

Cartridge::Cartridge(std::vector<uint8_t> prg, std::vector<uint8_t> chr, int mp, int mr, bool b) {
	PRG = prg;
	CHR = chr;
	Mapper = mp;
	Mirror = mr;
	Battery = b;
}

uint8_t Cartridge::Read(uint16_t address) {
	int index = (int(address) - 0x8000) % PRG.size();
	//return PRG[index];
	return 0;
}