#ifndef IF_ID_H
#define IF_ID_H



class IF_ID
{
    public:
        IF_ID();
        virtual ~IF_ID();
        int After_IF;
        int pc;

        int Read_Data1;
        int Read_Data2;
        short immed;
        unsigned short unimmed;
        char rt;
        char rd;

        char opcode;
        char funct;
        char rs;
        char shamt;
        int address;
        char* out;
        int forwarding;
        int isNOP;


    protected:
    private:
};

#endif // IF_ID_H
