#include "InstruM.h"

InstruM::InstruM()
{
    //ctor
}

InstruM::~InstruM()
{
    //dtor
}

 void InstruM::storetoIns(int pc)
{
    int i,j;
    for(j=0;j<1024;j++){
        Ins[j]=0;
    }

    for(i=pc,j=pc;j<1024;i+=4,j+=4){
        Ins[j] |= InM[i];
        Ins[j] <<= 8;
        Ins[j] |= InM[i+1];
        Ins[j] <<= 8;
        Ins[j] |= InM[i+2];
        Ins[j] <<= 8;
        Ins[j] |= InM[i+3];
    }

}
 char InstruM::rtopcode(int i)
 {
     char rt;
     rt = Ins[i]>>26;
     return rt;

 }
char InstruM::rtfunct(int i)
{
    unsigned int temp;
    char rt;
    temp = Ins[i]<<26;
    rt =  temp >>26;
    return rt;

}

char InstruM::rtrs(int i)
{
   unsigned int temp;
   char rt;
   temp = Ins[i]<<6;
   rt = temp>>27;
   return rt;
}
char InstruM::rtrt(int i)
{
    unsigned int temp;
    char rt;
    temp = Ins[i]<<11;
    rt = temp>>27;
    return rt;
}
char InstruM::rtrd(int i)
{
    unsigned int temp;
    char rt;
    temp = Ins[i]<<16;
    rt = temp >>27;
    return rt;
}
char InstruM::rtshamt(int i)
{
    unsigned int temp;
    char rt;
    temp = Ins[i]<<21;
    rt = temp >> 27;
    return rt;
}
short InstruM::rtimmediate(int i)
{
    unsigned int temp;
    short rt;
    temp = Ins[i]<<16;
    rt = temp>>16;
    return rt;
}
int InstruM::rtaddress(int i)
{
    unsigned int temp;
    int rt;
    temp = Ins[i]<<6;
    rt = temp>>6;
    return rt;
}

