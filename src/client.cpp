/*
 * client.cpp
 *
 *  Created on: 2017年3月10日
 *      Author: yygyfjkihag
 */
#include <iostream>
#include "A_client.h"

/*******************************************
 * 在本例中服务器会获取到客户为本地IP，端口随机
 * 服务器自身的IP可以指定也可以随机
 * *****************************************/
const char* serverIp = "127.0.0.2";
const unsigned short serverPort = 8700;
int main(){
	int sflag=0;
	A_client client;
	client.conn(serverIp, serverPort);
	while(true) {
		sflag = client.sendMsg();

		if(1==sflag){
			client.recvMsg();
			continue;
		}
		if(-1==sflag)
			continue;
		if(-2==sflag){
			client.close();
			cout<<"CLIEnt OVER."<<endl;
			break;
		}
	}
	cout<<"MAIN OVER."<<endl;
	return 0;
}



