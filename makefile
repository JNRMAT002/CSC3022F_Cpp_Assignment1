CC = g++
CCFLAGS = -std=c++11

main: src/main.cpp
	${CC} ${CCFLAGS} src/main.cpp -o bin/myWC

run:
	@bin/./myWC

clean:
	@echo "Cleaning up..."
	rm bin/*