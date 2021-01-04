#include <serverListenerTask.h>

serverListenerTask::serverListenerTask(ConnectionHandler& handler): handler_(handler), answer(), token(){}

void serverListenerTask::operator()(){
    while (1) {
        if (!handler_.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        int len = answer.length();
        answer.resize(len - 1);
        std::stringstream ss(answer);
        std::string token;
        while (std::getline(ss, token, '|')) {
            std::cerr << token << std::endl;
        }
    }
}