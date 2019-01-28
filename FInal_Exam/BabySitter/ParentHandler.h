#pragma once
#include"Parent.h"

#include<iostream>	//파일 처리를 하기 위한 헤더
#include<vector>	//벡터를 사용하기 위한 헤더
#include<string>	//string 함수 ex)strcpy, strcat,strtok 함수를 사용하기 위한 헤더
using namespace std;
class ParentHandler
{
	
public:
	ParentHandler();			
	static void LoginMenu();	//부모가 로그인을 할지 회원가입을 할지 선택하는 메뉴 함수이다.
	
	~ParentHandler();
};

