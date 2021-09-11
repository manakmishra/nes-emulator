#ifndef INES_H_INCLUDED
#define INES_H_INCLUDED

#include <string>

class iNES {
private:
	struct Header;
public:
	struct Cartridge* loadNESFile(const std::string& path);
};

#endif // !INES_H_INCLUDED
