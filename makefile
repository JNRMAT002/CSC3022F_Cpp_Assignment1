CC = g++
CCFLAGS = -std=c++11

all: myWC main

main: src/main.cpp
	${CC} ${CCFLAGS} src/main.cpp bin/myWC.o -o bin/myWC

myWC: src/myWC.cpp include/myWC.h
	$(CC) ${CCFLAGS} -c src/myWC.cpp -o bin/myWC.o

run:
	@cat data/example.txt | ./bin/myWC

clean:
	@echo "Cleaning up..."
	rm bin/*