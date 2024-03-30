#include<stdio.h>

struct preg{
    unsigned int clean: 1;
    unsigned int lowInk: 2;
    unsigned int Ecode: 4;
    unsigned int pjam: 1;
    int pnum;
} typedef Page;

int main(){
    Page page[20] = {{0, 0, 0, 0, 0}};
    for(int i = 0; i < 20; i++){
        page[i].pnum = i + 1;
        if(i == 19)
            page[i].clean = 1;
        if(i >= 8)
            page[i].lowInk = 3;
        if(i == 12)
            page[i].Ecode = 10;
        if(i == 14)
            page[i].pjam = 1;
    }
    printf("Status:Clean  LowInk  Ecode   Pjam    Pnum\n");
    for(int i = 0; i < 20; i++){
        printf("\t%u\t%u\t%u\t%u\t%d\n", page[i].clean, page[i].lowInk, page[i].Ecode, page[i].pjam, page[i].pnum);
    }
    return 0;
}
