#include "WB.h"

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
     out = "NOP";
}

WB::~WB()
{
    //dtor
}

void WB::WBdo(MEM_WB* mem_wb, Reg* r)
{
    this->out = mem_wb->out;

     this->opcode = mem_wb->opcode;
     this->Readdata = mem_wb->Readdata;
     this->ALUresult = mem_wb->ALUresult;
     this->MemtoReg = mem_wb->MemtoReg;
     this->RegWrite = mem_wb->RegWrite;
     this->RegDst = mem_wb->RegDst;

     this->instruction = mem_wb->instruction;
     this->rt = mem_wb->rt;
     this->rd = mem_wb->rd;


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

     if(this->instruction == 0){
        return;
     }


     if(this->RegWrite == 1){
        r->reg[destination] = WriteData;
     }



}
