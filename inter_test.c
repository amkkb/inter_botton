#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    int fd;
    int key_val = 0;
    fd = open("/dev/key_driver",O_RDWR);
    if(fd < 0)
    {   
         printf("open device failed\n");
         return -1;    
    }
    else
    {
        printf("open success\n");
    }

    while(1)
    {
        read(fd,&key_val,1);
        printf("key_val = 0x%x\n",key_val);
        usleep(100);
    }

    return 0;

}
