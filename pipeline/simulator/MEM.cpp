#include "MEM.h"
#include<stdio.h>

MEM::MEM()
{
    MemWrite = 0;
    MemRead = 0;
    Writedata = 0;
    Address = 0;;
    Readdata = 0;
    opcode = 0;

    RegWrite = 0;
    MemtoReg = 0;
    RegDst = 0;

    instruction = 0;
    rt = -1;
    rd = -1;
    out = "NOP";
    stall = 0;
    isNOP = 0;
    //ctor
}

MEM::~MEM()
{
    //dtor
}
void MEM::MEMdo(ID_EX* id_ex ,EX* ex,IF_ID* if_id,Memory* mem,EX_MEM* ex_mem, MEM_WB* mem_wb)
{
    this->out = ex_mem->out;
    this->isNOP = ex_mem->isNOP;


    unsigned char a1,a2,a3,a4;
    int temp = 0;

    this->MemRead = ex_mem->MemRead;
    this->MemWrite = ex_mem->MemWrite;
    this->Writedata = ex_mem->Read_Data2;
    this->Address = ex_mem->ALUresult;



    this->RegWrite = ex_mem->RegWrite;
    this->MemtoReg = ex_mem->MemtoReg;
    this->RegDst = ex_mem->RegDst;

    this->instruction = ex_mem->instruction;
    this->rt = ex_mem->rt;
    this->rd = ex_mem->rd;
    this->opcode = ex_mem->opcode;



    if(ex_mem->isNOP != 1){
    if(ex_mem->RegWrite == 1){
        if(ex_mem->RegDst == 1){
            if(if_id->opcode == 0x00){
                switch(if_id->funct){
                case 0x20:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x22:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x26:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x27:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x28:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x2A:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x00:
                    if(if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x02:
                    if(if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x03:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                default:
                    break;
                }
            }else{
                switch(if_id->opcode){
                case 0x08:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x09:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x23:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x20:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x0C:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x0D:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x0E:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x0A:
                    if(if_id->rs == ex_mem->rd){
                        ex->stall = 1;
                    }
                    break;
                case 0x04:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x05:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x07:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd){
                        ex->stall =1;
                    }
                    }
                    break;
                default:
                    break;
                }
            }
        }else{
            if(if_id->opcode == 0x00){
                switch(if_id->funct){
                case 0x20:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x22:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x26:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x27:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x28:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x2A:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x00:
                    if(if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x02:
                    if(if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x03:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                default:
                    break;
                }
            }else{
                switch(if_id->opcode){
                case 0x08:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x09:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x23:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x20:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x0C:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x0D:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x0E:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x0A:
                    if(if_id->rs == ex_mem->rt){
                        ex->stall = 1;
                    }
                    break;
                case 0x04:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x05:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x07:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt){
                        ex->stall =1;
                    }
                    }
                    break;
                default:
                    break;
                }
            }




        }

    }

     if(id_ex->isNOP != 1){
    if(ex_mem->RegWrite == 1 && id_ex->RegWrite==1){
        if(ex_mem->RegDst == 1){
                if(id_ex->RegDst == 1){
                    if(ex_mem->rd == id_ex->rd){
                        ex->stall = 0;
                    }
                }else{
                    if(ex_mem->rd == id_ex->rt){
                        ex->stall = 0;
                    }
                }
        }else{
             if(id_ex->RegDst == 1){
                    if(ex_mem->rt == id_ex->rd){
                        ex->stall = 0;
                    }
                }else{
                    if(ex_mem->rt == id_ex->rt){
                        ex->stall = 0;
                    }
                }
        }
    }
     }
}


    /*
    if(ex->stall == 1){
        printf("this->out = %s\n",this->out);
        printf("this->out rt= %d\n",this->rt);
        printf("if_id: %s\n",if_id->out);
        printf("if_id rs: %d\n",if_id->rs);
        printf("if_id rt: %d\n",if_id->rt);
        printf("if_id immed: 0x%08x\n",if_id->immed);

    }
*/



       mem_wb->isNOP = this->isNOP;
        mem_wb->out = this->out;
        mem_wb->ALUresult = ex_mem->ALUresult;
        mem_wb->MemtoReg = ex_mem->MemtoReg;
        mem_wb->RegWrite = ex_mem->RegWrite;
        mem_wb->RegDst = ex_mem->RegDst;

        mem_wb->instruction = this->instruction;
        mem_wb->rt = ex_mem->rt;
        mem_wb->rd = ex_mem->rd;
        mem_wb->opcode = this->opcode;


    temp = this->Writedata;
    a4 = temp;
    temp = temp >> 8;
    a3 = temp;
    temp = temp >> 8;
    a2 = temp ;
    temp = temp >> 8;
    a1 = temp;


    if(this->instruction == 0){
        return ;
    }


    if(this->MemWrite == 1){
        switch(this->opcode){
        case 0x2B:
            mem->mem[this->Address] = a4;
            mem->mem[this->Address + 1] = a3;
            mem->mem[this->Address + 2] = a2;
            mem->mem[this->Address + 3] = a1;
            break;
        case 0x29:
            mem->mem[this->Address] = a4;
            mem->mem[this->Address+1] = a3;
            break;
        case 0x28:
            mem->mem[this->Address] = a4;
            break;
        default :
            break;
        }
    }

    this->Readdata = 0;
    mem_wb->Readdata = 0;

    temp = 0;

    if(this->MemRead == 1){
        switch(this->opcode){
            case 0x23:
                temp |= mem->mem[this->Address];
                temp = temp <<8;
                temp |= mem->mem[this->Address+1];
                temp = temp <<8;
                temp |= mem->mem[this->Address+2];
                temp = temp <<8;
                temp |= mem->mem[this->Address+3];
                this->Readdata = temp;
                mem_wb->Readdata = temp;
                break;
            case 0x21:
                temp |=  mem->mem[this->Address];
                temp  = temp << 8;
                temp |=  mem->mem[this->Address+1];
                this->Readdata = temp;
                mem_wb->Readdata = temp;
                break;
            case 0x25:
                temp |= (mem->mem[this->Address]);
                temp = temp << 8;
                temp |=  (mem->mem[this->Address+1]);
                this->Readdata = temp;
                mem_wb->Readdata = temp;
                break;
            case 0x20:
                 temp |= mem->mem[this->Address];
                 this->Readdata = temp;
                 mem_wb->Readdata = temp;
                 break;
            case 0x24:
                 temp |= mem->mem[this->Address];
                 this->Readdata = temp;
                 mem_wb->Readdata = temp;
                 break;
            default:
                break;
        }
    }


}
