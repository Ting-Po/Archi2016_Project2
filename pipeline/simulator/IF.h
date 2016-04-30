#ifndef IF_H
#define IF_H
#include "InstruM.h"
#include "Reg.h"
#include "IF_ID.h"



class IF
{
    public:
        IF();
        IF(int pc);
        virtual ~IF();
        int pc;
        int pc_branch;
        int PCSel;
        int instruction;
        char opcode;
        char funct;
        char* out;
        int stall;


        void IFdo(InstruM* ins, Reg* r,IF_ID* if_id);


    protected:
    private:
};

#endif // IF_H
