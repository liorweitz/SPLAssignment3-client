#ifndef CLIENT_KEYBOARDLISTENERTASK_H
#define CLIENT_KEYBOARDLISTENERTASK_H

#include <ConnectionHandler.h>
#include <string>
#include <sstream>
#include <future>


class KeyboardListenerTask{
private:
    ConnectionHandler& handler_;
    bool shutdown;
public:
    KeyboardListenerTask(ConnectionHandler& handler);
    void operator()( std::future<int> futureObj);
    std::string encode(std::string);
    void parse();
};

#endif //CLIENT_KEYBOARDLISTENERTASK_H
