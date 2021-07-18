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
	int str_len = 1600;
    char write_buf[2550] = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    
    str_len = strlen(write_buf);
    fd = open("/dev/xdma0_h2c_0", O_RDWR);
    if(fd < 0)
	{
        printf("virtual_disk device open fail\n");
        return -1;
    }
    write(fd, write_buf, str_len);
    close(fd);
    return 0;
 
}