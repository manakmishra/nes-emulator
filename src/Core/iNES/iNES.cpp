#include "iNES.h"
#include "../Cartridge/Cartridge.h"

#include <iostream>
#include <fstream>
#include <vector>

const int iNESMagic = 0x1a53454e;

struct Header {
	uint32_t Magic;
	uint8_t NumPRG;
	uint8_t NumCHR;
	uint8_t Control1;
	uint8_t Control2;
	uint8_t NumRAM;
	uint8_t _res[7];
};

Cartridge* iNES::loadNESFile(const std::string& path) {
	std::fstream in(path.c_str(), std::ios::binary | std::ios::in);
	struct Header header;

	if (in.is_open()) {
		in.read((char*)&header, sizeof(Header));

		if (header.Magic != iNESMagic) {
			std::cerr << "invalid .nes file header" << std::endl;
			exit(-1);
		}

		//mapper type
		int mapper1 = int(header.Control1) >> 4;
		int mapper2 = int(header.Control2) >> 4;
		int mapper = mapper1 | mapper2 << 4;

		//mirror type
		int mirror1 = int(header.Control1) & 1;
		int mirror2 = int(header.Control1 >> 3) & 1;
		int mirror = mirror1 | mirror2 << 1;

		//battery-backed RAM
		bool battery = (header.Control1 & 2) == 2;

		if ((header.Control1 & 4) == 4) {
			std::vector<uint8_t> trainer(512);
			in.read((char*)&trainer[0], 512);
		}

		int size = int(header.NumPRG) * 16384;
		std::vector<uint8_t> prg(size);
		in.read((char*)&prg[0], size);

		size = int(header.NumCHR) * 8192;
		std::vector<uint8_t> chr(size);
		in.read((char*)&chr[0], size);

		Cartridge cartridge(prg, chr, mapper, mirror, battery);
		in.close();

		return &cartridge;
	} else {
		std::cerr << "Error! File cannot be opened!" << std::endl;
		exit(-1);
	}
}