CC := gcc
CFLAGS := -Wall -march=native -Ofast
LDFLAGS := 

SRCDIR := ./src
OBJDIR := ./obj

SRCS := $(patsubst ${SRCDIR}/%,%,$(wildcard ${SRCDIR}/*.c))
OBJS := $(patsubst %.c,%.o,${SRCS})

BIN := $(shell basename ${CURDIR})

${BIN}: $(addprefix ${OBJDIR}/,${OBJS})
ifndef LDFLAGS
	${CC} -o $@ $^
else
	${CC} ${LDFAGS} -o $@ $^
endif

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
ifndef CFLAGS
	${CC} -MMD -MD -o $@ -c $<
else
	${CC} ${CFLAGS} -MMD -MD -o $@ -c $<
endif

${OBJDIR}:
	mkdir ${OBJDIR}

.PHONY: clean
clean:
	rm -r ${BIN} $(wildcard ${OBJDIR}/*)

-include $(addprefix ${OBJDIR}/,$(patsubst %.o,%.d,${OBJS}))
