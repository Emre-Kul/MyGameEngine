#include "Internet.h"
Server::Server(){
	Version = MAKEWORD(2,2);
	error = WSAStartup(Version,&wsa);
	AdressSize = sizeof(Adress);
	index = 0;
}
void Server::setAdress(int port,int maxSize){
	socketSize = maxSize;
	SOCK_Con = new SOCKET[maxSize];

	for(int i = 0;i < maxSize;i++) SOCK_Con[i] = 0;

	SOCK_Listen = socket(AF_INET,SOCK_STREAM,NULL);

	Adress.sin_family = AF_INET;
	Adress.sin_port = htons(port);
	Adress.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(SOCK_Listen,(SOCKADDR*)&Adress,AdressSize) == SOCKET_ERROR) error = 1;//bind socket
	if(listen(SOCK_Listen,socketSize) == SOCKET_ERROR) error = 1;	
}
void Server::runServer(){
    char Data[1024];
	int activity,i;
	for(i = 0;i < 1024;i++) Data[i] ='\0';
	i = 0;
	    FD_ZERO(&readset);
		FD_SET(SOCK_Listen,&readset);
		for(int i = 0;i < socketSize;i++)if(SOCK_Con[i] > 0)FD_SET(SOCK_Con[i],&readset);
		if(select(0,&readset,NULL,NULL,NULL) == SOCKET_ERROR)error = WSAGetLastError();
		if(FD_ISSET(SOCK_Listen,&readset)){//if there is an something
			if( (SOCK_Connection = accept(SOCK_Listen,(SOCKADDR*)&Adress,&AdressSize)) == SOCKET_ERROR)error = WSAGetLastError();//accept connection
			else if(index == socketSize) {
				send(SOCK_Connection,"Server Full",11,NULL);
				send(SOCK_Connection,"",0,NULL);
			}
				i = 0;
			while(i < socketSize && SOCK_Con[i] != 0) i++;
			if(i < socketSize){
				SOCK_Con[i] = SOCK_Connection;
				messages.push_back(new Message("CON\0",i,INTERNET_CONNECTED));
				index++;
			}
		}//FD_ISSET IF
		for(i = 0;i < socketSize;i++){//else other socket recv data
			if(FD_ISSET(SOCK_Con[i],&readset)){
				activity = recv(SOCK_Con[i],Data,1024,NULL) ; 
				if(activity == SOCKET_ERROR){
					if(WSAGetLastError() == WSAECONNRESET){//disconnect
						closesocket(SOCK_Con[i]);
						SOCK_Con[i] = 0;
						messages.push_back(new Message("DISC\0",i,INTERNET_DISCONNECTED));
					    index--;
					}
					else cout << "Cant Recv";
				}
				if(activity == 0){
					closesocket(SOCK_Con[i]);
					SOCK_Con[i] = 0;
					messages.push_back(new Message("DISC\0",i,INTERNET_DISCONNECTED));
					index--;
				}
				else{
				Data[activity] = '\0';
				messages.push_back(new Message(Data,i,INTERNET_RECEVING));
				}
			}
		}//FOR
}
void Server::sendMessage(string msg,int socketId){
	int msgSize = msg.length();
	if(SOCK_Con[socketId] != 0)
		send(SOCK_Con[socketId],msg.c_str(),msgSize,NULL);
}
void Server::sendMessageToAll(string msg){
	int msgSize = msg.length();
	msg[msgSize] = '\0';
	for(int i = 0;i < socketSize;i++){
		if(SOCK_Con[i] != 0)
			send(SOCK_Con[i],msg.c_str(),msgSize + 1,NULL);
	}
}
/*******************CLIENT**************************/
Client::Client(){
	Version = MAKEWORD(2,2);
	error = WSAStartup(Version,&wsa);
	AdressSize = sizeof(Adress);
	connected = false;
}
void Client::setAdress(string targetIp,int port){
	SOCK_Connection = socket(AF_INET,SOCK_STREAM,NULL);

	Adress.sin_family = AF_INET;
	Adress.sin_port = htons(port);
	Adress.sin_addr.s_addr = inet_addr(targetIp.c_str());

}
bool Client::connectToServer(){
	if(!connected){
	if(error = connect(SOCK_Connection,(SOCKADDR*)&Adress,AdressSize)) {
		sendMessage("My Name Is Emre ");
		connected = true;	
	}
	return connected;
	}
	else return true;
}
void Client::runClient(){
  char Data[1024];
	int activity,i;
	for(i = 0;i < 1024;i++) Data[i] ='\0';
	i = 0;
	    FD_ZERO(&readset);
		FD_SET(SOCK_Connection,&readset);
		if(select(0,&readset,NULL,NULL,NULL) == SOCKET_ERROR)error = WSAGetLastError();

		if(FD_ISSET(SOCK_Connection,&readset)){//if there is an something
			activity = recv(SOCK_Connection,Data,1024,NULL);
			if(activity == SOCKET_ERROR){
					if(WSAGetLastError() == WSAECONNRESET){//disconnect
						disconnect();
						messages.push_back(new Message("DISC\0",i,INTERNET_DISCONNECTED));
					}
					else cout << "Cant Recv";
				}
				if(activity == 0){
					disconnect();
					messages.push_back(new Message("DISC\0",i,INTERNET_DISCONNECTED));
				}
				else{
				Data[activity] = '\0';
				messages.push_back(new Message(Data,i,INTERNET_RECEVING));
				}

		}//FD_ISSET IF
}
void Client::sendMessage(string message){
	int msgSize = message.length();
	if(SOCK_Connection != 0)
	send(SOCK_Connection,message.c_str(),msgSize,NULL);
}
void Client::disconnect(){
	connected = false;
	closesocket(SOCK_Connection);
	WSACleanup();
}