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
    short bytesToShort(char* bytesArr);
    void shortToBytes(short num, char* bytesArr);
//    int stringToInt(std::string);
public:
    KeyboardListenerTask(ConnectionHandler& handler);
    void operator()( std::future<bool> futureObj);
    std::string encode(std::string);

};

#endif //CLIENT_KEYBOARDLISTENERTASK_H
