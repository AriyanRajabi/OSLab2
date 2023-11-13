#include "types.h"
#include "stat.h"
#include "user.h"


int main (int argc,char* argv[]){
    const char* src = argv[1];
    const char* dest = argv[2];
    if(!src || !dest){
        printf(1,"Invalid arguments recieved in user program!\n");
        return 0;
    }
    printf(1,"copy file %s to %s\n",src,dest);
    copy(src,dest);
    return 0;
}