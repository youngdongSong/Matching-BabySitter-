#include "SitterHandler.h"

void SitterHandler::LoginMenu() {		//���̺���Ͱ� �α����� ���� ȸ�������� ���� �����ϴ� �޴�
	Sitter sitter;	//Sitter ��ü�� �����Ѵ�.
	int login;		//�޴� �Է½� �Է¹��� ������ �����ϱ� ���� ���� ����
	
	cout << endl << "�޴� �Է�:(1.�α��� 2.ȸ������)==>";		// "�޴� �Է�:(1.�α��� 2.ȸ������)==>"�� ����Ѵ�.
	cin >> login;		//�Է¹��� ���� login�� �����Ѵ�.
	if (login == 1) {	//�Է¹��� ���� 1�̶�� ����
		sitter.Login();	//SitterŬ������ Login()�Լ��� ����ȴ�.
	}
	else if (login == 2) {	//�Է¹��� ���� 2��� ����
		sitter.Join();		//SitterŬ������ Join()�Լ��� ����ȴ�.
		sitter.Set();		//SitterŬ������ Set()�Լ��� ����ȴ�.
		LoginMenu();	//SitterHandlerŬ������ LoginMenu()�� ����Ǿ� �ٽ� �α����� �� ������ ȸ�������� �Ұ������� ���� ���´�.
	}
	else {		//�Է¹������� 1�̳� 2 �̿��� ���� �Է� ���� ��� ����
		cout << "=====�޴��� �߸� ���� �Ͽ����ϴ�=====" << endl;		//"=====�޴��� �߸� ���� �Ͽ����ϴ�====="�� ����Ѵ�.
		LoginMenu();		//SitterHandlerŬ������ LoginMenu()�� ����Ǿ� �ٽ� �α����� �� ������ ȸ�������� �Ұ������� ���� ���´�.
	}



}


SitterHandler::SitterHandler()
{
}


SitterHandler::~SitterHandler()
{
}
