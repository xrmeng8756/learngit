#include<stdio.h>
#include<winsock2.h>
#pragma comment (lib, "ws2_32.lib")

#define BUF_SIZE 100

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("192.168.1.101");
    sockAddr.sin_port = htons(1234);
    bind(servSock, (SOCKADDR *)&sockAddr, sizeof(SOCKADDR));

    listen(servSock, 20);

    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR *)&clntAddr, &nSize);
    char buffer[BUF_SIZE];
    int strLen = recv(clntSock, buffer, BUF_SIZE, 0);
    send(clntSock, buffer, strLen, 0);

    closesocket(clntSock);
    closesocket(servSock);

    WSACleanup();

    return 0;
}
