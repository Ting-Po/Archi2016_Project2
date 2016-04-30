#ifndef MEMORY_H
#define MEMORY_H


class Memory
{
    public:
        Memory();
        virtual ~Memory();
        unsigned char  mem[1024];
        unsigned char sp_memnum[8];
    protected:
    private:
};

#endif // MEMORY_H
