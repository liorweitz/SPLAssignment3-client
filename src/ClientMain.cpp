#include <ConnectionHandler.h>
#include <KeyboardListenerTask.h>
#include <stdlib.h>
#include <thread>
#include <future>



int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " host port" << std::endl;
        return -1;
    }

//    bool logoutSent=false;
    std::string host = argv[1];
    short port = atoi(argv[2]);
    
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cout << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }
    //creates exit signal promised object to pass to KeyboardListenerTask thread to inform it to terminate.
    std::promise<bool> exitSignal;
    std::future<bool> futureObj=exitSignal.get_future();


    KeyboardListenerTask keyboard_listener_task(connectionHandler);
//    ServerListenerTask server_listener_task(connectionHandler);

    std::thread th1(std::ref(keyboard_listener_task),std::move(futureObj));
//    std::thread th2(std::ref(server_listener_task));

    while (1) {
        std::string answer;
        if ((!connectionHandler.getLine(answer))) {
            std::cout << "getLine error\n" << std::endl;
            break;
        }
        std::cout << answer<< std::endl;
        if (answer.compare("ACK 4")==0){
            exitSignal.set_value(true);
            th1.join();
            break;
        }
        else if(answer.compare("ERR 4")==0){
            exitSignal.set_value(false);
        }
    }
    return 0;
}
