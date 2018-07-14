#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define BUF_SIZE 100

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("192.168.1.101");
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR *)&sockAddr, sizeof(SOCKADDR));

    char bufSend[BUF_SIZE] = {0};
    printf("Input a string: ");
    scanf("%s", bufSend);
    send(sock, bufSend, strlen(bufSend), 0);

    char bufRecv[BUF_SIZE] = {0};
    recv(sock, bufRecv, BUF_SIZE, 0);

    printf("Message from server: %s\n", bufRecv);

    closesocket(sock);

    WSACleanup();

    system("pause");
    return 0;
}
