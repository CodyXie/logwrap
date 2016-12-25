
.PHONY : all
all : liblogwrap_static liblogwrap logwarpper

CURDIR=$(shell pwd)
CFLAGS += -Werror -fpie -fPIC -I$(CURDIR)/include
CPPFLAGS+=$(CFLAGS)
CPPFLAGS+= -std=c++11
LDFLAGS+= -lpthread -lstdc++

OBJS:=$(patsubst %.c, %.o, $(filter-out logwrapper.c, $(wildcard *.c)))
OBJS+=$(patsubst %.cpp, %.o, $(wildcard *.cpp))
EXEOBJS:=$(OBJS)
EXEOBJS+=logwrapper.o

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

liblogwrap_static : $(OBJS)
	$(AR) -rcs $@.a $^

liblogwrap : $(OBJS)
	$(CC) -shared $(CLAGS) -o $@.so $^ $(LDFLAGS)

logwarpper : $(EXEOBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean :
	$(RM) *.o liblogwrap_static.a liblogwrap.so logwarpper
