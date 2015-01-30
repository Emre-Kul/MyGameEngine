#ifndef INTERNET_H
#define INTERNET_H

#define SCK_VERSION2 0X0202
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <vector>

using namespace std;


const int INTERNET_DISCONNECTED = 0;
const int INTERNET_CONNECTED = 1;
const int INTERNET_RECEVING = 2;

struct Message{
	string message;
	int socketIndex,stat;
	Message(string msg,int index,int status){message = msg;socketIndex = index;stat = status;}
	Message();
};

class Server{
	fd_set readset;
	WSAData wsa;
	WORD Version;
	SOCKADDR_IN Adress;
	SOCKET SOCK_Listen,SOCK_Connection;
	SOCKET *SOCK_Con;
	int AdressSize,error,index,socketSize;
public:
	vector <Message*> messages;
	Server();
	void setAdress(int portNumber,int maxSize);
	void runServer();
	
	void sendMessage(string msg,int socketId);
	void sendMessageToAll(string msg);

	vector <Message*>& getMessageList(){return messages;}
	int getLastError(){return error;}	

};

class Client{
	fd_set readset;
	WORD Version;
	WSADATA wsa;
	SOCKET SOCK_Connection;
	SOCKADDR_IN Adress;
	int AdressSize,error;
	
public:
	vector <Message*> messages;
	bool connected;
	Client();
	void setAdress(string targetIp,int port);
	bool connectToServer();
	void runClient();
	void sendMessage(string message);
	void disconnect();
	void getMessages();
	int getErrorCode(){return error;}
};

#endif