#ifndef ID_EX_H
#define ID_EX_H
#include<cstring>



class ID_EX
{
    public:
        ID_EX();
        virtual ~ID_EX();

        int Branch;
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
        int isNOP;
        int pc;

    protected:
    private:
};

#endif // ID_EX_H
