#include "ID_EX.h"

ID_EX::ID_EX()
{
    Branch = -1;
    RegWrite=-1;
    RegDst=-1;
    ALUSrc=-1;
    MemWrite=-1;
    MemRead=-1;
    MemtoReg=-1;

    instruction = -1;
    Read_Data1=-1;
    Read_Data2=-1;

    signimmed=-1;
    unsignimmed = -1;

    rt=-1;
    rd=-1;

    opcode=-1;
    funct=-1;
    rs=-1;
    shamt=-1;
    address=-1;
    out = "NOP";
}

ID_EX::~ID_EX()
{
    //dtor
}
