// CMakeProject1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <inaddr.h>
#include <locale>
#include <string>
#include <stdlib.h>
#include <cstddef>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

vector<vector<char>> buf;
vector<vector<char>> message_buf;
mutex buf_mutex;

SOCKET ClientSockGlobal;
bool conn_client = false;

int connecting_to_server() {

	const char SERVER_IP[] = "127.0.0.1";
	const short SERVER_PORT_NUM = 1;
	const short BUFF_SIZE = 1024;

	int erStat;

	in_addr ip_to_num;
	inet_pton(AF_INET, SERVER_IP, &ip_to_num);



	WSADATA wsData;
	erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

	if (erStat != 0) {
		cout << WSAGetLastError();
		return 1;
	}


	SOCKET ClientSock = socket(AF_INET, SOCK_STREAM, 0);

	if (ClientSock == INVALID_SOCKET) {
		closesocket(ClientSock);
		WSACleanup();
		return 1;
	}

	// Establishing a connection to Server
	sockaddr_in servInfo;

	ZeroMemory(&servInfo, sizeof(servInfo));

	servInfo.sin_family = AF_INET;
	servInfo.sin_addr = ip_to_num;
	servInfo.sin_port = htons(SERVER_PORT_NUM);

	erStat = connect(ClientSock, (sockaddr*)&servInfo, sizeof(servInfo));

	if (erStat != 0) {
		closesocket(ClientSock);
		WSACleanup();
		return 1;
	}

	ClientSockGlobal = ClientSock;
	conn_client = true;
	return 0;
}

void disconnecting() {
	closesocket(ClientSockGlobal);
	WSACleanup();
	conn_client = false;
}

vector<char> change_string(vector<char> s) {
	vector<char> new_s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] % 2 == 0) {
			new_s.push_back('K');
			new_s.push_back('B');
		}
		else {
			new_s.push_back(s[i]);
		}
	}
	return new_s;
}

bool check_string(vector<char> s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' < 0 || s[i] - '0' > 9) return false;
	}
	return true;
}

vector<char> sort(vector<char> s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size() - i - 1; j++) {
			if (s[j] < s[j + 1]) {
				int temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
	return s;
}

void func1() {

	string str;
	cin >> str;
	vector<char> s(str.begin(), str.end());

	if (s.size() <= 64 && check_string(s)) {
		s = change_string(sort(s));

		buf_mutex.lock();
		buf.push_back(s);
		buf_mutex.unlock();
	}
}

vector <char> int_to_vector_char(int num) {
	vector<char> str_num;
	str_num.clear();
	while (num != 0) {
		str_num.insert(str_num.begin(), char(num % 10 + '0'));
		num = num / 10;
	}
	return str_num;
}

void func2() {



	while (!buf.empty()) {
		vector<char> s;

		buf_mutex.lock();
		s = buf.back();
		buf.pop_back();
		buf_mutex.unlock();

		for (int i = 0; i < s.size(); i++) cout << s[i];
		cout << endl;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
				sum += s[i] - '0';
			}
		}

		vector<char> mess = int_to_vector_char(sum);

		message_buf.push_back(mess);
		int packet_size;
		while (!message_buf.empty()) {
			vector<char> curr_mess = message_buf.back();
			message_buf.pop_back();
			Sleep(100);
			if (!conn_client) {
				if (connecting_to_server() == 0) {
					packet_size = send(ClientSockGlobal, curr_mess.data(), curr_mess.size(), 0);
					if (packet_size == SOCKET_ERROR) {
						message_buf.push_back(curr_mess);
						disconnecting();
						break;
					}
				}
				else {
					message_buf.push_back(curr_mess);
					break;
				}
			}
			else {
				packet_size = send(ClientSockGlobal, curr_mess.data(), curr_mess.size(), 0);
				if (packet_size == SOCKET_ERROR) {
					message_buf.push_back(curr_mess);
					disconnecting();
					break;
				}
			}
		}
	}
}
