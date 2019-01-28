#pragma once

#include"ParentHandler.h"
#include"MainHandler.h"
#include<iostream>		//���� ó�� �ϱ� ���� ���
#include<string>		//string �Լ��� ����ϱ� ���� �ش�
#include<unordered_map>	//unordered_map�� ����ϱ� ���� ���



using namespace std;
class Parent
{
	string id;				//�̸��� ���� �ʵ�
	string pwd;				//�н����带 ���� �ʵ�
	string name;			//�̸��� ���� �ʵ�
	string age;				//������ ���� �ʵ�
	string sex;				//������ ���� �ʵ�
	string child_name;		//������ �̸��� ���� �ʵ�
	string child_sex;		//������ ������ ���� �ʵ�
	string child_age;		//������ ���̸� ���� �ʵ�
	string number;			//����ó�� ���� �ʵ�
		
public:
	Parent();
	void setID(string id) { this->id = id;}										//���̵� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setPwd(string pwd) { this->pwd = pwd; }								//�н����带 �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setName(string name) { this->name = name; }							//�̸��� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setAge(string age) { this->age = age; }								//���̸� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setSex(string sex) { this->sex = sex; }								//������ �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setChild_name(string child_name) { this->child_name = child_name; }	//������ �̸��� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setChild_sex(string child_sex) { this->child_sex = child_sex; }		//������ ������ �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setChild_age(string age) { this->child_age = child_age; }				//������ ���̸� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void setNumber(string number) { this->number = number; }					//����ó�� �Է¹޹޾� �����ϱ� ���� set�Լ�

	string getID() { return id; }						//���̵��� ������ ������ get�Լ�
	string getPwd() { return pwd; }						//�н������� ������ ������ get�Լ�
	string getName() { return name; }					//�̸��� ������ ������ get�Լ�
	string getAge() { return age; }						//������ ������ ������ get�Լ�
	string getSex() { return sex; }						//������ ������ ������ get�Լ�
	string getChild_name() { return child_name; }		//������ �̸��� ������ ������ get�Լ�
	string getChild_sex() { return child_sex; }			//������ ������ ������ ������ get�Լ�
	string getChild_age() { return child_age; }			//������ ������ ������ ������ get�Լ�
	string getNumber() { return number; }				//����ó�� ������ ������ get�Լ�

	void Join();		//�θ� ȸ�� ���Խ� ȣ��Ǵ� �Լ�
	void Set();			//�θ� ȸ�� ���Խ� �ۼ��� ������ ���Ͽ� �����ϴ� �Լ�
	void Login();		//������ ������ �о �Է¹��� ���̵� ���� �н����� ���� ���Ͽ� �α��� �ϴ� �Լ�
	void Show();		//���̺������ ������ �����ִ� �Լ�
	void Favorites();	//���ã�� ����� �ϴ� �Լ�
	void Chatting();	//������ ���� �Լ�
	~Parent();
	
	
};

