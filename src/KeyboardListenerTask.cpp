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


std::string KeyboardListenerTask::encode(std::string line){
    char arr[2];
    std::string toSend;
    std::stringstream ss(line);
    std::string token;
    std::getline(ss, token,' ');

    if(token.compare("ADMINREG")==0){
        shortToBytes(1, arr);

        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        while (std::getline(ss, token, ' ')) {
            toSend.append(token);
            toSend.append(1,'\0');
        }
    }
    else if(token.compare("STUDENTREG")==0){
        shortToBytes(2, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        while (std::getline(ss, token, ' ')) {
            toSend.append(token);
            toSend.append(1,'\0');
        }
    }
    else if(token.compare("LOGIN")==0){
        shortToBytes(3, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        while (std::getline(ss, token, ' ')) {
            toSend.append(token);
            toSend.append(1,'\0');
        }
    }
    else if(token.compare("LOGOUT")==0){
        logoutSent=true;
        shortToBytes(4, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
    }
    else if(token.compare("COURSEREG")==0){
        shortToBytes(5, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        std::getline(ss, token, ' ');
        toSend.append(token);
//        short tmp= std::atoi(token.c_str());
//        shortToBytes(tmp,arr);
//        toSend.append(1,arr[0]);
//        toSend.append(1,arr[1]);
   }
    else if(token.compare("KDAMCHECK")==0){
        shortToBytes(6, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        std::getline(ss, token, ' ');
        toSend.append(token);
    }
    else if(token.compare("COURSESTAT")==0){
        shortToBytes(7, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        std::getline(ss, token, ' ');
        toSend.append(token);
    }
    else if(token.compare("STUDENTSTAT")==0){
        shortToBytes(8, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        std::getline(ss, token, ' ');
        toSend+=token;
        toSend+="\0";
    }
    else if(token.compare("ISREGISTERED")==0){
        shortToBytes(9, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        std::getline(ss, token, ' ');
        toSend.append(token);
    }
    else if(token.compare("UNREGISTER")==0){
        shortToBytes(10, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
        std::getline(ss, token, ' ');
        toSend.append(token);
    }
    else if(token.compare("MYCOURSES")==0){
        shortToBytes(11, arr);
        toSend.append(1,arr[0]);
        toSend.append(1,arr[1]);
    }
    return toSend;
}

short KeyboardListenerTask::bytesToShort(char* bytesArr)
{
    short result = (short)((bytesArr[0] & 0xff) << 8);
    result += (short)(bytesArr[1] & 0xff);
    return result;
}

void KeyboardListenerTask::shortToBytes(short num, char* bytesArr)
{
    bytesArr[0] = ((num >> 8) & 0xFF);
    bytesArr[1] = (num & 0xFF);
}

//int stringToInt(std::string str){
//
//}