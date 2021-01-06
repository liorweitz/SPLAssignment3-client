#include <KeyboardListenerTask.h>

KeyboardListenerTask::KeyboardListenerTask(ConnectionHandler& handler): handler_(handler),logoutSent(false){}

void KeyboardListenerTask::operator()(std::future<bool> futureObj) {
    while (1) {
        const short bufsize=1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
        std::string line(buf);
        std::string toSend = encode(line);
        std::cout << toSend << std::endl;
        if (!handler_.sendLine(toSend)) {
            std::cout << "Disconnected. Exiting...keyboard\n" << std::endl;
            break;
        }
        if (line.compare("LOGOUT")==0){
            int result=futureObj.get();
            if (result==true){
                std::cout << "terminating!!!!!" << std::endl;
                std::terminate();
            }
        }
    }
}

void KeyboardListenerTask::goBusy(){

}

std::string KeyboardListenerTask::encode(std::string line){
    std::string toSend;
    std::stringstream ss(line);
    std::string token;
    std::getline(ss, token,' ');

    if(token.compare("ADMINREG")==0){
        toSend+="01";
        while (std::getline(ss, token, ' ')) {
            toSend+=token;
            toSend+="0";
        }
    }
    else if(token.compare("STUDENTREG")==0){
        toSend+="02";
        while (std::getline(ss, token, ' ')) {
            toSend+=token;
            toSend+="0";
        }
    }
    else if(token.compare("LOGIN")==0){
        toSend+="03";
        while (std::getline(ss, token, ' ')) {
            toSend+=token;
            toSend+="0";
        }
    }
    else if(token.compare("LOGOUT")==0){
        logoutSent=true;
        toSend+="04";
    }
    else if(token.compare("COURSEREG")==0){
        toSend+="05";
        std::getline(ss, token, ' ');
        toSend+=token;
   }
    else if(token.compare("KDAMCHECK")==0){
        toSend+="06";
        std::getline(ss, token, ' ');
        toSend+=token;
    }
    else if(token.compare("COURSESTAT")==0){
        toSend+="07";
        std::getline(ss, token, ' ');
        toSend+=token;
    }
    else if(token.compare("STUDENTSTAT")==0){
        toSend+="08";
        std::getline(ss, token, ' ');
        toSend+=token;
        toSend+="0";
    }
    else if(token.compare("ISREGISTERED")==0){
        toSend+="09";
        std::getline(ss, token, ' ');
        toSend+=token;
    }
    else if(token.compare("UNREGISTER")==0){
        toSend+="10";
        std::getline(ss, token, ' ');
        toSend+=token;
    }
    else if(token.compare("MYCOURSES")==0){
        toSend+="11";
        std::getline(ss, token, ' ');
        toSend+=token;
    }
    return toSend;
}
