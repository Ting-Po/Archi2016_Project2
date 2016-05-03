#include "WB.h"
#include<stdio.h>

WB::WB()
{
    //ctor
     Readdata = 0;
     ALUresult = 0;
     MemtoReg = 0;
     RegWrite = 0;
     RegDst = 0;
     opcode = 0;

     instruction = 0;
     rt = -1;
     rd = -1;
     strcpy(out , "NOP");
     isNOP = 0;
}

WB::~WB()
{
    //dtor
}

void WB::WBdo(int* err,MEM_WB* mem_wb, Reg* r)
{
    this->isNOP = mem_wb->isNOP;
    strcpy(this->out , mem_wb->out);

     this->opcode = mem_wb->opcode;
     this->Readdata = mem_wb->Readdata;
     this->ALUresult = mem_wb->ALUresult;
     this->MemtoReg = mem_wb->MemtoReg;
     this->RegWrite = mem_wb->RegWrite;
     this->RegDst = mem_wb->RegDst;

     this->instruction = mem_wb->instruction;
     this->rt = mem_wb->rt;
     this->rd = mem_wb->rd;

    if(isNOP == 1){
        return;
    }

     char destination = 0;
     int WriteData = 0;

    if(this->RegDst == 0){
        destination = this->rt;
     }else{
        destination = this->rd;
     }

     if(this->MemtoReg == 0){
        WriteData = this->ALUresult;
     }else{
        WriteData = this->Readdata;
     }


     int nop = this->instruction<<11;

     if(this->opcode == 0 && nop == 0){
        return;
     }


     if(this->opcode!=0x03){
     if(this->RegWrite == 1){
        if(destination == 0){
            err[0] = 1;
            return;
        }

        r->reg[destination] = WriteData;


     }
     }else{
        r->reg[31] = mem_wb->ALUresult;

     }


}
