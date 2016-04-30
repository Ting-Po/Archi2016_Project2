#include "ID.h"
#include<stdio.h>

ID::ID()
{
    //ctor
    pc = -1;
    opcode = -1;
    instruction = -1;
    forwarding = 0;
    out = "NOP";
    Read_Data1=-1;
    Read_Data2=-1;
    immed=-1;
    unimmed=-1;
    rt=-1;
    rd=-1;

    funct=-1;
    rs=-1;
    shamt=-1;
    address=-1;
    stall = 0;
}

ID::~ID()
{
    //dtor
}

void ID::IDdo(IF_ID* if_id,ID_EX* id_ex,IF* ifif,Reg* r)
{

    this->out = if_id->out;
    this->forwarding = if_id->forwarding;
    this->instruction = if_id->After_IF;
    this->opcode = if_id->opcode;
    this->pc = if_id->pc;
    this->Read_Data1 = if_id->Read_Data1;
    this->Read_Data2 = if_id->Read_Data2;
    this->immed = if_id->immed;
    this->unimmed = if_id->unimmed;
    this->rt = if_id->rt;
    this->rd = if_id->rd;

    this->funct = if_id->funct;
    this->rs = if_id->rs;
    this->shamt = if_id->shamt;
    this->address = if_id->address;

    this->Read_Data1 = r->reg[this->rs];
    this->Read_Data2 = r->reg[this->rt];

    if(this->stall == 1){
        return;
    }

    id_ex->out = this->out;
    id_ex->instruction = this->instruction;
    id_ex->rt = this->rt;
    id_ex->rd = this->rd;
    id_ex->Read_Data1 = this->Read_Data1;
    id_ex->Read_Data2 = this->Read_Data2;

    id_ex->opcode = this->opcode;
    id_ex->funct = this->funct;
    id_ex->rs = this->rs;
    id_ex->shamt = this->shamt;
    id_ex->address = this->address;

    id_ex->signimmed = this->immed;
    id_ex->unsignimmed = this->unimmed;

     unsigned short immed1=0;
     int temp1=0;
     unsigned int temppc1=0;
     int ans1=0;
     unsigned short immed = 0;
     int temp=0;
     unsigned int temppc=0;
     int ans=0;
/*
    if(this->instruction == 0){
        return ;
    }
*/

    switch(if_id->opcode){
    case 0x00:
        id_ex->RegDst = 1;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x08:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x09:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x023:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 1;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 1;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x21:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 1;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 1;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x25:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 1;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 1;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x20:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 1;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 1;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x24:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 1;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 1;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    case 0x2B:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 1;
        id_ex->Branch = 0;
        break;
    case 0x29:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 1;
        id_ex->Branch = 0;
        break;
    case 0x28:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 1;
        id_ex->Branch = 0;
        break;
    case 0x0F:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
     case 0x0C:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
     case 0x0D:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
     case 0x0E:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
     case 0x0A:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 1;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 1;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
     case 0x04:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        ifif->pc_branch = this->pc + 4* if_id->immed;
        if(if_id->Read_Data1 == if_id->Read_Data2)
            ifif->PCSel = 1;
        else
            ifif->PCSel = 0;
        break;
    case 0x05:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        ifif->pc_branch = this->pc + 4* if_id->immed;
        if(if_id->Read_Data1!=if_id->Read_Data2)
            ifif->PCSel = 1;
        else
            ifif->PCSel = 0;
        break;
    case 0x07:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        ifif->pc_branch = this->pc+4*if_id->immed;
        if(if_id->Read_Data1>0)
            ifif->PCSel = 1;
        else
            ifif->PCSel = 0;
        break;
    case 0x02:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        immed1 = if_id->immed;
        temp1 = immed1<<2;
        temppc1 = this->pc;
        temppc1 = temppc1>>24;
        temppc1 = temppc1 <<24;

        ans1 = temppc1|temp1;

        ifif->pc_branch = ans1;
        ifif->PCSel = 1;
        break;
    case 0x03:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        immed = if_id->immed;
        temp = immed<<2;
        temppc = this->pc;
        temppc = temppc>>24;
        temppc = temppc <<24;

        ans = temppc|temp;
        r->reg[31] = this->pc;

        ifif->pc_branch = ans;
        ifif->PCSel = 1;
        break;
    case 0x3F:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    default:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 0;
        break;
    }
    if(id_ex->Branch == 0){
        ifif->PCSel = 0;
    }


    if(if_id->opcode == 0x00 && if_id->funct==0x08){
        id_ex->RegDst = 0;
        id_ex->RegWrite = 0;
        ifif->pc_branch = id_ex->Read_Data1;
        ifif->PCSel = 1;
    }




}
