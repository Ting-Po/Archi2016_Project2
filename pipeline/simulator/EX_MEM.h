#ifndef EX_MEM_H
#define EX_MEM_H
#include<cstring>


class EX_MEM
{
    public:
        EX_MEM();
        virtual ~EX_MEM();
        int RegWrite;
        int MemWrite;
        int MemRead;
        int MemtoReg;
         int RegDst;

        int instruction;
        int Read_Data2;
        char rt;
        char rd;
        char opcode;
        char out[8];
        int isNOP;

        int ALUresult;
    protected:
    private:
};

#endif // EX_MEM_H
