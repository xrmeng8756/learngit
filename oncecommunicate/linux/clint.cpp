#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
    //�����׽���
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    //����������ض���IP�Ͷ˿ڣ���������
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //ÿ���ֽڶ���0���
    serv_addr.sin_family = AF_INET;  //ʹ��IPv4��ַ
    serv_addr.sin_addr.s_addr = inet_addr("192.168.1.101");  //�����IP��ַ
    serv_addr.sin_port = htons(1234);  //�˿�
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
   
    //��ȡ���������ص�����
    char buffer[40];
    read(sock, buffer, sizeof(buffer)-1);
   
    printf("Message form server: %s\n", buffer);
   
    //�ر��׽���
    close(sock);

    return 0;
}
