
CROSS_COMPILE =
AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CPP		= $(CC) -E
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm

STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump

export AS LD CC CPP AR NM
export STRIP OBJCOPY OBJDUMP

CFLAGS := -Wall -O2 -g
CFLAGS += -I $(shell pwd)/ \

LDFLAGS := -lpthread ./libcmockery.a

export CFLAGS LDFLAGS

TOPDIR := $(shell pwd)
export TOPDIR

TARGET := bowling.out


 obj-y += bowling.o
 obj-y += test_main.o

all : 
	make -C ./ -f $(TOPDIR)/Makefile.build
	$(CC)  -o $(TARGET) built-in.o $(LDFLAGS)


clean:
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)
.PHONY:all clean 
