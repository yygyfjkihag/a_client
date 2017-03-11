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
	while(true) {
		switch(client.sendMsg()){
		case -1:
			continue;
		case -2:
			break;
		case 1:
			break;
		default :
			break;
		}
		switch(client.recvMsg()){
		case -1:
			break;
		case 1:
			break;
		default:
			break;
		}
	}
	client.close();
	return 0;
}



