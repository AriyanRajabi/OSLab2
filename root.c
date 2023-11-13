#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc,char* argv[]){
    int prev_ebx = 0,number = atoi(argv[1]);//get argument from the comand line
    asm volatile(
        "movl %%ebx, %0;"// store current ebx in prev_ebx
        "movl %1, %%ebx" //put number in ebx
        : "=r" (prev_ebx) //output (%0)
        : "r" (number) //%1 as input
    );
    printf(2,"digital root called from user: %d, result %d\n",number,root());
    asm ("movl %0, %%ebx"::"r"(prev_ebx)); //restore ebx
    exit();
    return 0;
}