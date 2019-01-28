#pragma once

#include"SitterHandler.h"
#include"MainHandler.h"
#include<fstream>	//파일 처리를 하기 위한 헤더 파일
#include<iostream>	//파일 처리를 하기 위한 헤더 파일
#include<unordered_map>//unordered_map을 사용하기 위한 헤더파일
using namespace std;
class Sitter
{
	string id;			//이름을 위한 필드
	string pwd;			//패스워드를 위한 필드
	string name;		//이름을 위한 필드
	string age;			//나이을 위한 필드
	string sex;			//성별을 위한 필드
	string time;		//일할 시간을 위한 필드
	string specialty;	//특기을 위한 필드
	string number;		//연락처를 위한 필드
public:
	void SetId(string id) { this->id = id; }							 //아이디를 입력받받아 저장하기 위한 set함수
	void SetPwd(string pwd) { this->pwd = pwd; }						//패스워드를 입력받받아 저장하기 위한 set함수
	void SetName(string name) { this->name = name; }					//이름를 입력받받아 저장하기 위한 set함수
	void SetAge(string age) { this->age = age; }						//나이를 입력받받아 저장하기 위한 set함수
	void SetSex(string sex) { this->sex = sex; }						//성별를 입력받받아 저장하기 위한 set함수
	void SetTime(string time) { this->time = time; }					//일할 시간를 입력받받아 저장하기 위한 set함수
	void SetSpecialty(string specialty) { this->specialty = specialty; }//특기를 입력받받아 저장하기 위한 set함수
	void SetNumber(string number) { this->number = number; }			//연락처를 입력받받아 저장하기 위한 set함수

	string GetId() { return id; }					//아이디의 정보를 리턴할 get함수
	string GetPwd() { return pwd; }					//패스워드의 정보를 리턴할 get함수
	string GetName() { return name; }				//이름의 정보를 리턴할 get함수
	string GetAge() { return age; }					//나이의 정보를 리턴할 get함수
	string GetSex() { return sex; }					//성별의 정보를 리턴할 get함수
	string GetTime() { return time; }				//일할 시간의 정보를 리턴할 get함수
	string GetSpecialty() { return specialty; }		//특기의 정보를 리턴할 get함수
	string GetNumber() { return number; }			//연락처의 정보를 리턴할 get함수

	void Join();		//베이비시터가 회원가입을 메뉴를 선택할 경우 실행 되는 함수
	void Set();			//베이비시터가 회원가입으로 입력받은 정보를 파일에 저장하기 위한 함수
	void Login();		//베이비시터가 로그인을 하면 입력받은 아이디와 패스워드를 비교하여 로그인을 할 수 있는 함수
	void Show();		//부모와 아이의 정보를 보여주는 함수
	void Chatting();	//공지를 띄어주는 함수
	Sitter();
	~Sitter();
};

