#ifndef NES_H_INCLUDED
#define NES_H_INCLUDED

#include "CPU/CPU.h"
#include "Cartridge/Cartridge.h"
#include "iNES/iNES.h"

#include <string>

class NES {
private:
	CPU *cpu;

public:
	Cartridge* cartridge;

	NES(const std::string& path);
};

#endif // !NES_H_INCLUDED
