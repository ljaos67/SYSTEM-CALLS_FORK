#
# PROGRAM: ASSIGNMENT #1
# AUTHOR:  Leonart Jaos
#

CXXFLAGS = -Wall -Werror -std=c++14

z1911688_project1: z1911688_project1.o
	g++ $(CXXFLAGS) -o z1911688_project1 z1911688_project1.o

z1911688_project1.o: z1911688_project1.cpp
	g++ $(CXXFLAGS) -c z1911688_project1.cpp

clean:
	rm -f *.o z1911688_project1
