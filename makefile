CPPFLAGS	=	-std=c++20 -Wall -Wextra -Wpedantic -Werror -g
CC		=	g++
OBJECTS		=	main.o CalcParser.o Environment.o Operations.o
PROGRAM		=	calculator

$(PROGRAM): $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROGRAM) $(OBJECTS)

main.o: main.cpp CalcParser.h
	$(CC) $(CPPFLAGS) -c main.cpp

CalcParser.o: CalcParser.cc CalcParser.h Environment.h
	$(CC) $(CPPFLAGS) -c CalcParser.cc

Environment.o: Environment.cc Environment.h
	$(CC) $(CPPFLAGS) -c Environment.cc

Operations.o: Operations.cc Operations.h
	$(CC) $(CPPFLAGS) -c Operations.cc

clean:
	rm -f *.o $(PROGRAM)
