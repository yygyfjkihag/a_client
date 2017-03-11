/*
 * client.cpp
 *
 *  Created on: 2017Äê3ÔÂ10ÈÕ
 *      Author: yygyfjkihag
 */
#include <iostream>
#include "A_client.h"

const char* serverIp = "127.0.0.1";
int main(){
	A_client client;
	client.conn(serverIp, 8700);
	while(true){
		client.sendMsg();
		client.recvMsg();
	}
	client.close();
	return 0;
}



