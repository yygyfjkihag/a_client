//============================================================================
// Name        : A_client.cpp
// Author      : Monday
// Version     :
// Copyright   : yygyfjkihag
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "A_client.h"

A_client::A_client(){
	init();

	/**
	 * test port
	 */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if ( INVALID_SOCKET == sock) cout<<"Clint socket creates err."<<endl;
}
int A_client::init() {
	WORD wVerReq = MAKEWORD(1, 1);
	WSADATA wsaData;
	int err = WSAStartup(wVerReq, &wsaData);
	if (0 != err) {
		cout << "Client-WSAStartup failed. Return:" << err << endl;
		return -1;
	}

	if (wsaData.wVersion != wVerReq) {
		cout << "Client-wsaData.wVersion: " << wsaData.wVersion
				<< " is not equal to wVerReq: " << wVerReq << endl;
		WSACleanup();
		return -2;
	}
	return 1;
}
int A_client::conn(const char* serverIp, const unsigned short serverPort) {

	SOCKADDR_IN addr_server;
	addr_server.sin_family = AF_INET;
	addr_server.sin_port = htons(serverPort);
	addr_server.sin_addr.S_un.S_addr = inet_addr(serverIp);
	int err;

	if ( INVALID_SOCKET == sock) {
		cout << "Client-socket error: " << WSAGetLastError() << endl;
		return -3;
	}

	err = connect(sock, (SOCKADDR*) &addr_server, sizeof(addr_server));

	if ( SOCKET_ERROR == err) {
		cout << "Client-connect error: " << WSAGetLastError() << endl;
		return -4;
	}
	cout << "Client:Connection established." << endl;
	return 1;
}

int A_client::sendMsg() {
	int err;
	cin.getline(send_buf, 256);
	cin.clear();
	if (0 == strcmp(send_buf, "quit") || 0 == strcmp(send_buf, "exit"))
		return -1;
	else {
	err = send(sock, send_buf, strlen(send_buf) + 1, 0);

	if ( SOCKET_ERROR == err) {
		cout << "Client-send error: " << WSAGetLastError() << endl;
		return -2;
	}
	return 1;
	}
}

int A_client::recvMsg() {
	int err;
	err = recv(sock, recv_buf, sizeof(recv_buf), 0);
	if (err <= 0) {
		cout << "Client-recv error: " << WSAGetLastError() << endl;
		return -1;
	}
	cout << "Client:";
	cout << recv_buf << endl;
	return 1;
}

void A_client::close() {
	int err = closesocket(sock);
	if ( SOCKET_ERROR == err) {
		cout << "Client-closeSocket error: " << WSAGetLastError() << endl;
	}
	WSACleanup();
}

A_client::~A_client(){}
