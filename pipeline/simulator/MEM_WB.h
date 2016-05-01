#ifndef MEM_WB_H
#define MEM_WB_H
#include<cstring>


class MEM_WB
{
    public:
        MEM_WB();
        virtual ~MEM_WB();
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
    protected:
    private:
};

#endif // MEM_WB_H
