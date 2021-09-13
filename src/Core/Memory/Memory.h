#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <cstdint>

class NES;

class Memory {
public:
	Memory() = default;
	Memory(NES* nesObj);

	uint8_t Read(uint16_t address);
	uint16_t Read16(uint16_t address);
	void Write(uint16_t address, uint8_t value);

	NES* nes;
	uint8_t* RAM;
};

#endif // !MEMORY_H_INCLUDED
