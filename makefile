CC := gcc
CFLAGS := -Wall -march=native -Ofast
LDFLAGS := 

SRCDIR := ./src
OBJDIR := ./obj

SRCS := $(patsubst ${SRCDIR}/%,%,$(wildcard ${SRCDIR}/*.c))
OBJS := $(patsubst %.c,%.o,${SRCS})

BIN := $(shell basename ${CURDIR})

${BIN}: ${OBJDIR}/${OBJS}
ifndef LDFLAGS
	${CC} -o $@ $^
else
	${CC} ${LDFAGS} -o $@ $^
endif

${OBJDIR}/%.o: ${SRCDIR}/%.c
	${CC} ${CFLAGS} -o $@ -c $<

.PHONY: clean
clean:
	rm -r ${BIN} $(wildcard ${OBJDIR}/*.o)
