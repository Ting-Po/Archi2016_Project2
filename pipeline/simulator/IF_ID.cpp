#include "IF_ID.h"

IF_ID::IF_ID()
{
    After_IF = -1;
    pc = -1;

    Read_Data1=-1;
    Read_Data2=-1;

    immed=-1;
    unimmed = -1;

    rt=-1;
    rd=-1;

    opcode=-1;
    funct=-1;
    rs=-1;
    shamt=-1;
    address=-1;

    strcpy(out , "NOP");
    forwarding = 0;
    isNOP = 0;

}

IF_ID::~IF_ID()
{
    //dtor
}
