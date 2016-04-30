#ifndef MEM_H
#define MEM_H
#include "Memory.h"
#include "EX_MEM.h"
#include "MEM_WB.h"
#include "EX.h"
#include "IF_ID.h"
#include "ID_EX.h"


class MEM
{
    public:
        MEM();
        virtual ~MEM();
        int MemWrite;
        int MemRead;
        int Writedata;
        int Address;
        int Readdata;

        int RegWrite;
        int MemtoReg;
        int RegDst;

        char rt;
        char rd;
        char opcode;

        int instruction;
        char* out;
        int stall;

        void MEMdo(ID_EX* id_ex,EX* ex,IF_ID* if_id,Memory* mem,EX_MEM* ex_mem, MEM_WB* mem_wb);

    protected:
    private:
};

#endif // MEM_H
