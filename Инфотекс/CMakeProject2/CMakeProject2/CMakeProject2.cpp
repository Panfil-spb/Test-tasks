#include <WinSock2.h>
#include <WS2tcpip.h>
#include "CMakeProject2.h"
#pragma comment(lib, "Ws2_32.lib")

using namespace std;



int main(void)
{
	const char IP_SERV[] = "127.0.0.1";
	const int PORT_NUM = 1;
	const short BUFF_SIZE = 1024;


	int erStat;

	in_addr ip_to_num;
	erStat = inet_pton(AF_INET, IP_SERV, &ip_to_num);

	if (erStat <= 0) {
		cout << "Error in IP translation to special numeric format" << endl;
		return 1;
	}


	WSADATA wsData;

	erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

	if (erStat != 0) {
		cout << "Error WinSock version initializaion #";
		cout << WSAGetLastError();
		return 1;
	}
	else
		cout << "WinSock initialization is OK" << endl;

	SOCKET ServSock = socket(AF_INET, SOCK_STREAM, 0);

	if (ServSock == INVALID_SOCKET) {
		cout << "Error initialization socket # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		WSACleanup();
		return 1;
	}
	else
		cout << "Server socket initialization is OK" << endl;


	sockaddr_in servInfo;
	ZeroMemory(&servInfo, sizeof(servInfo));

	servInfo.sin_family = AF_INET;
	servInfo.sin_addr = ip_to_num;
	servInfo.sin_port = htons(PORT_NUM);

	erStat = bind(ServSock, (sockaddr*)&servInfo, sizeof(servInfo));

	if (erStat != 0) {
		cout << "Error Socket binding to server info. Error # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		WSACleanup();
		return 1;
	}
	else
		cout << "Binding socket to Server info is OK" << endl;

	erStat = listen(ServSock, SOMAXCONN);

	if (erStat != 0) {
		cout << "Can't start to listen to. Error # " << WSAGetLastError() << endl;
		closesocket(ServSock);
		WSACleanup();
		return 1;
	}
	else
		cout << "Listening..." << endl;



	while (true) {
		sockaddr_in clientInfo;
		ZeroMemory(&clientInfo, sizeof(clientInfo));

		int clientInfo_size = sizeof(clientInfo);

		SOCKET ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

		if (ClientConn == INVALID_SOCKET) {
			cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << endl;
			closesocket(ServSock);
			closesocket(ClientConn);
			WSACleanup();
			return 1;
		}
		else {
			cout << "Connection to a client established successfully" << endl;
			char clientIP[22];

			inet_ntop(AF_INET, &clientInfo.sin_addr, clientIP, INET_ADDRSTRLEN);

			cout << "Client connected with IP address " << clientIP << endl;

		}

		while (true) {
			vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);
			short packet_size = 0;
			packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);
			if (packet_size == SOCKET_ERROR) {
				break;
			}
			cout << "Client's message: ";
			int ans = check_buff(servBuff);

			if (ans == 0)
				cout << servBuff.data() << endl;
			else if (ans == 1)
				cout << "ERROR <Message from user is not a multiple of 32>" << endl;
			else
				cout << "ERROR <Message from user less than two characters>" << endl;

			clean_buff(servBuff);
		}
	}

	return 0;
}