#include "NES.h"
#include "Memory/Memory.h"
#include "iNES/iNES.h"

NES::NES(const std::string& path) {
	cartridge = iNES().loadNESFile(path);
	CPU newCPU = CPU(Memory(this));
	cpu = &newCPU;
}