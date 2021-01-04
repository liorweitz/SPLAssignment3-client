#ifndef CLIENT_SERVERLISTENERTASK_H
#define CLIENT_SERVERLISTENERTASK_H

#include <connectionHandler.h>
#include <string>
#include <sstream>

class ConnectionHandler;

class serverListenerTask{
private:
    ConnectionHandler& handler_;
    std::string answer;
    std::string token;
public:
    serverListenerTask(ConnectionHandler& handler);
    void operator()();
};

#endif //CLIENT_SERVERLISTENERTASK_H
