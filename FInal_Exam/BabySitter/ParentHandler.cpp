#pragma warning(disable:4996)
#include "ParentHandler.h"



ParentHandler::ParentHandler()
{

}

void ParentHandler::LoginMenu() {
	Parent parent;	//Parent 객체 생성	
	int login;		//입력받은 메뉴 정보를 저장하기 위한 변수 선언
	
	cout << endl << "메뉴 입력:(1.로그인 2.회원가입)==>";
		cin >> login;	//입력받은 값을 login 변수에 저장
		if (login == 1) {	//입력받은 값이 1인 경우 실행
			parent.Login();	//Parent클래스의 Login()함수를 실행한다.
		}
		else if (login == 2) {	//입력받은 값이 2인 경우 실행
			parent.Join();	//Parent클래스의 Join()함수를 실행한다. (회원가입)
			parent.Set();	//Parent클래스의 Set()함수를 실행한다. (회원가입시 작성된 정보를 파일에 저장하는 함수)
			ParentHandler::LoginMenu();	//ParentHandler클래스의 정적함수인 LoginMenu()함수를 실행한다.	
		}
		else {
			cout << "=====메뉴를 잘못 선택 하였습니다=====" << endl;
			ParentHandler::LoginMenu();	//ParentHandler클래스의 정적함수인 LoginMenu()함수를 실행한다.	
		}
	
		
	
}




ParentHandler::~ParentHandler()
{
	
}
