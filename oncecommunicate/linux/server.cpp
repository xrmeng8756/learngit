#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //�����׽���
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //���׽��ֺ�IP���˿ڰ�
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //ÿ���ֽڶ���0���
    serv_addr.sin_family = AF_INET;  //ʹ��IPv4��ַ
    serv_addr.sin_addr.s_addr = inet_addr("192.168.1.101");  //�����IP��ַ
    serv_addr.sin_port = htons(1234);  //�˿�
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //�������״̬���ȴ��û���������
    listen(serv_sock, 20);

    //���տͻ�������
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    //��ͻ��˷�������
    char str[] = "Hello World!";
    write(clnt_sock, str, sizeof(str));
   
    //�ر��׽���
    close(clnt_sock);
    close(serv_sock);

    return 0;
}
