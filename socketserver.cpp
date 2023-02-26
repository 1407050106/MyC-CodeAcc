#include "socketserver.h"
using namespace std;

int main() {
    //SERVER
    // 1.创建句柄   
    int listenfd;
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    if(listenfd==-1)
    {
        printf("Socket create fail!\n");
    }
    // 2.绑定端口
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port=htons(5001);
    if(bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))!=0)
    {
        printf("bind failed \n");
    }

    if(listen(listenfd,5)!=0)
    {
        printf("Listen failed\n");
        close(listenfd);
    }
    // 3.用接收函数去监听
    int clintfd;
    int socklen=sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    clintfd=accept(listenfd,(struct sockaddr*)&client_addr,(socklen_t *)&socklen);
    if(clintfd==-1)
        printf("connect failed\n");
    else
        printf("client %s has connnected\n",inet_ntoa(client_addr.sin_addr));

    int iret;
    char* buf;
    memset(buf,0,sizeof(buf));
    iret=recv(clintfd,buf,strlen(buf),0);
    if(iret<=0)
    {
        perror("send");
    }
    printf("receive %s\n",buf);
    // 4.有客户端连接就可以通信了
    char buffer[1024];
    while (1)
    {
        int iret;
        memset(buffer,0,sizeof(buffer));
        iret=recv(clintfd,buffer,sizeof(buffer),0);
        if (iret<=0) 
        {
            printf("iret=%d\n",iret); break;  
        }
            printf("receive :%s\n",buffer);
    
        strcpy(buffer,"ok");//reply cilent with "ok"
        if ( (iret=send(clintfd,buffer,strlen(buffer),0))<=0) 
        { 
            perror("send"); 
        }
        printf("send :%s\n",buffer);
    } 

    close(listenfd); 
    close(clintfd);

}