#include "types.h"
#include "stat.h"
#include "user.h"


int main (int argc,char* argv[]){
    for (int i = 0;i<3;i++){
        int pid = fork();
        if(pid<0){
            printf(1,"fork failed!s\n");
            exit();
        }
        if(pid == 0 && i ==0){ //first child
            int pid = fork();
            if( pid<0){
                printf(1,"fork failed!\n");
                exit();
            }
            if(pid == 0){
                printf(1,"uncle called from user, result:%d\n", uncle());
               
            }
            
        }

    }
    for(int i = 0;i<3;i++){
        wait();//wait to kill zombies
    }
    
    exit();
    return 0;
}