#pragma warning(disable:4996)
#include "ParentHandler.h"



ParentHandler::ParentHandler()
{

}

void ParentHandler::LoginMenu() {
	Parent parent;	//Parent ��ü ����	
	int login;		//�Է¹��� �޴� ������ �����ϱ� ���� ���� ����
	
	cout << endl << "�޴� �Է�:(1.�α��� 2.ȸ������)==>";
		cin >> login;	//�Է¹��� ���� login ������ ����
		if (login == 1) {	//�Է¹��� ���� 1�� ��� ����
			parent.Login();	//ParentŬ������ Login()�Լ��� �����Ѵ�.
		}
		else if (login == 2) {	//�Է¹��� ���� 2�� ��� ����
			parent.Join();	//ParentŬ������ Join()�Լ��� �����Ѵ�. (ȸ������)
			parent.Set();	//ParentŬ������ Set()�Լ��� �����Ѵ�. (ȸ�����Խ� �ۼ��� ������ ���Ͽ� �����ϴ� �Լ�)
			ParentHandler::LoginMenu();	//ParentHandlerŬ������ �����Լ��� LoginMenu()�Լ��� �����Ѵ�.	
		}
		else {
			cout << "=====�޴��� �߸� ���� �Ͽ����ϴ�=====" << endl;
			ParentHandler::LoginMenu();	//ParentHandlerŬ������ �����Լ��� LoginMenu()�Լ��� �����Ѵ�.	
		}
	
		
	
}




ParentHandler::~ParentHandler()
{
	
}
