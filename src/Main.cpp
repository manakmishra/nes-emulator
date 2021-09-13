#include "Core/NES.h"
#include <iostream>

int main() {
	NES nes = NES("roms/nestest.nes");
	for (int i = 0; i < 10; i++) {
		nes.cpu->Step();
	}
	return 0;
}