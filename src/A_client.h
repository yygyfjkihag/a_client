/*
 * A_client.h
 *
 *  Created on: 2017Äê3ÔÂ10ÈÕ
 *      Author: yygyfjkihag
 */

#ifndef A_CLIENT_H_
#define A_CLIENT_H_

#include <stdio.h>
#include <WinSock2.h>
#include <iostream>
#include <string.h>
using namespace std;

class A_client {
private:
	SOCKET sock;
	char recv_buf[512];
	char send_buf[256];
public:
	A_client();
	bool socketBoost();
	bool conn(const char* serverIp,const unsigned short serverPort);
	int sendMsg();
	int recvMsg();
	void close();
	~A_client(){};
};

#endif /* A_CLIENT_H_ */
