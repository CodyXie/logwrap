
.PHONY : all
all : liblogwrap_static liblogwrap logwarpper

CURDIR=$(shell pwd)
CFLAGS += -Werror -fPIC -fpie -I$(CURDIR)/include
LDFLAGS+= -lpthread

OBJS:=$(patsubst %.c, %.o, $(filter-out logwrapper.c, $(wildcard *.c)))
EXEOBJS:=$(OBJS)
EXEOBJS+=logwrapper.o

%.o : %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

%.o : %.cpp
	$(CC) $(CPPFLAGS) -fPIC -c $< -o $@

liblogwrap_static : $(OBJS)
	$(AR) -rcs $@.a $^

liblogwrap : $(OBJS)
	$(CC) -shared $(CLAGS) -o $@.so $^ $(LDFLAGS)

logwarpper : $(EXEOBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean :
	$(RM) *.o liblogwrap_static.a liblogwrap.so logwarpper
