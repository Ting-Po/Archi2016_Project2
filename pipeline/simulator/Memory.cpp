#include "Memory.h"

Memory::Memory()
{
    int i;
    for(i=0;i<1024;i++){
        mem[i] = 0;
    }
    for(i=0;i<8;i++)
        sp_memnum[i] = 0;
    //ctor
}

Memory::~Memory()
{
    //dtor
}
