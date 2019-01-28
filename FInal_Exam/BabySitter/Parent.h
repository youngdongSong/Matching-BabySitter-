#pragma once

#include"ParentHandler.h"
#include"MainHandler.h"
#include<iostream>		//파일 처리 하기 위한 헤더
#include<string>		//string 함수를 사용하기 위한 해더
#include<unordered_map>	//unordered_map을 사용하기 위한 헤더



using namespace std;
class Parent
{
	string id;				//이름을 위한 필드
	string pwd;				//패스워드를 위한 필드
	string name;			//이름을 위한 필드
	string age;				//나이을 위한 필드
	string sex;				//성별을 위한 필드
	string child_name;		//아이의 이름을 위한 필드
	string child_sex;		//아이의 성별을 위한 필드
	string child_age;		//아이의 나이를 위한 필드
	string number;			//연락처를 위한 필드
		
public:
	Parent();
	void setID(string id) { this->id = id;}										//아이디를 입력받받아 저장하기 위한 set함수
	void setPwd(string pwd) { this->pwd = pwd; }								//패스워드를 입력받받아 저장하기 위한 set함수
	void setName(string name) { this->name = name; }							//이름을 입력받받아 저장하기 위한 set함수
	void setAge(string age) { this->age = age; }								//나이를 입력받받아 저장하기 위한 set함수
	void setSex(string sex) { this->sex = sex; }								//성별를 입력받받아 저장하기 위한 set함수
	void setChild_name(string child_name) { this->child_name = child_name; }	//아이의 이름을 입력받받아 저장하기 위한 set함수
	void setChild_sex(string child_sex) { this->child_sex = child_sex; }		//아이의 성별을 입력받받아 저장하기 위한 set함수
	void setChild_age(string age) { this->child_age = child_age; }				//아이의 나이를 입력받받아 저장하기 위한 set함수
	void setNumber(string number) { this->number = number; }					//연락처를 입력받받아 저장하기 위한 set함수

	string getID() { return id; }						//아이디의 정보를 리턴할 get함수
	string getPwd() { return pwd; }						//패스워드의 정보를 리턴할 get함수
	string getName() { return name; }					//이름의 정보를 리턴할 get함수
	string getAge() { return age; }						//나이의 정보를 리턴할 get함수
	string getSex() { return sex; }						//성별의 정보를 리턴할 get함수
	string getChild_name() { return child_name; }		//아이의 이름의 정보를 리턴할 get함수
	string getChild_sex() { return child_sex; }			//아이의 성별의 정보를 리턴할 get함수
	string getChild_age() { return child_age; }			//아이의 나이의 정보를 리턴할 get함수
	string getNumber() { return number; }				//연락처의 정보를 리턴할 get함수

	void Join();		//부모가 회원 가입시 호출되는 함수
	void Set();			//부모가 회원 가입시 작성한 내용을 파일에 저장하는 함수
	void Login();		//파일의 정보를 읽어서 입력받은 아이디 값과 패스워드 값을 비교하여 로그인 하는 함수
	void Show();		//베이비시터의 정보를 보여주는 함수
	void Favorites();	//즐겨찾기 기능을 하는 함수
	void Chatting();	//공지를 보는 함수
	~Parent();
	
	
};

