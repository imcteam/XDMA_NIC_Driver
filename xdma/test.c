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
	int str_len = 0;
    char write_buf[2550] = { 0 };
    char read_buf[2550]  = { 0 };
    
    printf("please input a string:\n");
    scanf("%s", write_buf);
    str_len = strlen(write_buf);
	if (str_len > MAX_LEN)
	{
		printf("Error, the input string length is beyond the maximum str length.\n");
		return -1;
	}
 
    fd = open("/dev/xdma0_h2c_1", O_RDWR);
    if(fd < 0)
	{
        printf("virtual_disk device open fail\n");
        return -1;
    }
    
	lseek(fd, 0, SEEK_SET);
	
    printf("Write %d bytes data to /dev/virtual_disk \n", str_len);
    printf("%s\n", write_buf);
 
    write(fd, write_buf, str_len);

    close(fd);
    fd = open("/dev/xdma0_c2h_1", O_RDWR);
 
	lseek(fd, 0, SEEK_SET);
    printf("Read %d bytes data from /dev/virtual_disk \n", str_len);
    read(fd, read_buf, str_len);
    printf("%s\n", read_buf);
    
    close(fd);
    return 0;
 
}