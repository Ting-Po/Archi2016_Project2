#ifndef EX_H
#define EX_H
#include "ID_EX.h"
#include "EX_MEM.h"
#include "IF_ID.h"
#include "IF.h"
#include"ID.h"
#include<cstring>


class EX
{
    public:
        EX();
        virtual ~EX();

        int RegWrite;
        int RegDst;
        int ALUSrc;
        int MemWrite;
        int MemRead;
        int MemtoReg;

        int instruction;
        int Read_Data1;
        int Read_Data2;

        int signimmed;
        int unsignimmed;

        char rt;
        char rd;

        char opcode;
        char funct;
        char rs;
        char shamt;
        int address;
        char out[8];
        int stall;
        char ex_memdst;
        int fwd_rs;
        int fwd_rt;

        int forwarding;
        int isNOP;
        void Exdo(int* err,IF* ifif, ID* id,IF_ID* if_id,ID_EX* id_ex, EX_MEM* ex_mem);
        int pc;

    protected:
    private:
};

#endif // EX_H
