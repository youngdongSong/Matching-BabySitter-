#include "MainHandler.h"


void MainHandler::StartMenu() {
	int input;	//�޴��� �Է¹��� ����
	ParentHandler p;	//ParentHandler ��ü ����
	SitterHandler s;	//SitterHandler ��ü ����
	cout << "1.�θ� 2.���̺����==>";
	cin >> input;	//�Է¹��� ���� ������ ����
	
	if (input == 1) {	//1�� �Է� �޾��� ��� ����
		p.LoginMenu();	//�θ��� �α��� �޴� ȭ�� ����
	}
	else if (input == 2) {	//2�� �Է� �޾��� ��� ����
		s.LoginMenu();	//���̺������ �α��� �޴� ȭ�� ����
	}
}
MainHandler::MainHandler()
{
}


MainHandler::~MainHandler()
{
}
