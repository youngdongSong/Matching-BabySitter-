#pragma once
#include"Parent.h"

#include<iostream>	//���� ó���� �ϱ� ���� ���
#include<vector>	//���͸� ����ϱ� ���� ���
#include<string>	//string �Լ� ex)strcpy, strcat,strtok �Լ��� ����ϱ� ���� ���
using namespace std;
class ParentHandler
{
	
public:
	ParentHandler();			
	static void LoginMenu();	//�θ� �α����� ���� ȸ�������� ���� �����ϴ� �޴� �Լ��̴�.
	
	~ParentHandler();
};

