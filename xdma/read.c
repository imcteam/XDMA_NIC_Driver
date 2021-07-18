#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
 
#define MAX_LEN (1000)
 
int main()
{
    int fd;
    int rv;
	int str_len = 1000;
    char read_buf[2550]  = { 0 };
    


    fd = open("/dev/xdma0_c2h_0", O_RDWR);
 
	lseek(fd, 0, SEEK_SET);
    printf("Read %d bytes data from /dev/virtual_disk \n", str_len);
    rv=read(fd, read_buf, str_len);
    if(!rv){
        printf("read failed!\n");
        return 0;
    }
    printf("totally %d byte received\n",rv);
    for(int i=0;i<rv;i++){
        printf("%02x  ",read_buf[i]);
    }
    printf("\n");
    
    close(fd);
    return 0;
 
}