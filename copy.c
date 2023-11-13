#include "types.h"
#include "stat.h"
#include "user.h"


int main (int argc,char* argv[]){
    const char* src = argv[1];
    const char* dest = argv[2];
    copy(src,dest);
    return 0;
}