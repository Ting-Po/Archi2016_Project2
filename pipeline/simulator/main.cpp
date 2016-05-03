#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "InstruM.h"
#include "Memory.h"
#include "Reg.h"
#include "Function.h"
#include "IF_ID.h"
#include "IF.h"
#include "ID.h"
#include "ID_EX.h"
#include "EX.h"
#include "EX_MEM.h"
#include "MEM.h"
#include "MEM_WB.h"
#include "WB.h"
#include<cstring>


using namespace std;



int main()
{

    int PC=0;
    int InstruNum = 0;
    int SP=0;
    int MemNum = 0;
    int cycle = 0;
    int i;
    int* err;
    int error_message[4] = {0,0,0,0};
    err = error_message;


    FILE* pFile;
    FILE* dFile;
    FILE* snap;
    FILE* error;
  //unsigned char* buffer;
    size_t result;
    InstruM* m = new InstruM();
    Memory* n = new Memory();

  pFile = fopen ( "iimage.bin" , "rb" );
  dFile = fopen ( "dimage.bin" , "rb" );
  snap = fopen("snapshot.rpt" , "w");
  error = fopen("error_dump.rpt", "w");


  // obtain file size:



  result = fread (m->pc_instrunum,sizeof(unsigned char),8,pFile);
  fread (n->sp_memnum,sizeof(unsigned char),8,dFile);

  PC |= m->pc_instrunum[0];
  PC <<= 8;
  PC |= m->pc_instrunum[1];
  PC <<= 8;
  PC |= m->pc_instrunum[2];
  PC <<= 8;
  PC |= m->pc_instrunum[3];

  InstruNum |= m->pc_instrunum[4];
  InstruNum <<= 8;
  InstruNum |= m->pc_instrunum[5];
  InstruNum <<= 8;
  InstruNum |= m->pc_instrunum[6];
  InstruNum <<= 8;
  InstruNum |= m->pc_instrunum[7];

  SP |= n->sp_memnum[0];
  SP <<= 8;
  SP |= n->sp_memnum[1];
  SP <<= 8;
  SP |= n->sp_memnum[2];
  SP <<= 8;
  SP |= n->sp_memnum[3];

  MemNum |= n->sp_memnum[4];
  MemNum <<= 8;
  MemNum |= n->sp_memnum[5];
  MemNum <<= 8;
  MemNum |= n->sp_memnum[6];
  MemNum <<= 8;
  MemNum |= n->sp_memnum[7];

  fread (&(m->InM)[PC],sizeof(unsigned char),InstruNum*4,pFile);
  fread (n->mem,sizeof(unsigned char),MemNum*4,dFile);



  m->storetoIns(PC);






  fclose(pFile);
  fclose(dFile);







Reg* reg = new Reg();
Function* func = new Function();



reg->reg[29] = SP;





//-------------------------------------Project2

IF* ifif = new IF(PC);
IF_ID* if_id = new IF_ID();
ID* id = new ID();
ID_EX* id_ex = new ID_EX();
EX* ex = new EX();
EX_MEM* ex_mem = new EX_MEM();
MEM* mem = new MEM();
MEM_WB* mem_wb = new MEM_WB();
WB* wb = new WB();




    while(1){
        if(ifif->opcode==0x3f && id->opcode == 0x3f && ex->opcode == 0x3f && mem->opcode == 0x3f && wb->opcode == 0x3f){
            break;
        }






        fprintf(snap,"cycle %d\n",cycle);

        for(i=0;i<32;i++){
            fprintf(snap, "$%02d: 0x%08X\n", i, reg->reg[i]);
        }
        fprintf(snap,"PC: 0x%08X\n",ifif->pc);


        if(err[0] == 1){
            fprintf(error, "In cycle %d: Write $0 Error\n",cycle);
        }
        if(err[2] == 1){
            fprintf(error, "In cycle %d: Address Overflow\n",cycle);
        }
        if(err[3] == 1){
            fprintf(error, "In cycle %d: Misalignment Error\n",cycle);
        }
        if(err[1] == 1){
            fprintf(error, "In cycle %d: Number Overflow\n",cycle);
        }

        err[0] = 0;
        err[1] = 0;
        err[2] = 0;
        err[3] = 0;





        wb->WBdo(err,mem_wb,reg);
        mem->MEMdo(err,id_ex,ex,if_id,n,ex_mem,mem_wb);
        ex->Exdo(err,ifif,id,if_id,id_ex,ex_mem);
        id->IDdo(if_id,id_ex,ifif,reg);
        ifif->IFdo(snap,m,reg,if_id);\




        if(id->stall == 1){
            fprintf(snap,"ID: %s to_be_stalled\n", id->out);
            id->stall = 0;
        }else{
        if(id->forwarding == 1){
            if(ex->fwd_rs == 1 && ex->fwd_rt == 1){
            fprintf(snap,"ID: %s fwd_EX-DM_rs_$%d fwd_EX-DM_rt_$%d\n", id->out,ex->ex_memdst,ex->ex_memdst);
            }else if(ex->fwd_rs == 1){
            fprintf(snap,"ID: %s fwd_EX-DM_rs_$%d\n", id->out,ex->ex_memdst);
            }
            else if(ex->fwd_rt == 1){
            fprintf(snap,"ID: %s fwd_EX-DM_rt_$%d\n", id->out,ex->ex_memdst);
            }
            id->forwarding = 0;
        }else{
        fprintf(snap,"ID: %s\n", id->out);
            }
        }
        if(ex->forwarding == 1){
            if(ex->fwd_rs == 1 && ex->fwd_rt == 1){
            fprintf(snap,"EX: %s fwd_EX-DM_rs_$%d fwd_EX-DM_rt_$%d\n", ex->out,ex->ex_memdst,ex->ex_memdst);
            }else if(ex->fwd_rs == 1){
            fprintf(snap,"EX: %s fwd_EX-DM_rs_$%d\n", ex->out,ex->ex_memdst);
            }else if(ex->fwd_rt == 1){
            fprintf(snap,"EX: %s fwd_EX-DM_rt_$%d\n", ex->out,ex->ex_memdst);
            }
        ex->forwarding = 0;
        }else{
        fprintf(snap,"EX: %s\n", ex->out);
        }
        fprintf(snap,"DM: %s\n", mem->out);
        fprintf(snap,"WB: %s\n\n\n", wb->out);
        cycle++;


          ex->fwd_rs = 0;
        ex->fwd_rt = 0;

        if(err[2]|err[3]){
            break;
        }





    }

     if(err[2]|err[3]){

        if(err[0] == 1){
            fprintf(error, "In cycle %d: Write $0 Error\n",cycle);
        }
        if(err[2] == 1){
            fprintf(error, "In cycle %d: Address Overflow\n",cycle);
        }
        if(err[3] == 1){
            fprintf(error, "In cycle %d: Misalignment Error\n",cycle);
        }
        if(err[1] == 1){
            fprintf(error, "In cycle %d: Number Overflow\n",cycle);
        }
    }else{
      if(err[0] == 1){
            fprintf(error, "In cycle %d: Write $0 Error\n",cycle);
        }
        if(err[1] == 1){
            fprintf(error, "In cycle %d: Number Overflow\n",cycle);
        }
    }



/*
   while((m->rtopcode(PC))!= 0x3F){


        fprintf(snap, "cycle %d\n",cycle);
        for(i=0;i<32;i++){
            fprintf(snap, "$%02d: 0x%08X\n", i, reg->reg[i]);
        }
        fprintf(snap,"PC: 0x%08X\n\n\n", PC);
        if(err[0] == 1){
            fprintf(error, "In cycle %d: Write $0 Error\n",cycle);
        }
        if(err[1] == 1){
            fprintf(error, "In cycle %d: Number Overflow\n",cycle);
        }
        if(err[2] == 1){
            fprintf(error, "In cycle %d: Address Overflow\n",cycle);
        }
        if(err[3] == 1){
            fprintf(error, "In cycle %d: Misalignment Error\n",cycle);
        }
        cycle++;


           err[0] = 0;
        err[1] = 0;
        err[2] = 0;
        err[3] = 0;




        if(m->rtopcode(PC) == 0x00){
            switch(m->rtfunct(PC)){
        case 0x20:
            func->add(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x21:
            func->addu(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x22:
            func->sub(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x24:
            func->And(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x25:
            func->Or(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x26:
            func->Xor(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x27:
            func->nor(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x28:
            func->nand(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x2A:
            func->slt(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x00:
            func->sll(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x02:
            func->srl(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x03:
            func->sra(m,PC,reg,err);
            PC = PC + 4;
            break;
        case 0x08:
            PC = reg->reg[m->rtrs(PC)];
            break;
        default:
                PC = PC + 4;
                break;
            }
        }else{
            switch(m->rtopcode(PC)){
            case 0x08:{
                func->addi(m,PC,reg,err);
                PC = PC + 4;
                break;
            }
            case 0x09:
                func->addiu(m,PC,reg,err);
                PC = PC + 4;
                break;
            case 0x23:
                func->lw(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x21:
                func->lh(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x25:
                func->lhu(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x20:
                func->lb(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x24:
                func->lbu(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x2B:
                func->sw(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x29:
                func->sh(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x28:
                func->sb(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x0F:
                func->lui(m,PC,reg,n,err);
                PC = PC + 4;
                break;
            case 0x0C:
                func->andi(m,PC,reg,err);
                PC = PC + 4;
                break;
            case 0x0D:
                func->ori(m,PC,reg,err);
                PC = PC + 4;
                break;
            case 0x0E:
                func->nori(m,PC, reg,err);
                PC = PC + 4;
                break;
            case 0x0A:
                func->slti(m,PC, reg,err);
                PC = PC + 4;
                break;
            case 0x04:
                PC = func->beq(m,PC, reg,err);
                break;
            case 0x05:
                PC = func->bne(m,PC, reg,err);
                break;
            case 0x07:
                PC = func->bgtz(m,PC,reg,err);
                break;
            case 0x02:
                PC = func->j(m,PC,reg,err);
                break;
            case 0x03:
                PC = func->jal(m,PC,reg,err);
                break;
            default:
                PC = PC +4;
                break;
            }

        }


        if(err[2]|err[3]){
            break;
        }



   }

    if(err[2]|err[3]){
          if(err[0] == 1){
            fprintf(error, "In cycle %d: Write $0 Error\n",cycle);
        }
        if(err[1] == 1){
            fprintf(error, "In cycle %d: Number Overflow\n",cycle);
        }
        if(err[2] == 1){
            fprintf(error, "In cycle %d: Address Overflow\n",cycle);
        }
        if(err[3] == 1){
            fprintf(error, "In cycle %d: Misalignment Error\n",cycle);
        }
    }else{
    fprintf(snap, "cycle %d\n",cycle);
      if(err[0] == 1){
            fprintf(error, "In cycle %d: Write $0 Error\n",cycle);
        }
        if(err[1] == 1){
            fprintf(error, "In cycle %d: Number Overflow\n",cycle);
        }
        cycle++;
        for(i=0;i<32;i++){
            fprintf(snap, "$%02d: 0x%08X\n", i, reg->reg[i]);
        }
        fprintf(snap,"PC: 0x%08X\n\n\n", PC);
    }

*/







    fclose(snap);
    fclose(error);




  return 0;




}
