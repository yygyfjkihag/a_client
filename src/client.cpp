/*
 * client.cpp
 *
 *  Created on: 2017��3��10��
 *      Author: yygyfjkihag
 */
#include <iostream>
#include "A_client.h"

/*******************************************
 * �ڱ����з��������ȡ���ͻ�Ϊ����IP���˿����
 * �����������IP����ָ��Ҳ�������
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



