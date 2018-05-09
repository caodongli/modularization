# Makefile for external modules
KERNEL := /lib/modules/`uname -r`/build
obj-m := medium.o

all:
	make -C $(KERNEL) M=`pwd` modules
install:
	make -C $(KERNEL) M=`pwd` modules_install
	depmod -A

clean:
	make -C $(KERNEL) M=`pwd` clean
	rm -f *.*~

