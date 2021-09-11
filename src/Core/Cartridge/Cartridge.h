#ifndef CARTRIDGE_H_INCLUDED
#define CARTRIDGE_H_INCLUDED

#include <cstdint>

const int MirrorHorizontal = 0;
const int MirrorVertical = 1;
const int MirrorQuad = 2;

struct Cartridge {
	Cartridge(uint8_t* prg, uint8_t* chr, int mp, int mr, bool b) {
		PRG = prg;
		CHR = chr;
		Mapper = mp;
		Mirror = mr;
		Battery = b;
	}

	uint8_t* PRG;
	uint8_t* CHR;
	int Mapper;
	int Mirror;
	bool Battery;
};

#endif // !CARTRIDGE_H_INCLUDED
