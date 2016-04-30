#ifndef INSTRUM_H
#define INSTRUM_H


class InstruM
{
    public:
        InstruM();
        virtual ~InstruM();
        unsigned char pc_instrunum[8];
        unsigned char InM[1024];
        unsigned int Ins[1024];
        void storetoIns(int pc);
        char rtopcode(int i);
        char rtfunct(int i);
        char rtrs(int i);
        char rtrt(int i);
        char rtrd(int i);
        char rtshamt(int i);
        short rtimmediate(int i);
        int rtaddress(int i);

    protected:
    private:



};

#endif // INSTRUM_H
