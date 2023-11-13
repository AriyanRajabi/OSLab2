#include "types.h"
#include "stat.h"
#include "user.h"

void f(void){
    printf(2,"10 seconds passed");
    exit();
}

int main (int argc,char* argv[]){
    int pid_to_find = atoi(argv[1]);
    int pid = fork();
    if (pid<0){
        printf(1,"Fork failed!\n");
        exit();
        return 0;
    }
    if(pid ==0){
        
        printf(1,"life:%d\n",lifetime(pid_to_find));
        exit();
    }else{
        printf(2,"life time of %d is %d\n",pid,lifetime(pid));
    }
    wait();
    
    //printf(1,"time:%d\n",(unsigned)time(NULL));
    exit();
    return 0;
}