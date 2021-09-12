#ifndef CARTRIDGE_H_INCLUDED
#define CARTRIDGE_H_INCLUDED

#include <cstdint>

const int MirrorHorizontal = 0;
const int MirrorVertical = 1;
const int MirrorQuad = 2;

class Cartridge{
public:
	Cartridge(uint8_t* prg, uint8_t* chr, int mp, int mr, bool b);
	uint8_t Read(uint16_t address);

private:
	uint8_t* PRG;
	uint8_t* CHR;
	int Mapper;
	int Mirror;
	bool Battery;
};

#endif // !CARTRIDGE_H_INCLUDED
