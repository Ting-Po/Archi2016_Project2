#include "IF.h"


IF::IF()
{
    pc = -1;
    pc_branch = -1;
    PCSel = -1;
    instruction = -1;
    opcode = -1;
    strcpy(out,"NOP");
    funct = -1;
    stall =0;
    isNOP = 0;

    //ctor
}
IF::IF(int pc){
    this->pc = pc;
    this->pc_branch = -1;
    this->PCSel = -1;
    this->instruction = -1;
    this->opcode = -1;
    strcpy(this->out,"NOP");
    this->funct = -1;
    this->stall = 0;
    this->isNOP = 0;
}


IF::~IF()
{
    //dtor
}

void IF::IFdo(FILE* snap,InstruM* ins,Reg* r, IF_ID* if_id)
{
    this->instruction = ins->Ins[this->pc];
    this->opcode = ins->rtopcode(this->pc);
    this->funct = ins->rtfunct(this->pc);


       if(this->opcode == 0x00){
            switch(this->funct){
        case 0x20:
            strcpy(this->out,"ADD");
            break;
        case 0x21:
            strcpy(this->out,"ADDU");
            break;
        case 0x22:
            strcpy(this->out,"SUB");
            break;
        case 0x24:
            strcpy(this->out ,"AND");
            break;
        case 0x25:
            strcpy(this->out ,"OR");
            break;
        case 0x26:
            strcpy(this->out ,"XOR");
            break;
        case 0x27:
            strcpy(this->out , "NOR");
            break;
        case 0x28:
            strcpy(this->out , "NAND");
            break;
        case 0x2A:
            strcpy(this->out , "SLT");
            break;
        case 0x00:
            strcpy(this->out , "SLL");
            break;
        case 0x02:
            strcpy(this->out , "SRL");
            break;
        case 0x03:
            strcpy(this->out , "SRA");
            break;
        case 0x08:
            strcpy(this->out , "JR");
            break;
        default:
                break;
            }
        }else{
            switch(this->opcode){
            case 0x08:{
                strcpy(this->out , "ADDI");
                break;
            }
            case 0x09:
                strcpy(this->out , "ADDIU");
                break;
            case 0x23:
                strcpy(this->out , "LW");
                break;
            case 0x21:
                strcpy(this->out , "LH");
                break;
            case 0x25:
                strcpy(this->out , "LHU");
                break;
            case 0x20:
                strcpy(this->out , "LB");
                break;
            case 0x24:
                strcpy(this->out , "LBU");
                break;
            case 0x2B:
                strcpy(this->out , "SW");
                break;
            case 0x29:
                strcpy(this->out , "SH");
                break;
            case 0x28:
                strcpy(this->out , "SB");
                break;
            case 0x0F:
                strcpy(this->out , "LUI");
                break;
            case 0x0C:
                strcpy(this->out , "ANDI");
                break;
            case 0x0D:
                strcpy(this->out , "ORI");
                break;
            case 0x0E:
                strcpy(this->out , "NORI");
                break;
            case 0x0A:
                strcpy(this->out , "SLTI");
                break;
            case 0x04:
                strcpy(this->out , "BEQ");
                break;
            case 0x05:
                strcpy(this->out , "BNE");
                break;
            case 0x07:
                strcpy(this->out , "BGTZ");
                break;
            case 0x02:
                strcpy(this->out , "J");
                break;
            case 0x03:
                strcpy(this->out , "JAL");
                break;
            case 0x3F:
                strcpy(this->out , "HALT");
    if_id->rs = -1;
    if_id->rt = -1;
    if_id->rd = -1;
                break;
            default:
                break;
            }

        }




        if(this->stall == 1){
             fprintf(snap,"IF: 0x%08X to_be_stalled\n",this->instruction);
        this->stall = 0;
            return;
        }

    if_id->isNOP = this->isNOP;

    if_id->After_IF = ins->Ins[this->pc];
    if_id->pc = this->pc +4;

    if_id->opcode = ins->rtopcode(this->pc);
    if_id->funct = ins->rtfunct(this->pc);
    if_id->rs = ins->rtrs(this->pc);
    if_id->rt = ins->rtrt(this->pc);
    if_id->rd = ins->rtrd(this->pc);
    if_id->shamt = ins->rtshamt(this->pc);

    if_id->immed = ins->rtimmediate(this->pc);
    if_id->unimmed = ins->rtimmediate(this->pc);

    if(if_id->rs > (int)0 || if_id->rs <(int)32){
        if_id->Read_Data1 = r->reg[if_id->rs];
    }else{
        if_id->Read_Data1 = 0;
    }

    if(if_id->rt >(int)0 || if_id->rt <(int)32){
        if_id->Read_Data2 = r->reg[if_id->rt];
    }else{
        if_id->Read_Data2 = 0;
    }



    strcpy(if_id->out , this->out);

    if(this->instruction == 0){
        strcpy(this->out , "NOP");
        strcpy(if_id->out , this->out);
        return ;
    }


    if(this->stall == 1){
        fprintf(snap,"IF: 0x%08X to_be_stalled\n",this->instruction);
        this->stall = 0;
    }else{
    if(this->PCSel == 0){
        this->pc = this->pc + 4;
        fprintf(snap,"IF: 0x%08X\n",this->instruction);
    }else{
        fprintf(snap,"IF: 0x%08X to_be_flushed\n",this->instruction);

        if_id->After_IF = 0;

        if_id->pc = 0;

        if_id->opcode = -1;
        if_id->funct = -1;
        if_id->rs = -1;
        if_id->rt = -1;
        if_id->rd = -1;
        if_id->shamt = -1;

        if_id->immed = 0;
        if_id->unimmed = 0;
        if_id->Read_Data1 = 0;
        if_id->Read_Data2 = 0;
        strcpy(if_id->out , "NOP");

        this->pc = this->pc_branch;
        }
    }


}



