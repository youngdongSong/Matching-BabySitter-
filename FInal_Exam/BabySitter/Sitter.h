#pragma once

#include"SitterHandler.h"
#include"MainHandler.h"
#include<fstream>	//���� ó���� �ϱ� ���� ��� ����
#include<iostream>	//���� ó���� �ϱ� ���� ��� ����
#include<unordered_map>//unordered_map�� ����ϱ� ���� �������
using namespace std;
class Sitter
{
	string id;			//�̸��� ���� �ʵ�
	string pwd;			//�н����带 ���� �ʵ�
	string name;		//�̸��� ���� �ʵ�
	string age;			//������ ���� �ʵ�
	string sex;			//������ ���� �ʵ�
	string time;		//���� �ð��� ���� �ʵ�
	string specialty;	//Ư���� ���� �ʵ�
	string number;		//����ó�� ���� �ʵ�
public:
	void SetId(string id) { this->id = id; }							 //���̵� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetPwd(string pwd) { this->pwd = pwd; }						//�н����带 �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetName(string name) { this->name = name; }					//�̸��� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetAge(string age) { this->age = age; }						//���̸� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetSex(string sex) { this->sex = sex; }						//������ �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetTime(string time) { this->time = time; }					//���� �ð��� �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetSpecialty(string specialty) { this->specialty = specialty; }//Ư�⸦ �Է¹޹޾� �����ϱ� ���� set�Լ�
	void SetNumber(string number) { this->number = number; }			//����ó�� �Է¹޹޾� �����ϱ� ���� set�Լ�

	string GetId() { return id; }					//���̵��� ������ ������ get�Լ�
	string GetPwd() { return pwd; }					//�н������� ������ ������ get�Լ�
	string GetName() { return name; }				//�̸��� ������ ������ get�Լ�
	string GetAge() { return age; }					//������ ������ ������ get�Լ�
	string GetSex() { return sex; }					//������ ������ ������ get�Լ�
	string GetTime() { return time; }				//���� �ð��� ������ ������ get�Լ�
	string GetSpecialty() { return specialty; }		//Ư���� ������ ������ get�Լ�
	string GetNumber() { return number; }			//����ó�� ������ ������ get�Լ�

	void Join();		//���̺���Ͱ� ȸ�������� �޴��� ������ ��� ���� �Ǵ� �Լ�
	void Set();			//���̺���Ͱ� ȸ���������� �Է¹��� ������ ���Ͽ� �����ϱ� ���� �Լ�
	void Login();		//���̺���Ͱ� �α����� �ϸ� �Է¹��� ���̵�� �н����带 ���Ͽ� �α����� �� �� �ִ� �Լ�
	void Show();		//�θ�� ������ ������ �����ִ� �Լ�
	void Chatting();	//������ ����ִ� �Լ�
	Sitter();
	~Sitter();
};

