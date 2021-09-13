#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include <cstdint>
#include "../Memory/Memory.h"

class CPU {
private:
	uint16_t PC;
	uint8_t SP;
	uint8_t A; 
	uint8_t X; 
	uint8_t Y;
	uint8_t C;
	uint8_t Z; 
	uint8_t I; 
	uint8_t D;
	uint8_t B; 
	uint8_t V; 
	uint8_t N;

	Memory memory;

	void ExecuteInstruction();

public:
	CPU(Memory mem);

	uint8_t Flags();
	void setFlags(uint8_t flags);
	void SetZ(uint8_t value);
	void SetN(uint8_t value);

	uint16_t Immediate();
	uint16_t ZeroPage();
	uint16_t ZeroPageX();
	uint16_t ZeroPageY();
	uint16_t Relative();
	uint16_t Absolute();
	uint16_t AbsoluteX();
	uint16_t AbsoluteY();
	uint16_t Indirect();
	uint16_t IndexedIndirect();
	uint16_t IndirectIndexed();

	void ADC(uint16_t address);
	void CLD();
	void LDA(uint16_t address);
	void LDX(uint16_t address);
	void SEI();
	void TXS();

	void Reset();
	uint8_t ReadPC();
	uint16_t ReadPC16();
	void Step();
};

#endif // !CPU_H_INCLUDED
