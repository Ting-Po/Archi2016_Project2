#include "MEM_WB.h"

MEM_WB::MEM_WB()
{
     Readdata = 0;
     ALUresult = 0;
     MemtoReg = 0;
     RegWrite = 0;
     RegDst = 0;
     opcode = 0;

     instruction = 0;
     rt = -1;
     rd = -1;
     out = "NOP";
    //ctor
}

MEM_WB::~MEM_WB()
{
    //dtor
}
