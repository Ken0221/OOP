#include<stdio.h>

typedef unsigned char BYTE;
struct header{
	BYTE pd;
	BYTE crv[3];
	BYTE mt;
} typedef Header;

union state{
    struct setup{
        BYTE bc[12];
        BYTE cpn[20];
        BYTE llc[18];
        BYTE hlc[5];
        BYTE dt[8];
    } setup;

    struct connect{
        BYTE bc[4];
        BYTE ci[6];
    } connect;
    
    struct alerting{
        BYTE bc[8];
        BYTE pi[4];
        BYTE sig[3];
        BYTE hlc[5];
    } alerting;

} typedef State;

struct isdnmsg{
    Header hder;
    State states;
} typedef Isdnmsg;

int main(){
    Isdnmsg msg;
    printf("Enter 1 digit for the pd field:\n");
    scanf("%c", &msg.hder.pd);
    getchar();
    printf("Enter 3 digits for the crv field:\n");
    scanf("%c %c %c", &msg.hder.crv[0], &msg.hder.crv[1], &msg.hder.crv[2]);
    getchar();
    printf("Enter 7 for the mt field:\n");
    scanf("%c", &msg.hder.mt);
    getchar();
    if(msg.hder.mt == '7'){
        printf("Enter 4 digits for the con's bc field:\n");
        scanf("%c %c %c %c", &msg.states.connect.bc[0], &msg.states.connect.bc[1], &msg.states.connect.bc[2], &msg.states.connect.bc[3]);
        getchar();
        printf("Enter 6 digits for the con's ci field:\n");
        scanf("%c %c %c %c %c %c", &msg.states.connect.ci[0], &msg.states.connect.ci[1], &msg.states.connect.ci[2], &msg.states.connect.ci[3], &msg.states.connect.ci[4], &msg.states.connect.ci[5]);
    getchar();
    }
        printf("\nThe data store in the msg to hold CONNECT message are:\n");
        printf("The pd field's value:%c\n", msg.hder.pd);
        printf("The 3 crv field's values:%c\t%c\t%c\n", msg.hder.crv[0],  msg.hder.crv[1],  msg.hder.crv[2]);
        printf("The mt field's value:%c\n", msg.hder.mt);
        printf("The 4 bc field's values:\n%c\t%c\t%c\t%c\n", msg.states.connect.bc[0], msg.states.connect.bc[1], msg.states.connect.bc[2], msg.states.connect.bc[3]);
        printf("The 6 ci field's values:\n%c\t%c\t%c\t%c\t%c\t%c\n",  msg.states.connect.ci[0], msg.states.connect.ci[1], msg.states.connect.ci[2], msg.states.connect.ci[3], msg.states.connect.ci[4], msg.states.connect.ci[5]);

    return 0;
}
