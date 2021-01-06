#ifndef CLIENT_KEYBOARDLISTENERTASK_H
#define CLIENT_KEYBOARDLISTENERTASK_H

#include <ConnectionHandler.h>
#include <string>
#include <sstream>
#include <future>


class KeyboardListenerTask{
private:
    ConnectionHandler& handler_;
    bool logoutSent;
    void parse();
    void goBusy();
public:
    KeyboardListenerTask(ConnectionHandler& handler);
    void operator()( std::future<bool> futureObj);
    std::string encode(std::string);

};

#endif //CLIENT_KEYBOARDLISTENERTASK_H
