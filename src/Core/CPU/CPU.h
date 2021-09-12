#include <cstdint>
#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

class CPU {
private:
	uint16_t PC;
	uint8_t SP;
	uint8_t A, X, Y;
	uint8_t C, Z, I, D, B, V, N;
public:
	uint8_t Flags();
	void setFlags(uint8_t flags);
};

#endif // !CPU_H_INCLUDED
