#include "NES.h"

NES::NES(const std::string& path) {
	iNES ines = iNES();
	cartridge = ines.loadNESFile("roms/nestest.nes");


}