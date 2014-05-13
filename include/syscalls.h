#ifndef SYSCALLS_H
#define SYSCALLS_H

void sys_sleep(int time);
char sys_read();
void sys_write(int input);
void kill_process();

#endif
