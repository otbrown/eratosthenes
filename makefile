CXX = g++
CPPFLAGS = -Wall -O3
LFLAGS =

BIN = es
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TPP = $(wildcard *.tpp)
OUT = prime_bitset.h

RM = rm -f

%.o: %.cpp ${TPP}
	${CXX} -c ${CPPFLAGS} $< -o $@

${BIN}: ${OBJ}
	${CXX} -o $@ ${LFLAGS} $^

all: ${BIN}

.PHONY: clean
clean:
	${RM} *.o ${BIN} ${OUT}
