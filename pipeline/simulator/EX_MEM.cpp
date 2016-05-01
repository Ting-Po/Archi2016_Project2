#include "EX_MEM.h"

EX_MEM::EX_MEM()
{
    //ctor
    RegWrite =-1;
    MemWrite =-1;
    MemRead =-1;
    MemtoReg =-1;
    RegDst = -1;

    opcode = -1;
    instruction = -1;
    Read_Data2=-1;
    rt=-1;
    rd=-1;

    ALUresult = -1;
    strcpy(out , "NOP");
    isNOP = 0;
}

EX_MEM::~EX_MEM()
{
    //dtor
}
