#ifndef WB_H
#define WB_H
#include "Reg.h"
#include "MEM_WB.h"
#include<cstring>


class WB
{
    public:
        WB();
        virtual ~WB();
        int Readdata;
        int ALUresult;
        int MemtoReg;
        int RegWrite;
        int RegDst;

        int instruction;
        char opcode;
        char rt;
        char rd;
        char out[8];
        int isNOP;
        void WBdo(MEM_WB* mem_wb, Reg* r);
    protected:
    private:
};

#endif // WB_H
