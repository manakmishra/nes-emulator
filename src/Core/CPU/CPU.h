#include <cstdint>
#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

class CPU {
private:
	uint16_t PC;
	uint8_t SP;
	uint8_t A, X, Y;
	bool C, Z, I, D, B, V, N;
public:
	uint8_t getFlags();
	uint8_t setFlags(uint8_t flags);
};

#endif // !CPU_H_INCLUDED
