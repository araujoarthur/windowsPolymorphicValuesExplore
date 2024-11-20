#include <iostream>
#include <windows.h>
#include <bitset>

typedef struct _tagPTEST {
    short x;
    short y;
} PTEST, *PPTEST;

int main()
{
    //unsigned long a = 0x007D0230;
    unsigned long a = 0xF0F1F2F3;
    unsigned long* b = &a;
    PPTEST c = nullptr;
    void* d = (void*)b;
    c = (PTEST*)d;
    POINTS e = MAKEPOINTS(a);
    
    constexpr BYTE bytemasklen = (byte)(sizeof(DWORD_PTR)*8);
    
    std::cout << "Mask Used: " << std::bitset<bytemasklen>(0xFFFF) << " of size " << bytemasklen << "sizeof DWORD_PTR: " << sizeof(DWORD_PTR) << " sizeof DWORD: " << sizeof(DWORD) << "\n\n";
    // HIWORD:  ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff)) Casts L to DWORD_PTR, performs L & 0xFFFF then casts it to a WORD.
    std::cout << " STEPS OF HIWORD                HEX     DEC                 BIN\n";
    std::cout << "CAST L TO A DWORD_PTR:        " << std::hex << DWORD_PTR(a) << " " << std::dec << DWORD_PTR(a) << "  " << std::bitset<bytemasklen>(DWORD_PTR(a)) << "\n";
    std::cout << "SHIFT RIGHT L BY 16:          " << std::hex << (DWORD_PTR(a) >> 16) << "         " << std::dec << (DWORD_PTR(a) >> 16) << "   " << std::bitset<bytemasklen>((DWORD_PTR(a) >> 16)) << "\n";
    std::cout << "PERFORMS BITWISE & 0xffff:    " << std::hex << ((DWORD_PTR(a) >> 16)& 0xffff) << "         " << std::dec << ((DWORD_PTR(a) >> 16) & 0xffff) << "   " << std::bitset<bytemasklen>((DWORD_PTR(a) >> 16) & 0xffff) << "\n";
	std::cout << "CASTS IT ALL TO A WORD:       " << std::hex << WORD((DWORD_PTR(a) >> 16) & 0xffff) << "         " << std::dec << WORD((DWORD_PTR(a) >> 16) & 0xffff) << "   " << std::bitset<bytemasklen>(WORD(DWORD_PTR(a) >> 16) & 0xffff) << "\n";

    //LOWORD:           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
	std::cout << "\n\n\n STEPS OF LOWORD                HEX     DEC                 BIN\n";
	std::cout << "CAST L TO A DWORD_PTR:        " << std::hex << DWORD_PTR(a) << " " << std::dec << DWORD_PTR(a) << "  " << std::bitset<bytemasklen>(DWORD_PTR(a)) << "\n";
	std::cout << "PERFORMS BITWISE & 0xffff:    " << std::hex << ((DWORD_PTR(a)) & 0xffff) << "         " << std::dec << ((DWORD_PTR(a)) & 0xffff) << "   " << std::bitset<bytemasklen>((DWORD_PTR(a)) & 0xffff) << "\n";
	std::cout << "CASTS IT ALL TO A WORD:       " << std::hex << WORD((DWORD_PTR(a)) & 0xffff) << "         " << std::dec << WORD((DWORD_PTR(a)) & 0xffff) << "   " << std::bitset<bytemasklen>(WORD(DWORD_PTR(a)) & 0xffff) << "\n";
    
    std::cout << "\n\n\n";
    //MAKEPOINTS(l)       (*((POINTS FAR *)&(l)))
    std::cout << "\n\n\n STEPS OF MAKEPOINTS                   \n";
    std::cout << "L IS                                   "<< a << " | " << std::hex << a << " | " << std::bitset<bytemasklen>(a) << "\n";
	std::cout << "GETS THE ADDRESS OF L:                  " << std::hex << &a << " " << std::dec << &a << "  " << "..." << "\n";
    std::cout << "  INTEGER:                                 " << "ADDRESS:     " << std::hex << (size_t)&a << "\n";
    std::cout << "  INTEGER:                                 " << "MID ADDRESS: " << std::hex << (size_t)&a + ((size_t)sizeof(a) / 2) << "(" << std::dec << ((size_t)sizeof(a) / 2) << ")\n";
    std::cout << "  INTEGER:                                 " << "END ADDRESS: " << std::hex << (size_t)&a + (size_t)sizeof(a) << "(" << std::dec << ((size_t)sizeof(a)) << ")\n";
    std::cout << "CASTS IT TO A POINTER TO POINTS:        " << std::hex <<  ((POINTS*) &a) << " " << std::dec << ((POINTS*)&a) << "  " << "..." << "\n";
    std::cout << "  STRUCT:                                  " << std::dec << "Value X:" << ((POINTS*)&a)->x << " Value Y:" << ((POINTS*)&a)->y << "\n";
    std::cout << "  STRUCT:                                  " << std::dec << "Address X:" << &(((POINTS*)&a)->x) << " Address Y:" << &(((POINTS*)&a)->y) << "\n";
    std::cout << "DEREF THE POINTER:                      " << std::hex << &(*((POINTS*)&a)) << " " << std::dec << &(*((POINTS*)&a)) << "  " << "..." << "\n";
	std::cout << "  STRUCT:                                  " << std::dec << "Value X:" << (*((POINTS*)&a)).x << " Value Y:" << (*((POINTS*)&a)).y << "\n";
    std::cout << "  STRUCT:                                  " << std::dec << "Bin X:" << std::bitset<bytemasklen>((*((POINTS*)&a)).x) << "\n";
    std::cout << "                                           Bin Y:" << std::bitset<bytemasklen>((*((POINTS*)&a)).y) << "\n";
	std::cout << "  STRUCT:                                  " << std::dec << "Address X:" << &((*((POINTS*)&a)).x) << " Address Y:" << &((*((POINTS*)&a)).y) << "\n";
    std::cout << "\n\n";

    std::cout << " Original Bin:       " << std::bitset<bytemasklen>(a) << "\n";
	std::cout << " Bin X:              " << std::bitset<bytemasklen>((*((POINTS*)&a)).x) << "\n\n";
	std::cout << " Bin Y:              " << std::bitset<bytemasklen>((*((POINTS*)&a)).y) << "\n";
    std::cout << " Original Bin >> 16: " << std::bitset<bytemasklen>(a>>16) << "\n";
    std::cout << "\n\n";

	std::cout << " Original Hex:       " << std::hex << (a) << "\n";
	std::cout << " Hex X:              " << std::hex << ((*((POINTS*)&a)).x) << "\n\n";
	std::cout << " Hex Y:              " << std::hex << ((*((POINTS*)&a)).y) << "\n";
	std::cout << " Original Hex >> 16: " << std::hex << (a >> 16) << "\n";
	std::cout << "\n\n";

    std::cout << a << " shifted right by 16 is dec: " << ((a >> 16) & 0xffff) << "  hex: " << std::hex << ((a >> 16)&0xffff) << "  bin<32>: " << std::bitset<32>(((a >> 16) & 0xffff)) << "\n";
    std::cout << HIWORD(a) << " " << LOWORD(a) << "\n" << "\n" << "\n";
	std::cout << std::hex << e.x << " " << e.y << "\n";
	std::cout << std::dec << e.x << " " << e.y << "\n";
    std::cout << std::hex << c->x << " " << c->y << "\n";
    std::cout << std::dec << c->x << " " << c->y << "\n";
    std::cout << "C-Long: " << sizeof(long) << "\n";
    std::cout << "C-Short: " << sizeof(short) << "\n";
    std::cout << "Win-Long: " << sizeof(LONG) << "\n";
    std::cout << "Win-Short: " << sizeof(SHORT) << "\n";
    std::cout << "Win-WParam: " << sizeof(WPARAM) << "\n";
    std::cout << "Win-LParam: " << sizeof(LPARAM) << "\n";
    std::cout << "__int64: " << sizeof(__int64) << "\n";
    std::cout << "__int3264: " << sizeof(__int3264) << "\n";
    std::cout << "Win-INT_PTR: " << sizeof(INT_PTR) << "\n";
    std::cout << "Win-LONG_PTR: " << sizeof(LONG_PTR) << "\n";
}
