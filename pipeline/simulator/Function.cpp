#include "Function.h"
#include<stdio.h>

Function::Function()
{
    //ctor
}

Function::~Function()
{
    //dtor
}
void Function::add(InstruM* ins,int pc,Reg* r,int* err)
{
    char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

    if(rd == 0){
        err[0] = 1;
    }

    unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    unsigned char rtsign = (unsigned int)r->reg[rt]>>31;
    int num = r->reg[rs] + r->reg[rt];
    unsigned char rdsign = (unsigned int)num>>31;



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

    if(err[0]){
        return;
    }

   r->reg[rd] = r->reg[rs] + r->reg[rt];


}
void Function::addu(InstruM* ins,int pc,Reg* r,int* err)
{
    char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3] | err[0]){
        return ;
    }

    r->reg[rd] = r->reg[rs] + r->reg[rt];

}
void Function::sub(InstruM* ins, int pc, Reg* r,int* err)
{
    char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }

    unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int rstrans = ~(r->reg[rt])+1;
    unsigned char rtsign = (unsigned int)rstrans>>31;
    int num = r->reg[rs] + rstrans;
    unsigned char rdsign = (unsigned int)num>>31;



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

    if(err[0]){
        return ;
    }


  r->reg[rd] = r->reg[rs] - r->reg[rt];
}
void Function::And(InstruM* ins, int pc, Reg*r,int* err)
{
    char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rd] = r->reg[rs] & r->reg[rt];
}
void Function::Or(InstruM* ins, int pc, Reg* r, int* err)
{
    char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);


      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rd] = r->reg[rs] | r->reg[rt];

}
void Function::Xor(InstruM* ins, int pc, Reg* r,int* err)
{
   char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }


    r->reg[rd] = r->reg[rs] ^ r->reg[rt];

}
void Function::nor(InstruM* ins, int pc, Reg* r,int* err)
{

     char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }


    r->reg[rd] = ~(r->reg[rs] | r->reg[rt]);
}
void Function::nand(InstruM* ins, int pc, Reg* r, int* err)
{
     char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rd] = ~(r->reg[rs] & r->reg[rt]);

}
void Function::slt(InstruM* ins, int pc, Reg* r,int* err)
{
     char rd = ins->rtrd(pc);
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);

      if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rd] = (r->reg[rs] < r->reg[rt]);

}
void Function::sll(InstruM* ins, int pc, Reg* r,int* err)
{
    char rd = ins->rtrd(pc);
    char rt = ins->rtrt(pc);
    char shift = ins->rtshamt(pc);

      if(rd == 0 ){
          if(rt == 0 & (ins->rtshamt(pc)==0)){
            err[0] =0;
          }else{
            err[0] = 1;
          }
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rd] = r->reg[rt] << shift;
}
void Function::srl(InstruM* ins, int pc, Reg* r,int* err)
{
    char rd = ins->rtrd(pc);
    char rt = ins->rtrt(pc);
    char shift = ins->rtshamt(pc);

     if(rd == 0){
        err[0] = 1;
    }



    if(err[2] |err[3]|err[0]){
        return ;
    }



    r->reg[rd] = ((unsigned int)r->reg[rt]) >> shift;

}
void Function::sra(InstruM* ins, int pc, Reg* r,int* err)
{
     char rd = ins->rtrd(pc);
    char rt = ins->rtrt(pc);
    char shift = ins->rtshamt(pc);

     if(rd == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rd] = r->reg[rt] >> shift;

}
void Function::addi(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


     if(rt == 0){
        err[0] = 1;
    }


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

    if(err[0]){
        return;
    }

 r->reg[rt] = r->reg[rs] + immed;



}
void Function::addiu(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    if(rt == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rt] = r->reg[rs] + immed;

}
void Function::lw(InstruM* ins, int pc, Reg* r,Memory* m,int* err)
{

    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


    if(rt == 0){
        err[0] = 1;
    }
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
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+1) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+2) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+3) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }

    if(((r->reg[rs]+immed)%4)!=0){
        err[3] = 1;
    }





    if(err[2] |err[3]|err[0]){
        return ;
    }

     int temp = 0;

    temp |= m->mem[r->reg[rs]+immed];
    temp = temp <<8;
    temp |= m->mem[r->reg[rs]+immed+1];
    temp = temp <<8;
    temp |= m->mem[r->reg[rs]+immed+2];
    temp = temp <<8;
    temp |= m->mem[r->reg[rs]+immed+3];

    r->reg[rt] = temp;

}
void Function::lh(InstruM* ins,int pc,Reg* r,Memory* m,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);



      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


    if(rt == 0){
        err[0] = 1;
    }
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
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+1) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }
    if(((r->reg[rs]+immed)%2)!=0){
        err[3] = 1;
    }



    if(err[2] |err[3]|err[0]){
        return ;
    }

    short temp =0;
    temp |=  m->mem[r->reg[rs]+immed];
    temp  = temp << 8;
    temp |=  m->mem[r->reg[rs]+immed+1];
    r->reg[rt] = temp;
}
void Function::lhu(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);



      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


    if(rt == 0){
        err[0] = 1;
    }
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
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+1) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }

    if(((r->reg[rs]+immed)%2)!=0){
        err[3] = 1;
    }



    if(err[2] |err[3]|err[0]){
        return ;
    }
    int  temp =0;
    temp |= (m->mem[r->reg[rs]+(int)immed]);
    temp = temp << 8;
    temp |=  (m->mem[r->reg[rs]+(int)immed+1]);

    r->reg[rt] = temp;

}
void Function::lb(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
     char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);


      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


    if(rt == 0){
        err[0] = 1;
    }
    if( (rssign == 0) & (immedsign==0 )){
            if(rtsign==1){
                err[1] = 1;
            }
    }
    if( (rssign==1) & (immedsign==1 )){
            if(rtsign==0){
                err[1] = 1;
            }
    }
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;

    }




    if(err[2] |err[3]|err[0]){
        return ;
    }
       char temp =0;
    temp |= m->mem[r->reg[rs]+immed];

    r->reg[rt] = temp;

}
void Function::lbu(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
     char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);


      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


    if(rt == 0){
        err[0] = 1;
    }
    if( (rssign==0) & (immedsign ==0 )){
            if(rtsign==1){
                err[1] = 1;
            }
    }
    if( (rssign==1) & (immedsign==1 )){
            if(rtsign==0){
                err[1] = 1;
            }
    }
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }



    if(err[2] |err[3]|err[0]){
        return ;
    }

 unsigned char temp =0;
    temp |= m->mem[r->reg[rs]+immed];
    r->reg[rt] = temp;

}
void Function::sw(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);



      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


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

    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+1) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+2) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+3) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }


    if(((r->reg[rs]+immed)%4)!=0){
        err[3] = 1;
    }



    if(err[2]| err[3]){
        return ;
    }

     unsigned char a1,a2,a3,a4;
    int temp  = r->reg[rt];

    a4 = temp;
    temp = temp >> 8;
    a3 = temp;
    temp = temp >> 8;
    a2 = temp ;
    temp = temp >> 8;
    a1 = temp;

    m->mem[r->reg[rs] + immed] = a1;
    m->mem[r->reg[rs] + immed+1] = a2;
    m->mem[r->reg[rs]+ immed+2] = a3;
    m->mem[r->reg[rs] + immed +3] = a4;

}
void Function::sh(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);



      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


    if( (rssign==0) & (immedsign == 0 )){
            if(rtsign==1){
                err[1] = 1;
            }
    }
    if( (rssign==1) & (immedsign==1 )){
            if(rtsign==0){
                err[1] = 1;
            }
    }
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed+1) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }



    if(((r->reg[rs]+immed)%2)!=0){
        err[3] = 1;
    }

    if(err[2]|err[3]){
        return ;
    }

     unsigned char a1,a2;
    int temp  = r->reg[rt];

    a2 = temp;
    temp = temp >> 8;
    a1 = temp;

    m->mem[r->reg[rs] + immed] = a1;
    m->mem[r->reg[rs] + immed+1] = a2;


}
void Function::sb(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);



      unsigned char rssign = (unsigned int)r->reg[rs]>>31;
    int immedtrans = immed;
    unsigned char immedsign = (unsigned int)immedtrans>>31;
    int num = r->reg[rs] + immedtrans;
    unsigned char rtsign = (unsigned int)num>>31;


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
    if((r->reg[rs]+immed) >=1024){
        err[2] = 1;
    }
    if((r->reg[rs]+immed)<0){
        err[2] = 1;
    }




    if(err[2]|err[3]){
        return;
    }

    unsigned char a1;
    int temp  = r->reg[rt];

    a1 = temp;
    m->mem[r->reg[rs] + immed] = a1;

}
void Function::lui(InstruM* ins, int pc, Reg* r, Memory* m,int* err)
{
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    unsigned int temp;
    temp = immed;
    temp = temp <<16;

    if(rt == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }


    r->reg[rt] = temp;

}
void Function::andi(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    unsigned short immed = ins->rtimmediate(pc);

    unsigned int temp;
    temp = immed;
    temp = r->reg[rs] & temp;

    if(rt == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rt] = temp;
}
void Function::ori(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    unsigned short immed = ins->rtimmediate(pc);

    unsigned int temp;
    temp = immed;
    temp = r->reg[rs] | temp;

    if(rt == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rt] = temp;

}
void Function::nori(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    unsigned short immed = ins->rtimmediate(pc);

    unsigned int temp;
    temp = immed;
    temp = ~(r->reg[rs] | temp);

    if(rt == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }

    r->reg[rt] = temp;

}
void Function::slti(InstruM * ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    unsigned int temp;
    temp = immed;
    int ans;
    ans = temp;

    if(rt == 0){
        err[0] = 1;
    }


    if(err[2] |err[3]|err[0]){
        return ;
    }


    r->reg[rt] = (r->reg[rs]<ans);

}
int Function::beq(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    int temp;
    int ans;
    temp = immed;

    if(r->reg[rs] == r->reg[rt]){
        ans = pc+4+4*temp;
    }else{
        ans = pc +4;
    }

    return ans;
}
int Function::bne(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    char rt = ins->rtrt(pc);
    short immed = ins->rtimmediate(pc);

    int temp;
    int ans;
    temp = immed;

    if(r->reg[rs] != r->reg[rt]){
        ans = pc+4+4*temp;
    }else{
        ans = pc +4;
    }

    return ans;

}
int Function::bgtz(InstruM* ins, int pc, Reg* r,int* err)
{
    char rs = ins->rtrs(pc);
    short immed = ins->rtimmediate(pc);

    int temp;
    int z = 0;
    int ans;
    temp = immed;

    if(r->reg[rs] > z){
        ans = pc+4+4*temp;
    }else{
        ans = pc +4;
    }

    return ans;

}
int Function::j(InstruM* ins, int pc, Reg* r,int* err)
{

    unsigned short immed = ins->rtimmediate(pc);

    int temp;
    unsigned int temppc;
    int ans;
    temp = immed<<2;
    temppc = pc;
    temppc = temppc>>24;
    temppc = temppc <<24;

    ans = temppc|temp;

    return ans;

}
int Function::jal(InstruM* ins, int pc, Reg* r,int* err)
{

    unsigned short immed = ins->rtimmediate(pc);

    int temp;
    unsigned int temppc;
    int ans;
    temp = immed<<2;
    temppc = pc;
    temppc = temppc>>24;
    temppc = temppc <<24;

    ans = temppc|temp;
    r->reg[31] = pc+4;

    return ans;


}
void Function::IF(InstruM* ins, Reg* r,IF_ID* if_id,int pc)
{
    if_id->After_IF = ins->Ins[pc];
    if_id->pc = pc +4;

    if_id->opcode = ins->rtopcode(pc);
    if_id->funct = ins->rtfunct(pc);
    if_id->rs = ins->rtrs(pc);
    if_id->rt = ins->rtrt(pc);
    if_id->rd = ins->rtrd(pc);
    if_id->shamt = ins->rtshamt(pc);
    if_id->immed = ins->rtimmediate(pc);

    if_id->Read_Data1 = r->reg[if_id->rs];
    if_id->Read_Data2 = r->reg[if_id->rt];

}
void Function::ID(IF_ID* if_id,ID_EX* id_ex)
{
    id_ex->instruction = if_id->After_IF;
    id_ex->rt = if_id->rt;
    id_ex->rd = if_id->rd;
    id_ex->Read_Data1 = if_id->Read_Data1;
    id_ex->Read_Data2 = if_id->Read_Data2;

    id_ex->opcode = if_id->opcode;
    id_ex->funct = if_id->funct;
    id_ex->rs = if_id->rs;
    id_ex->shamt = if_id->shamt;
    id_ex->address = if_id->address;



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
        break;
    case 0x05:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        break;
    case 0x07:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        break;
    case 0x02:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
        break;
    case 0x03:
        id_ex->RegDst = 0;
        id_ex->ALUSrc = 0;
        id_ex->MemtoReg = 0;
        id_ex->RegWrite = 0;
        id_ex->MemRead = 0;
        id_ex->MemWrite = 0;
        id_ex->Branch = 1;
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

    if(if_id->opcode == 0x00 && if_id->funct==0x08){
        id_ex->RegDst = 0;
        id_ex->RegWrite = 0;
    }


}
