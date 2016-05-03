#ifndef FUNCTION_H
#define FUNCTION_H
#include "InstruM.h"
#include "Reg.h"
#include "Memory.h"

class Function
{
    public:
        Function();
        virtual ~Function();
        void add(InstruM* ins, int pc,Reg* r,int* err);
        void addu(InstruM* ins, int pc,Reg* r, int* err);
        void sub(InstruM* ins, int pc,Reg* r, int* err);
        void And(InstruM* ins, int pc,Reg* r,int* err);
        void Or(InstruM* ins, int pc,Reg* r, int* err);
        void Xor(InstruM* ins, int pc,Reg* r,int* err);
        void nor(InstruM* ins, int pc, Reg* r,int* err);
        void nand(InstruM* ins, int pc, Reg* r,int* err);
        void slt(InstruM* ins, int pc, Reg* r,int* err);
        void sll(InstruM* ins, int pc, Reg* r,int* err);
        void srl(InstruM* ins, int pc, Reg* r,int* err);
        void sra(InstruM* ins, int pc, Reg* r,int* err);

        void addi(InstruM* ins, int pc, Reg* r,int* err);
        void addiu(InstruM* ins, int pc, Reg* r,int* err);
        void lw(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void lh(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void lhu(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void lb(InstruM* ins, int pc, Reg* r,Memory* m,int* err);
        void lbu(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void sw(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void sh(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void sb(InstruM* ins, int pc, Reg* r, Memory* m,int* err);
        void lui(InstruM* ins, int pc, Reg* r, Memory* m,int* err);

        void andi(InstruM* ins,int pc, Reg* r,int* err);
        void ori(InstruM* ins, int pc, Reg* r,int* err);
        void nori(InstruM* ins, int pc, Reg* r,int* err);
        void slti(InstruM* ins, int pc, Reg* r,int* err);
        int beq(InstruM* ins, int pc, Reg* r,int* err);
        int bne(InstruM* ins, int pc, Reg* r,int* err);
        int bgtz(InstruM* ins, int pc, Reg* r,int* err);

        int j(InstruM* ins, int pc, Reg* r,int* err);
        int jal(InstruM* ins, int pc, Reg* r,int* err);

    protected:
    private:
};

#endif // FUNCTION_H
