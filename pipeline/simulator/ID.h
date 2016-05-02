#ifndef ID_H
#define ID_H
#include "IF_ID.h"
#include "ID_EX.h"
#include "Reg.h"
#include "IF.h"
#include<cstring>


class ID
{
    public:
        ID();
        virtual ~ID();
        int pc;
        int instruction;
        char opcode;

        int Read_Data1;
        int Read_Data2;
        short immed;
        unsigned short unimmed;
        char rt;
        char rd;

        char funct;
        char rs;
        char shamt;
        int address;

        char out[8];
        int forwarding;
        int fwdrs;
        int fwdrt;
        int stall;
        int isNOP;
        void IDdo(IF_ID* if_id, ID_EX* id_ex,IF* ifif,Reg* r);
    protected:
    private:
};

#endif // ID_H
