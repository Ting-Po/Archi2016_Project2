#include "EX.h"
#include<stdio.h>

EX::EX()
{
    //ctor
    RegWrite=-1;
    RegDst=-1;
    ALUSrc=-1;
    MemWrite=-1;
    MemRead=-1;
    MemtoReg=-1;

    instruction = -1;
    Read_Data1=-1;
    Read_Data2=-1;

    signimmed=-1;
    unsignimmed = -1;

    rt=-1;
    rd=-1;

    opcode=0;
    funct=0;
    rs=0;
    shamt=0;
    address=0;
    strcpy(out , "NOP");
    forwarding = 0;
    stall =0;
    ex_memdst = 0;
    fwd_rt = 0;
    fwd_rs = 0;
    isNOP = 0;
}

EX::~EX()
{
    //dtor
}

void EX::Exdo(int* err,IF* ifif,ID* id,IF_ID* if_id,ID_EX* id_ex,EX_MEM* ex_mem)
{


   this->fwd_rs = 0;
   this->fwd_rt = 0;

   this->isNOP = id_ex->isNOP;
    strcpy(this->out , id_ex->out);
    this->ALUSrc = id_ex->ALUSrc;
    this->RegDst = id_ex->RegDst;
    this->RegWrite = id_ex->RegWrite;
    this->MemWrite = id_ex->MemWrite;
    this->MemRead = id_ex->MemRead;
    this->MemtoReg = id_ex->MemtoReg;
    this->RegDst = id_ex->RegDst;

    this->instruction = id_ex->instruction;
    this->Read_Data1 = id_ex->Read_Data1;
    this->Read_Data2 = id_ex->Read_Data2;

    this->signimmed = id_ex->signimmed;
    this->unsignimmed = id_ex->unsignimmed;

    this->rt = id_ex->rt;
    this->rd = id_ex->rd;

    this->opcode = id_ex->opcode;
    this->funct = id_ex->funct;
    this->rs = id_ex->rs;
    this->shamt = id_ex->shamt;
    this->address = id_ex->address;
    this->forwarding = 0;
    if_id->forwarding = 0;


if(this->isNOP != 1){
    if(this->RegWrite == 1){
        if(this->RegDst == 1){
             if(if_id->opcode == 0x00){
                if(this->opcode == 0x23|| this->opcode == 0x21 || this->opcode == 0x25 || this->opcode == 0x20 || this->opcode == 0x24){
                    switch(if_id->funct){
                    case 0x20:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x21:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x22:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x24:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x25:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x26:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x27:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x28:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x2A:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x00:
                        if(if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x02:
                        if(if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x03:
                        if(if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    default :
                        break;
                    }
                }
             }else{
                 if(this->opcode == 0x23|| this->opcode == 0x21 || this->opcode == 0x25 || this->opcode == 0x20 || this->opcode == 0x24){
                    switch(if_id->opcode){
                    case 0x08:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x09:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x23:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x21:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x25:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x20:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x24:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x2B:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        if(if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x29:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        if(if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x28:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        if(if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0C:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0D:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0E:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0A:
                        if(if_id->rs == this->rd){
                            if(this->rd!=0)
                            this->stall = 1;
                        }
                        break;
                    default:
                        break;
                    }
                 }

                switch(if_id->opcode){
                    case 0x04:
                        if(if_id->rs == this->rd || if_id->rt == this->rd ){
                            if(this->rd!=0)
                            this->stall =1;
                        }
                        break;
                    case 0x05:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall =1;
                        }
                        break;
                    case 0x07:
                        if(if_id->rs == this->rd || if_id->rt == this->rd){
                            if(this->rd!=0)
                            this->stall =1;
                        }
                        break;
                    default:
                        break;
                }
             }
        }else{
                 if(if_id->opcode == 0x00){
                if(this->opcode == 0x23|| this->opcode == 0x21 || this->opcode == 0x25 || this->opcode == 0x20 || this->opcode == 0x24){
                    switch(if_id->funct){
                    case 0x20:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x21:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x22:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x24:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x25:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x26:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x27:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x28:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x2A:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x00:
                        if(if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x02:
                        if(if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x03:
                        if(if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    default :
                        break;
                    }
                }
        }else{
                if(this->opcode == 0x23|| this->opcode == 0x21 || this->opcode == 0x25 || this->opcode == 0x20 || this->opcode == 0x24){
                    switch(if_id->opcode){
                    case 0x08:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x09:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x23:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x21:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x25:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x20:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x24:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x2B:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        if(if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x29:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        if(if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x28:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        if(if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0C:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0D:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0E:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    case 0x0A:
                        if(if_id->rs == this->rt){
                            if(this->rt!=0)
                            this->stall = 1;
                        }
                        break;
                    default:
                        break;
                    }
                 }


                switch(if_id->opcode){
                    case 0x04:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall =1;
                        }
                        break;
                    case 0x05:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall =1;
                        }
                        break;
                    case 0x07:
                        if(if_id->rs == this->rt || if_id->rt == this->rt){
                            if(this->rt!=0)
                            this->stall =1;
                        }
                        break;
                    default:
                        break;
                }
        }
            }
    }

}

        if(ex_mem->RegDst == 1){
            ex_memdst = ex_mem->rd;
        }else{
            ex_memdst = ex_mem->rt;
        }

    if(ex_mem->isNOP!=1){
    if(ex_mem->RegWrite == 1){
        if(this->opcode == 0x00){
            switch(this->funct){
            case 0x20:
                 if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x21:
                 if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x22:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x24:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x25:
                 if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x26:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x27:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x28:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x2A:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x00:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                break;
            case 0x02:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                break;
            case 0x03:
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                break;
            default:
                break;
            }
        }else{
            switch(this->opcode){
            case 0x08:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x09:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;

            case 0x23:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x21:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x25:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x20:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x24:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x2B:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                break;
            case 0x29:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                break;
            case 0x28:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                if(ex_memdst == this->rt && ex_memdst!=0){
                    this->Read_Data2 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rt = 1;
                }
                break;
            case 0x0C:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x0D:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x0E:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            case 0x0A:
                if(ex_memdst == this->rs && ex_memdst!=0){
                    this->Read_Data1 = ex_mem->ALUresult;
                    this->forwarding = 1;
                    this->fwd_rs = 1;
                }
                break;
            /*
            case 0x04:
                printf("if_id:eeeeeeeeeeee%s\n",if_id->out);
                if(ex_memdst == if_id->rt && ex_memdst!=0){
                        printf("if_id: %s\n",if_id->out);
                    if_id->Read_Data2 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    this->fwd_rsrt = 0;
                }
                if(ex_memdst == if_id->rs && ex_memdst!=0){
                    printf("if_id: %s\n",if_id->out);
                    if_id->Read_Data1 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    this->fwd_rsrt = 1;
                }

                break;
            case 0x05:
                if(ex_memdst == if_id->rt && ex_memdst!=0){
                    if_id->Read_Data2 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    this->fwd_rsrt = 0;
                }
                if(ex_memdst == if_id->rs && ex_memdst!=0){
                    if_id->Read_Data1 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    this->fwd_rsrt = 1;
                }

                break;
            case 0x07:
                if(ex_memdst == if_id->rt && ex_memdst!=0){
                    if_id->Read_Data2 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    this->fwd_rsrt = 0;
                }
                if(ex_memdst == if_id->rs && ex_memdst!=0){
                    if_id->Read_Data1 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    this->fwd_rsrt = 1;
                }

                break;
              */
            default :
                break;
            }

        }
            if(this->opcode != 0x23 && this->opcode != 0x21 && this->opcode != 0x25 && this->opcode != 0x20 && this->opcode != 0x24){
            switch(if_id->opcode){
             case 0x04:
                if(ex_memdst == if_id->rt && ex_memdst!=0){
                    if_id->Read_Data2 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    id->fwdrt = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == if_id->rs && ex_memdst!=0){
                    if_id->Read_Data1 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    id->fwdrs = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x05:
                if(ex_memdst == if_id->rt && ex_memdst!=0){
                    if_id->Read_Data2 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    id->fwdrt = 1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == if_id->rs && ex_memdst!=0){
                    if_id->Read_Data1 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    id->fwdrs = 1;
                    this->fwd_rs = 1;
                }

                break;
            case 0x07:
                if(ex_memdst == if_id->rt && ex_memdst!=0){
                    if_id->Read_Data2 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    id->fwdrt =  1;
                    this->fwd_rt = 1;
                }
                if(ex_memdst == if_id->rs && ex_memdst!=0){
                    if_id->Read_Data1 = ex_mem->ALUresult;
                    if_id->forwarding = 1;
                    id->fwdrs = 1;
                    this->fwd_rs = 1;
                }
                break;
            default:
                break;


            }
        }
    }
}

      if(this->isNOP == 1){
        this->forwarding = 0;
      }


      ex_mem->RegWrite = this->RegWrite;
      ex_mem->MemWrite = this->MemWrite;
      ex_mem->MemRead = this->MemRead;
      ex_mem->MemtoReg = this->MemtoReg;
      ex_mem->RegDst = this->RegDst;
       strcpy(ex_mem->out , this->out);
      ex_mem->instruction = this->instruction;
      ex_mem->Read_Data2 = this->Read_Data2;
      ex_mem->rt = this->rt;
      ex_mem->rd = this->rd;
      ex_mem->opcode = this->opcode;
      ex_mem->isNOP = this->isNOP;



     unsigned char rssign = (unsigned int)this->Read_Data1>>31;
     unsigned char rtsign=0;
     int num  = 0;
    unsigned char rdsign = 0;
    int rttrans = 0;
    unsigned char immedsign = 0;


      if(this->opcode == 0x00){
            switch(this->funct){
        case 0x20:
            num = Read_Data1 + Read_Data2;
            rtsign = (unsigned int)this->Read_Data2>>31;
            rdsign = (unsigned int)num>>31;
            if( (rssign==0) & (rtsign == 0 )){
                if(rdsign==1){
                err[1] = 1;
                }
            }
            if( (rssign==1) & (rtsign ==1 )){
                if(rdsign==0){
                err[1] = 1;
                }
            }
            ex_mem->ALUresult = Read_Data1 + Read_Data2;
            break;
        case 0x21:
            ex_mem->ALUresult = Read_Data1 + Read_Data2;
            break;
        case 0x22:
            rttrans = ~(Read_Data2)+1;
            rtsign = (unsigned int)rttrans>>31;
            num = Read_Data1 + rttrans;
            rdsign = (unsigned int)num>>31;
            if( (rssign==0) & (rtsign == 0 )){
                if(rdsign==1){
                    err[1] = 1;
                }
            }
            if( (rssign==1) & (rtsign ==1 )){
                if(rdsign==0){
                    err[1] = 1;
                }
            }

            ex_mem->ALUresult = Read_Data1 - Read_Data2;
            break;
        case 0x24:
            ex_mem->ALUresult = Read_Data1 & Read_Data2;
            break;
        case 0x25:
            ex_mem->ALUresult = Read_Data1 | Read_Data2;
            break;
        case 0x26:
            ex_mem->ALUresult = Read_Data1 ^ Read_Data2;
            break;
        case 0x27:
            ex_mem->ALUresult = ~(Read_Data1|Read_Data2);
            break;
        case 0x28:
            ex_mem->ALUresult = ~(Read_Data1&Read_Data2);
            break;
        case 0x2A:
            ex_mem->ALUresult = Read_Data1 < Read_Data2;
            break;
        case 0x00:
            ex_mem->ALUresult = Read_Data2 << shamt;
            break;
        case 0x02:
            ex_mem->ALUresult = (unsigned int)Read_Data2 >> shamt;
            break;
        case 0x03:
            ex_mem->ALUresult = Read_Data2 >> shamt;
            break;
        default:
            ex_mem->ALUresult = 0;
            break;
            }
        }else{
            switch(this->opcode){
            case 0x08:{
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                    if(rtsign == 1){
                        err[1] = 1;
                    }
                }
                if( (rssign == 1) & (immedsign == 1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }

                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            }
            case 0x09:
                ex_mem->ALUresult = Read_Data1 +signimmed;
                break;
            case 0x23:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                    if(rtsign==1){
                        err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign == 1)){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }

                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            case 0x21:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            case 0x25:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult = Read_Data1 +signimmed;
                break;
            case 0x20:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            case 0x24:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult =  Read_Data1 + signimmed;
                break;
            case 0x2B:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            case 0x29:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            case 0x28:
                immedsign = (unsigned int)signimmed>>31;
                num = Read_Data1 + signimmed;
                rtsign = (unsigned int)num>>31;
                if( (rssign==0) & (immedsign==0 )){
                        if(rtsign==1){
                            err[1] = 1;
                    }
                }
                if( (rssign==1) & (immedsign==1 )){
                    if(rtsign==0){
                        err[1] = 1;
                    }
                }
                ex_mem->ALUresult = Read_Data1 + signimmed;
                break;
            case 0x0F:
                ex_mem->ALUresult = signimmed<<16;
                break;
            case 0x0C:
                ex_mem->ALUresult = Read_Data1 & unsignimmed;
                break;
            case 0x0D:
                ex_mem->ALUresult = Read_Data1 | unsignimmed;
                break;
            case 0x0E:
                ex_mem->ALUresult = ~(Read_Data1|unsignimmed);
                break;
            case 0x0A:
                ex_mem->ALUresult =  Read_Data1<signimmed;
                break;
            default:
                ex_mem->ALUresult = 0;
                break;
            }

        }

        ifif->stall = 0;
        id->stall = 0;
        id_ex->isNOP = 0;

        if(this->stall == 1){
        ifif->stall = 1;
        id->stall = 1;
        strcpy(id_ex->out , "NOP");
        id_ex->isNOP = 1;

        /*
        id_ex->ALUSrc = -1;
        id_ex->RegDst = -1;
        id_ex->RegWrite = -1;
        id_ex->MemWrite = -1;
        id_ex->MemRead = -1;
        id_ex->MemtoReg = -1;
        id_ex->RegDst = -1;

        id_ex->instruction = 0;
        id_ex->Read_Data1 = -1;
        id_ex->Read_Data2 = -1;

        id_ex->signimmed =-1;
        id_ex->unsignimmed = -1;

        id_ex->rt = -1;
        id_ex->rd = -1;

       id_ex->opcode = -1;
        id_ex->funct = -1;
    id_ex->rs = -1;
    id_ex->shamt = -1;
    id_ex->address = -1;
    */

    this->stall = 0;
    }


}
