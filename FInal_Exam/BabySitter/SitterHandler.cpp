#include "SitterHandler.h"

void SitterHandler::LoginMenu() {		//베이비시터가 로그인을 할지 회원가입을 할지 선택하는 메뉴
	Sitter sitter;	//Sitter 객체를 생성한다.
	int login;		//메뉴 입력시 입력받은 정보를 저장하기 위한 변수 선언
	
	cout << endl << "메뉴 입력:(1.로그인 2.회원가입)==>";		// "메뉴 입력:(1.로그인 2.회원가입)==>"을 출력한다.
	cin >> login;		//입력받은 값을 login에 저장한다.
	if (login == 1) {	//입력받은 값이 1이라면 실행
		sitter.Login();	//Sitter클래스의 Login()함수가 실행된다.
	}
	else if (login == 2) {	//입력받은 값이 2라면 실행
		sitter.Join();		//Sitter클래스의 Join()함수가 실행된다.
		sitter.Set();		//Sitter클래스의 Set()함수가 실행된다.
		LoginMenu();	//SitterHandler클래스의 LoginMenu()가 실행되어 다시 로그인을 할 것인지 회원가입을 할것인지에 대해 묻는다.
	}
	else {		//입력받은값이 1이나 2 이외의 값이 입력 받을 경우 실행
		cout << "=====메뉴를 잘못 선택 하였습니다=====" << endl;		//"=====메뉴를 잘못 선택 하였습니다====="를 출력한다.
		LoginMenu();		//SitterHandler클래스의 LoginMenu()가 실행되어 다시 로그인을 할 것인지 회원가입을 할것인지에 대해 묻는다.
	}



}


SitterHandler::SitterHandler()
{
}


SitterHandler::~SitterHandler()
{
}
