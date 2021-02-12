CXX = g++
CPPFLAGS = -Wall -O3
LFLAGS =

BIN = es
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TPP = sieve.tpp

RM = rm -f

%.o: %.cpp ${TPP}
	${CXX} -c ${CPPFLAGS} $< -o $@

${BIN}: ${OBJ}
	${CXX} -o $@ ${LFLAGS} $^

all: ${BIN}

.PHONY: clean
clean:
	${RM} *.o ${BIN}
