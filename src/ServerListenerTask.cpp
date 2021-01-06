#include <ServerListenerTask.h>

ServerListenerTask::ServerListenerTask(ConnectionHandler& handler): handler_(handler), shutdown(false){}

void ServerListenerTask::operator()(){
    while (1) {
        std::string answer;
        if ((!handler_.getLine(answer)) | (shutdown==true)) {
            std::cout << "Disconnected. Exiting... server\n" << std::endl;
            break;
        }
        int len = answer.length();
        answer.resize(len - 1);
        std::stringstream ss(answer);
        std::string token;
        while (std::getline(ss, token, '|')) {
//            if (token.compare("ACK 4")){
//                shutdown=true;
//            }
            std::cerr << token << std::endl;
        }
    }
}