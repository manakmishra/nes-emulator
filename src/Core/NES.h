#ifndef NES_H_INCLUDED
#define NES_H_INCLUDED

#include <string>
#include "CPU/CPU.h"
#include "Cartridge/Cartridge.h"

class NES {
public:
	NES(const std::string& path);

	Cartridge* cartridge;
	CPU* cpu;
};

#endif // !NES_H_INCLUDED
