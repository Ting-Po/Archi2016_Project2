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
    strcpy(out , "NOP");
    stall = 0;
    isNOP = 0;
    //ctor
}

MEM::~MEM()
{
    //dtor
}
void MEM::MEMdo(int* err,ID_EX* id_ex ,EX* ex,IF_ID* if_id,Memory* mem,EX_MEM* ex_mem, MEM_WB* mem_wb)
{
    strcpy(this->out , ex_mem->out);
    this->isNOP = ex_mem->isNOP;


    unsigned char a1,a2,a3,a4;
    int temp = 0;
    short stemp = 0;
    char ctemp = 0;
    unsigned uctemp = 0;

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
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x22:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x26:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x27:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x28:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x2A:
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x00:
                    if(if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x02:
                    if(if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x03:
                    if(if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x08:
                     if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                     }
                    break;
                default:
                    break;
                }
            }else{
                switch(if_id->opcode){
                case 0x08:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x09:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x23:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x20:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x2B:
                    if(if_id->rs == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    if(if_id->rt == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x29:
                    if(if_id->rs == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    if(if_id->rt == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x28:
                    if(if_id->rs == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    if(if_id->rt == ex_mem->rd){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0C:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0D:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0E:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0A:
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x04:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x05:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd || if_id->rt == ex_mem->rd){
                        if(ex_mem->rd!=0)
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x07:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rd){
                        if(ex_mem->rd!=0)
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
                        if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x22:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x26:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x27:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x28:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x2A:
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x00:
                    if(if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x02:
                    if(if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x03:
                    if(if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x08:
                     if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt){
                        if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                     }
                    break;
                default:
                    break;
                }
            }else{
                switch(if_id->opcode){
                case 0x08:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x09:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x23:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x21:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x25:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x20:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x24:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x2B:
                    if(if_id->rs == ex_mem->rt){
                       if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    if(if_id->rt == ex_mem->rt){
                       if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x29:
                    if(if_id->rs == ex_mem->rt){
                       if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    if(if_id->rt == ex_mem->rt){
                       if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x28:
                    if(if_id->rs == ex_mem->rt){
                       if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    if(if_id->rt == ex_mem->rt){
                       if(ex_mem->rd!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0C:
                    if(if_id->rs == ex_mem->rt){
                        if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0D:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0E:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x0A:
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall = 1;
                    }
                    break;
                case 0x04:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x05:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt || if_id->rt == ex_mem->rt){
                         if(ex_mem->rt!=0)
                        ex->stall =1;
                    }
                    }
                    break;
                case 0x07:
                    if(ex_mem->opcode==0x23 ||ex_mem->opcode==0x21 ||ex_mem->opcode==0x25 ||ex_mem->opcode==0x20 ||ex_mem->opcode==0x24){
                    if(if_id->rs == ex_mem->rt){
                         if(ex_mem->rt!=0)
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





       mem_wb->isNOP = this->isNOP;
        strcpy(mem_wb->out , this->out);

        mem_wb->ALUresult = ex_mem->ALUresult;
        mem_wb->MemtoReg = ex_mem->MemtoReg;
        mem_wb->RegWrite = ex_mem->RegWrite;
        mem_wb->RegDst = ex_mem->RegDst;

        mem_wb->instruction = this->instruction;
        mem_wb->rt = ex_mem->rt;
        mem_wb->rd = ex_mem->rd;
        mem_wb->opcode = this->opcode;


    temp = this->Writedata;
    a4 = 0;
    a3 = 0;
    a2 = 0;
    a1 = 0;


    if(this->instruction == 0){
        return ;
    }

    if(this->isNOP!=1){
    if(this->MemWrite == 1){
        switch(this->opcode){
        case 0x2B:
            if( this->Address >=1024){
                err[2] = 1;
            }
            if( (this->Address)+1 >=1024){
                err[2] = 1;
            }
            if( (this->Address)+2 >=1024){
                err[2] = 1;
            }
            if( (this->Address)+3 >=1024){
            err[2] = 1;
            }
            if( this->Address <0){
                err[2] = 1;
            }

            if( ((this->Address)%4)!=0){
            err[3] = 1;
            }

            if(err[2]|err[3]){

            }else{
                a4 = temp;
                temp = temp >> 8;
                a3 = temp;
                temp = temp >> 8;
                a2 = temp ;
                temp = temp >> 8;
                a1 = temp;
            mem->mem[this->Address] = a1;
            mem->mem[this->Address + 1] = a2;
            mem->mem[this->Address + 2] = a3;
            mem->mem[this->Address + 3] = a4;
            }

            break;
        case 0x29:
            if((this->Address) >=1024){
                err[2] = 1;
            }
            if((this->Address)+1 >=1024){
                err[2] = 1;
            }
            if((this->Address)<0){
                err[2] = 1;
            }
            if( ((this->Address)%2)!=0){
                err[3] = 1;
            }
            if(err[2]|err[3]){

            }else{
            a2 = temp;
            temp = temp >> 8;
            a1 = temp;
            mem->mem[this->Address] = a1;
            mem->mem[this->Address+1] = a2;
            }
            break;
        case 0x28:
            if((this->Address) >=1024){
                err[2] = 1;
            }
            if((this->Address)<0){
                err[2] = 1;
            }
            if(err[2]|err[3]){

            }else{
            a1 = temp;
            mem->mem[this->Address] = a1;
            }
            break;
        default :
            break;
        }
    }
    }
    this->Readdata = 0;
    mem_wb->Readdata = 0;

    temp = 0;

    if(this->isNOP!=1){
    if(this->MemRead == 1){
        switch(this->opcode){
            case 0x23:
                if((this->Address) >=1024){
                    err[2] = 1;
                }
                if((this->Address)+1 >=1024){
                    err[2] = 1;
                }
                if((this->Address)+2 >=1024){
                    err[2] = 1;
                }
                if((this->Address)+3 >=1024){
                    err[2] = 1;
                }
                if((this->Address)<0){
                    err[2] = 1;
                }

                if(((this->Address)%4)!=0){
                    err[3] = 1;
                }

                if(err[2] |err[3]){

            }else{
                temp = 0;
                temp |= mem->mem[this->Address];
                temp = temp <<8;
                temp |= mem->mem[this->Address+1];
                temp = temp <<8;
                temp |= mem->mem[this->Address+2];
                temp = temp <<8;
                temp |= mem->mem[this->Address+3];
                this->Readdata = temp;
                mem_wb->Readdata = temp;
            }
                break;
            case 0x21:
                 if((this->Address) >=1024){
                    err[2] = 1;
                }
                if((this->Address)+1 >=1024){
                    err[2] = 1;
                }
                if((this->Address)<0){
                    err[2] = 1;
                }
                if(((this->Address)%2)!=0){
                    err[3] = 1;
                }



                if(err[2] |err[3]){

                }else{
                stemp = 0;
                stemp |=  mem->mem[this->Address];
                stemp  = stemp << 8;
                stemp |=  mem->mem[this->Address+1];
                this->Readdata = stemp;
                mem_wb->Readdata = stemp;
        }
                break;
            case 0x25:
                if(this->Address >=1024){
                    err[2] = 1;
                }
                if((this->Address)+1 >=1024){
                    err[2] = 1;
                }
                if((this->Address)<0){
                    err[2] = 1;
                }

                if(((this->Address)%2)!=0){
                    err[3] = 1;
                }



            if(err[2] |err[3]){

            }else{
                temp = 0;
                temp |= (mem->mem[this->Address]);
                temp = temp << 8;
                temp |=  (mem->mem[this->Address+1]);
                this->Readdata = temp;
                mem_wb->Readdata = temp;
            }
                break;
            case 0x20:
                if((this->Address) >=1024){
                    err[2] = 1;
                }
                if((this->Address)<0){
                    err[2] = 1;
                }

            if(err[2]){

            }else{
                 ctemp = 0;
                 ctemp |= mem->mem[this->Address];
                 this->Readdata = ctemp;
                 mem_wb->Readdata = ctemp;
            }
                 break;
            case 0x24:
                if( this->Address >=1024){
                    err[2] = 1;
                }
                if( this->Address<0){
                    err[2] = 1;
                }

            if(err[2]){

            }else{
                 uctemp = 0;
                 uctemp |= mem->mem[this->Address];
                 this->Readdata = uctemp;
                 mem_wb->Readdata = uctemp;
            }
                 break;
            default:
                break;
        }
    }
    }

}
