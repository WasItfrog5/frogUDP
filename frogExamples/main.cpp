#include <frog/frogUDP.h>
#include <iostream>

int main() {
    fr::UDP udp;//------------------------------------------------------it was not needed for me to make it, but its just better
    udp.connectTo("127.0.0.1");//---------------------------------------connects to local host
    udp.usePort(8080);//------------------------------------------------uses port 8080
    while(true) {//-----------------------------------------------------send messages until closed
        std::string message;
        getline(std::cin, message);
        udp.setMessage(message);//--------------------------------------sets message to send
        udp.sendMessage();//--------------------------------------------sends the message that was set (you can also use sendThisMessage(message), it sends automatically)
        char* buffer;//-------------------------------------------------holds received message here
        int bytes = udp.receiveMessage(buffer);//-----------------------this sets number of bytes received to variable bytes and receives the message to variable buffer
        if(bytes>0) {//-------------------------------------------------does this if number of bytes received is bigger than 0
            buffer[bytes] = '\0';//-------------------------------------idk what this does but it works
            std::cout << "received: " << buffer << std::endl;//---------shows received message
        }
    }
    udp.close();//------------------------------------------------------closes the socket or whatever, please use to prevent resource leaks
}
