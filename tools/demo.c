#include <assert.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    int fpga_fd,rc;
    char s[] = "xdma test!";
    char s2[] = "Are you OK?";
    char buffer[80];
    // fpga_fd = open("/dev/xdma0_h2c_0", O_RDWR);
    // if(fpga_fd < 0){
    //     printf("error0\n");
    //     return -1;
    // }
    // write(fpga_fd,s,sizeof(s));
    // write(fpga_fd,s2,sizeof(s2));
    // close(fpga_fd);
    // sleep(1);
    fpga_fd = open("/dev/xdma0_c2h_0", O_RDWR);
    if(fpga_fd < 0){
        printf("error1\n");
        return -1;
    }
    rc = read(fpga_fd,buffer,sizeof(buffer));
    printf("%s\n",buffer);
    sleep(1);
    rc = read(fpga_fd,buffer,sizeof(buffer));
    printf("%s\n",buffer);
    close(fpga_fd);
    return 0;
}