# XDMA_NIC_Driver
![avatar](https://raw.githubusercontent.com/ChangfengLi/XDMA_NIC_Driver/main/img/net_dev.jpg)
## 加载模块
```shell
cd xdma
sudo make //编译
sudo insmod xdma.ko //加载模块
```
## 卸载模块
```shell
sudo ifconfig enp2s0 down //关闭生成的相应网口
sudo rmmod xdma //卸载模块
sudo make
sudo insmod xdma.ko
dmesg //打印日志信息
dmesg | tail -n 50
```
