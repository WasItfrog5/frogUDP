/*⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⠞⣉⡭⣭⡙⢦⡀⢀⡴⢛⣩⢭⣍⠳⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⠇⣼⣿⣿⣶⠹⡆⠛⠚⢡⣿⣿⣿⡎⢳⠘⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠘⣇⠻⣟⠟⢋⣼⠃⠀⠀⠈⢯⡛⠛⣁⡾⢠⠇⠀⠀⠀⠀
⠀⠀⠀⠀⣸⠋⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠈⢧⠀⠀⠀⠀
⠀⠀⠀⠀⣯⠀⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠀⢸⠀⠀⠀⠀
⠀⠀⠀⠀⠸⣆⠀⠈⠑⠲⠤⣄⣀⣀⣀⣠⠴⠚⠁⠀⣠⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⣳⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⠋⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢰⠃⠀⠉⠙⣲⠶⠶⠶⠶⣖⠋⠉⠀⠘⣦⠀⠀⠀⠀⠀
⢀⣤⠖⠲⢤⡟⠀⠀⠀⡼⠁⠀⠀⠀⠀⠈⢳⡀⠀⠀⢹⣠⠶⠲⢤⡀
⡾⠀⠀⠀⠈⡇⠀⠀⢸⡃⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⢸⠇⠀⠀⠀⢻
⢳⡀⠀⠀⠀⢿⠀⠀⠈⣧⠀⠀⠀⠀⠀⠀⣰⠇⠀⠀⣼⠀⠀⠀⢀⡼
⠀⠙⢦⣀⠀⢈⣧⠀⠀⠈⠳⣄⣀⣀⣠⠴⠃⠀⠀⣰⡃⠀⢀⡴⠛⠀
⠀⠀⣴⣺⢗⣉⣁⣀⣀⣀⡶⠤⠤⠤⠤⠶⣆⢀⣀⣀⣉⡻⣟⣦⡀⠀
⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀

a cute frog
*/
//made by frog5, dont use as your own or do idrc
#include <frog/frogUDP.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iostream>
#include <cstring>
WSADATA data;
//WSAStartup(MAKEWORD(2,2), &data);
SOCKET sock = INVALID_SOCKET;
sockaddr_in server;
//server.sin_family = AF_INET;
std::string message_431295;
const int bufferSize_12389543 = 1024;
char buffer_71205643[bufferSize_12389543];
sockaddr_in from;
int fromLen = sizeof(from);



int fr::UDP::connectTo(const char* address) {
    WSAStartup(MAKEWORD(2,2), &data);
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    return 0;
};

int fr::UDP::usePort(int port) {
    server.sin_port = htons(port);
    return 0;
};

int fr::UDP::setMessage(std::string message) {
    message_431295 = message;
    return 0;
};

int fr::UDP::sendMessage() {
    sendto(sock, message_431295.c_str(), message_431295.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};

int fr::UDP::sendThisMessage(std::string message) {
    sendto(sock, message.c_str(), message.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};

int fr::UDP::receiveMessage(char* &buffer) {
    //int received = recvfrom(sock, buffer_71205643, sizeof(buffer_71205643), 0, (sockaddr*)&from, &fromLen);
    buffer = buffer_71205643;
    return recvfrom(sock, buffer_71205643, sizeof(buffer_71205643), 0, (sockaddr*)&from, &fromLen);
};

int fr::UDP::close() {
    closesocket(sock);
    WSACleanup();
    return 0;
};