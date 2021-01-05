CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system -lpthread

all: BGRSClient
	g++ -o bin/BGRSClient bin/ConnectionHandler.o bin/ClientMain.o bin/ServerListenerTask.o $(LDFLAGS)

BGRSClient: bin/ConnectionHandler.o bin/ClientMain.o bin/ServerListenerTask.o
	
bin/ConnectionHandler.o: src/ConnectionHandler.cpp
	g++ $(CFLAGS) -o bin/ConnectionHandler.o src/ConnectionHandler.cpp

bin/ClientMain.o: src/ClientMain.cpp
	g++ $(CFLAGS) -o bin/ClientMain.o src/ClientMain.cpp

bin/ServerListenerTask.o: src/ServerListenerTask.cpp
	g++ $(CFLAGS) -o bin/ServerListenerTask.o src/ServerListenerTask.cpp

.PHONY: clean
clean:
	rm -f bin/*
