CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system -lpthread

all: BGRSclient
	g++ -o bin/BGRSclient bin/ConnectionHandler.o bin/ClientMain.o bin/KeyboardListenerTask.o $(LDFLAGS)

BGRSclient: bin/ConnectionHandler.o bin/ClientMain.o bin/KeyboardListenerTask.o
	
bin/ConnectionHandler.o: src/ConnectionHandler.cpp
	g++ $(CFLAGS) -o bin/ConnectionHandler.o src/ConnectionHandler.cpp

bin/ClientMain.o: src/ClientMain.cpp
	g++ $(CFLAGS) -o bin/ClientMain.o src/ClientMain.cpp

bin/KeyboardListenerTask.o: src/KeyboardListenerTask.cpp
	g++ $(CFLAGS) -o bin/KeyboardListenerTask.o src/KeyboardListenerTask.cpp

.PHONY: clean
clean:
	rm -f bin/*
