#ifndef CLIENT_SERVERLISTENERTASK_H
#define CLIENT_SERVERLISTENERTASK_H

#include <ConnectionHandler.h>
#include <string>
#include <sstream>

class ConnectionHandler;

class ServerListenerTask{
private:
    ConnectionHandler& handler_;
    std::string answer;
    std::string token;
public:
    ServerListenerTask(ConnectionHandler& handler);
    void operator()();
};

#endif //CLIENT_SERVERLISTENERTASK_H
