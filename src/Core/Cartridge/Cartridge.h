#ifndef CARTRIDGE_H_INCLUDED
#define CARTRIDGE_H_INCLUDED

#include <iostream>
#include <vector>

const int MirrorHorizontal = 0;
const int MirrorVertical = 1;
const int MirrorQuad = 2;

class Cartridge{
public:
	Cartridge(std::vector<uint8_t> prg, std::vector<uint8_t> chr, int mp, int mr, bool b);
	uint8_t Read(uint16_t address);

private:
	std::vector<uint8_t> PRG;
	std::vector<uint8_t> CHR;
	int Mapper;
	int Mirror;
	bool Battery;
};

#endif // !CARTRIDGE_H_INCLUDED
