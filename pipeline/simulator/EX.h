#ifndef EX_H
#define EX_H
#include "ID_EX.h"
#include "EX_MEM.h"
#include "IF_ID.h"
#include "IF.h"
#include"ID.h"


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
        char* out;
        int stall;

        int forwarding;
        void Exdo(IF* ifif, ID* id,IF_ID* if_id,ID_EX* id_ex, EX_MEM* ex_mem);

    protected:
    private:
};

#endif // EX_H
