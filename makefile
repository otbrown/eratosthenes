CXX = g++
CPPFLAGS = -Wall -O3
LFLAGS =

BIN = es
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HDR = sieve.h

RM = rm -f

%.o: %.cpp ${HDR}
	${CXX} -c ${CPPFLAGS} $< -o $@

${BIN}: ${OBJ}
	${CXX} -o $@ ${LFLAGS} $^

all: ${BIN}

.PHONY: clean
clean:
	${RM} *.o ${BIN}
