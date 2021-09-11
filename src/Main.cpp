#include "Core/iNES/iNES.h"
#include "Core/Cartridge/Cartridge.h"
#include <iostream>

int main() {
	iNES ines = iNES();
	Cartridge* cartridge = ines.loadNESFile("roms/nestest.nes");

	std::cout << "PRG: " << cartridge->PRG << "\n";
	std::cout << "CHR: " << cartridge->CHR << "\n";
	std::cout << "Mapper: " << cartridge->Mapper << "\n";
	std::cout << "Mirror: " << cartridge->Mirror << "\n";
	std::cout << "Battery: " << cartridge->Battery << "\n";

	return 0;
}