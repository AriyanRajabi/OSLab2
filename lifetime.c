#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc,char* argv[]){
    
    int pid = fork();
    if (pid<0){
        printf(1,"Fork failed!\n");
        exit();
        return 0;
    }
    if(pid ==0){
        sleep(1000);
        printf(1,"childs lifetime:%d\n",lifetime(-1));
        exit();
    }else{
        sleep(1000);
        printf(2,"lifetime of parent with pid %d is %d\n",pid,lifetime(pid));
    }
    wait();
    
    exit();
    return 0;
}