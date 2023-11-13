#include "user.h"
#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "fcntl.h"


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//Lab 2
int sys_root(void){
  int n = myproc()->tf->ebx;
  cprintf("sys_root called, n=%d\n",n);
  return digital_root(n);
}

int sys_uncle(void){
  cprintf("sys_uncle called for pid:%d\n",myproc()->pid);
  return get_uncle_count();
}

int sys_copy(void){
  char *src,*dest;

  if (argstr(0,&src) < 0 || argstr(1,&dest)<0){
    cprintf("Invalid arguments\n");
    return -1;
  }
  int src_file = open(src, O_RDONLY);
  if(src_file<0){
    cprintf("failed to open src file\n");
    return -1;
  }
  int dest_file = open(dest,O_CREATE|O_WRONLY);
  if(dest_file<0){
    close(src_file);
    cprintf("failed to open dest file\n");
    return -1;
  }
  
  char buf[512];
  int n;
  while(n=read(src_file,buf,sizeof(buf))){
    if(write(dest_file,buf,n)!=n){
      close(src_file);
      close(dest_file);
      cprintf("error writing\n");
      return -1;
    }
  }
  close(src_file);
  close(dest_file);
  return 0;
}