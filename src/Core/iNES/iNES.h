#ifndef INES_H_INCLUDED
#define INES_H_INCLUDED

#include <string>

class Cartridge;

class iNES {
public:
	Cartridge* loadNESFile(const std::string& path);
};

#endif // !INES_H_INCLUDED
