#include "MainHandler.h"


void MainHandler::StartMenu() {
	int input;	//메뉴를 입력받을 변수
	ParentHandler p;	//ParentHandler 객체 생성
	SitterHandler s;	//SitterHandler 객체 생성
	cout << "1.부모 2.베이비시터==>";
	cin >> input;	//입력받은 값을 변수에 저장
	
	if (input == 1) {	//1을 입력 받았을 경우 실행
		p.LoginMenu();	//부모의 로그인 메뉴 화면 실행
	}
	else if (input == 2) {	//2를 입력 받았을 경우 실행
		s.LoginMenu();	//베이비시터의 로그인 메뉴 화면 실행
	}
}
MainHandler::MainHandler()
{
}


MainHandler::~MainHandler()
{
}
