#pragma warning(disable:4996)
#include"Parent.h"

using namespace std;

Parent::Parent() {}
void Parent::Show() {	//베이비 시터의 정보를 보여주는 함수
	string line;		//파일에서 한줄 씩
	
	int input;	//메뉴에서 입력받은 내용을 저장할 변수
	unordered_map<string, string> map2;		//unordered_map 객체 <string,strng>으로 제너릭된 map2를 생성
	ifstream in("sitterInfo.txt", ios::in);	//sitterInfo.txt를 읽기 모드로 열기
	if (in.is_open() == false)	//열기 실패시 실행
		cout << "파일 열기 실패";
	else {	//열기에 성공할 경우 실행
		cout << "=====베이비 시터 정보=====" << endl;
		cout << "    연락처    이름 나이 성별 가능시간 특기 순"<<endl<<endl;
		while (true) {	//무한 반복문 실행
			getline(in, line);	//파일에서 한 줄 씩 읽은 내용을 변수 line에 저장	
			cout << line << endl;	//한 줄 씩 출력
			if (in.eof())break;	//파일의 내용을 끝까지 읽으면 반복문 종료
			
		}
		cout << endl;
		cout << "1.시작화면 2.즐겨찾기 3.채팅 4.종료 ==>";
		cin >> input;	//메뉴를 입력받아 변수 input에 저장
		if (input == 1)	//1을 입력 받았을 경우 실행
			MainHandler::StartMenu();	//프로그램 시작할 때의 메뉴 선택하는 함수 실행

		else if (input == 2)	//2를 입력 받았을 경우 실행
			this->Favorites();	//즐겨찾기 기능을 하는 Favorites()함수 실행

		else if (input == 3)	//3을 입력 받았을 경우 실행
			this->Chatting();	//채팅 기능을 하는 Chatting() 함수 실행

		else if (input == 4)	//4를 입력 받았을 경우 실행
			exit(0);	//프로그램을 종료한다.
		

		in.close();	//파일을 닫는다.
	}
}
void Parent::Favorites() {	//즐겨찾기 기능을 하는 함수	
	int input;		//즐겨찾기를 추가, 즐겨찾기 보기 중 입력받은 내용을 저장 하는 변수
	int	input3;		//시작화면, 즐겨찾기,.채팅, 종료 중 입력받은 내용을 저장 하는 변수
	int input2;		//시작화면, 즐겨찾기 화면, 종료 중 입력받은 내용을 저장 하는 변수
	char number[15];	//파일에서 읽은 연락처 내용을 저장하는 char형 배열 변수
	char name[7];		//파일에서 읽은 이름 내용을 저장하는 char형 배열 변수
	char age[5];		//파일에서 읽은 나이 내용을 저장하는 char형 배열 변수
	char sex[20];		//파일에서 읽은 성별 내용을 저장하는 char형 배열 변수
	char time[100];		//파일에서 읽은 일할 시간 내용을 저장하는 char형 배열 변수
	char specialty[50];//파일에서 읽은 특기 내용을 저장하는 char형 배열 변수
	string result;		//파일에서 읽은 내용을 string형 변수 result에 모두 넣기 위해 생성
	string fname;		//즐겨찾기 추가 시 베이비시터의 이름을 입력받기위해 사용될 변수
	string line;		//파일에서 한 줄 씩 읽어 저장될 변수
	unordered_map<string, string> map2;		//unordered_map 객체 <string,strng>으로 제너릭된 map2를 생성
	
	cout << "1.즐겨찾기 추가 2.즐겨찾기 보기==>";
	cin >> input;	//입력받은 내용을 input에 저장

	if (input == 1) {	//1을 입력 받을 경우 실행
		ifstream in("sitterInfo.txt", ios::in);	//sitterInfo.txt파일을 읽기 전용으로 연다	
		if (in.is_open() == false)	//파일 열기에 실패하면 실행
			cout << "파일 열기 실패";
		
		else {		//파일이 열렸을 경우 실행
			while (true) {	//무한 반복문 실행
				in >> number >> name >> age >> sex >> time >> specialty;	//파일의 내용을 읽어 해당 변수에 저장한다.
				result += number; result += name; result += age;		//result변수에 읽어들인 값들을 추가적으로 넣는다.
				result += sex; result += time; result += specialty;
				map2[name] = result;	//이름을 key값으로 result를 value값으로 넣어 생성한다.
				getline(in, line);		//한 줄 씩 읽어 변수 line에 저장
				if (in.eof())break;		//파일의 끝이 닿으면 반복문을 벗어난다.
				result = "";			//다음 베이비시터의 정보를 저장하기 위해 result 변수를 null로 한다.
			}
		}
		in.close();	//파일을 닫는다.
		ofstream out("sitterFavorite.txt", ios_base::out | ios_base::app);	//sitterFavorite.txt을 쓰기모드로 열고 파일을 쓰면 파일 포인터가 맨 끝에 자리한다.
		if (out.is_open() == false)	//파일이 열리지 않을 경우 실행
			cout << "File open failed";
		cout << "이름을 입력하세요==>";
		cin >> fname;	//입력받은 값을 fname에 저장한다.
		
		if (map2.find(fname)!=map2.end()) {		//입력받은 베이비시터의 이름이 베이비시터 정보에 존재하면 실행			
			out << map2.find(fname)->second<<endl;	//베이비 시터의 정보를 파일에 쓴다.
			cout << endl;	//줄 띄움
			cout << "추가되었습니다." << endl<<endl;
			out.close();	//파일을 닫는다.
			cout << "1.시작화면 2.즐겨찾기 화면 3.종료==>";
			cin >> input2;	//메뉴를 입력받아 input2에 저장한다.
			if (input2 == 1)	//1을 입력받을 경우 실행
				MainHandler::StartMenu();	//초기 메뉴로 돌아가는 함수 실행
			else if (input2 == 2)	//2를 입력받을 경우 실행
				Favorites();	//즐겨찾기 기능인 함수 실행
			
			else if (input2 == 3)	//3을 입력받을 경우 실행
				exit(1);	//프로그램 종료
		}
		else {	//베이비시터 정보에 입력받은 이름과 같은 이름이 없을 경우 실행
			cout << "해당 이름은 없습니다." << endl<<endl;
			out.close();	//파일을 닫는다.
			cout << "1.시작화면 2.즐겨찾기 화면 3.종료==>";
			
			cin >> input2;	//메뉴를 입력받아 input2에 저장한다.
			if (input2 == 1)	//1을 입력받을 경우 실행
				MainHandler::StartMenu();	//초기 메뉴로 돌아가는 함수 실행
			else if (input2 == 2)	//2를 입력받을 경우 실행
				Favorites();	//즐겨찾기 기능인 함수 실행

			else if (input2 == 3)	//3을 입력받을 경우 실행
				exit(1);	//프로그램 종료
		}

	}
	else if (input == 2) {	//즐겨찾기 보기를 선택하였을 경우 실행
		string tmp;		//파일에서 한 줄 씩 읽은 값을 저장하기 위한 변수
		ifstream in2("sitterFavorite.txt", ios::in);	//sitterFavorite.txt를 읽기 모드로 연다.
		
		if(in2.is_open() == false)	//파일 열기 실패할 경우 실행
			cout << "파일 열기 실패";

		else {	//파일이 열렸을 경우 실행
			cout << "=====즐겨찾기=====" << endl;
			while (true) {	//무한 반목문 실행
				getline(in2, tmp);	//파일을 한 줄 씩 읽어 tmp에 저장
				cout << tmp << endl;	//내용 출력
				if (in2.eof())break;		//파일을 끝까지 읽었으면 반복문을 벗어난다.
				
			}
			cout << "1.시작화면 2.즐겨찾기 3.채팅 4.종료 ==>";
			cin >> input3;	//입력받은 값을 변수에 저장
			if (input3 == 1)	//1을 입력받았을 경우 실행
				MainHandler::StartMenu();	//초기메뉴로 돌아가기위해 함수 실행

			else if (input3 == 2) {	//2를 입력 받았을 경우 실행
				fname = "";		//전에 입력받은 베이비시터 이름을 null로 한다.
				this->Favorites();	//즐겨찾기 기능인 함수 실행
			}
			else if (input3 == 3)	//3을 입력 받았을 경우 실행
				this->Chatting();	//채팅 기능 함수 실행

			else if (input3 == 4)	//4를 입력 받았을 경우 실행
				exit(0);			//프로그램이 종료된다.

		}
		in2.close();	//파일을 닫는다.
	}
}
void Parent::Join() {	//회원 가입 함수
	string id,pwd,name,age,sex,child_name,child_age,child_sex,number;	//회원정보를 저장하기 위한 변수
	cout << "아이디를 입력하세요==>";
	cin >> id;	//아이디를 입력받아 변수에 저장
	this->setID(id);	//객체에 아이디 값을 set한다.
	cout << "패스워드를 입력하세요==>";
	cin >> pwd;	//패스워드를 입력받아 변수에 저장
	this->setPwd(pwd);	//객체에 패스워드 값을 set한다.
	cout << "연락처를 입력하세요==>";
	cin >> number;	//연락처를 입력받아 변수에 저장
	this->setNumber(number);	//객체에 연락처 값을 set한다.
	cout << "이름을 입력하세요==>";
	cin >> name;	//이름을 입력받아 변수에 저장
	this->setName(name);	//객체에 이름 값을 set한다.
	cout << "나이를 입력하세요==>";
	cin >> age;	//나이를 입력받아 변수에 저장
	this->setAge(age);	//객체에 나이 값을 set한다.
	cout << "성별을 입력하세요==>";
	cin >> sex;	//성별을 입력받아 변수에 저장
	this->setSex(sex);	//객체에 성별 값을 set한다.
	cout << "아이의 이름을 입력하세요==>";
	cin >> child_name;	//아이의 이름을 입력받아 변수에 저장
	this->setChild_name(child_name);	//객체에 아이의 이름 값을 set한다.
	cout << "아이의 나이를 입력하세요==>";
	cin >> child_age;	//아이의 나이를 입력받아 변수에 저장
	this->setChild_age(child_age);	//객체에 아이의 나이 값을 set한다.
	cout << "아이의 성별을 입력하세요==>";
	cin >> child_sex;		//아이의 성별를 입력받아 변수에 저장
	this->setChild_sex(child_sex);	//객체에 아이의 성별 값을 set한다.

}
void Parent::Set() {		//회원정보를 파일에 저장 하는 함수
		ofstream out("parent.txt", ios_base::out | ios_base::app);	//parent.txt파일을 쓰기,append모드로 연다
		if (out.is_open() == false)	//파일 열기 실패 할 경우 실행
			cout << "File open failed";
		out << this->getID() << " ";			//파일에 아이디 값을 쓴다.
		out << this->getPwd() << " ";			//파일에 패스워드 값을 쓴다.
		out << this->getNumber() << " ";		//파일에 연락처 값을 쓴다.
		out << this->getName() << " ";			//파일에 이름 값을 쓴다.
		out << this->getAge() << " ";			//파일에 나이 값을 쓴다.
		out << this->getSex() << " ";			//파일에 성별 값을 쓴다.
		out << this->getChild_name() << " ";	//파일에 아이의 이름 값을 쓴다.
		out << this->getChild_age() << " ";		//파일에 아이의 나이 값을 쓴다.
		out << this->getChild_sex() << " ";		//파일에 아이의 성별 값을 쓴다.
		out << endl;	//줄 바꿈
		out.close();	//파일을 닫는다.

		ofstream out2("parentInfo.txt", ios_base::out | ios_base::app);	////parentIfo.txt파일을 쓰기,append모드로 연다
		if (out2.is_open() == false)	//파일 열기 실패 할 경우 실행
			cout << "File open failed";
		out2 << this->getName() << " ";			//파일에 이름 값을 쓴다.
		out2 << this->getAge() << " ";			//파일에 나이 값을 쓴다.
		out2 << this->getSex() << " ";			//파일에 성별 값을 쓴다.
		out2 << this->getChild_name() << " ";	//파일에 아이의 이름 값을 쓴다.
		out2 << this->getChild_age() << " ";		//파일에 아이의 나이 값을 쓴다.
		out2 << this->getChild_sex() << " ";		//파일에 아이의 성별 값을 쓴다.
		out2 << endl;	//줄 띄움
		out2.close();	//파일을 닫는다.
}
void Parent::Login() {	//로그인 기능을 하는 함수
	string pid;		//입력 받을 아이디 값을 저장 하기 위한 변수
	string ppwd;	//입력 받을 패스워드 값을 저장 하기 위한 변수
	string line;	//파일을 줄 단위로 읽어 저장할 변수
	int menu;		//메뉴를 입력받을 변수 
	char id[10];	//파일에서 아이디값을 읽어 저장할 char형 배열 변수
	char pwd[10];	//파일에서 패스워드값을 읽어 저장할 char형 배열 변수
	unordered_map<string, string> map1;	//unordered_map 변수 map1 선언
	
	cout << "아이디를 입력하세요==>";
	cin >> pid;	//아이디 값을 입력 받아 변수에 저장
	cout << "패스워드를 입력하세요==>";
	cin >> ppwd;	//패스워드 값을 입력 받아 변수에 저장
	

	ifstream in("parent.txt", ios::in);	//parent.txt 파일을 읽기 모드로 연다.
	if (in.is_open() == false)	//파일 열기 실패 할 경우 실행
		cout << "파일 열기 실패";
	else {	//파일이 열릴 경우 실행
		while(!in.eof()){	//파일의 끝까지 반복
			in >> id>>pwd;	//파일의 아이디값과 패스워드 값을 변수 id,pwd에 저장
			map1[id] = pwd;	//아이디값을 key값에 패스워드 값을 value값에 저장
			getline(in, line);	//한 줄 씩 읽어 변수 line에 저장
			if (in.eof())	//파일을 끝까지 읽으면 반복문 종료
				break; 
		}
		if (!(map1.find(pid) == map1.end())) {	//입력받은 아이디 값이 존재 할경우 실행
			if (map1.find(pid)->second == ppwd) {	//입력받은 패스워드 값이 존재 할 경우 실행
				cout << endl << "=====" << pid << "님 " << "환영합니다.=====" << endl << endl;
				Show();	//베이비 시터 정보를 보여주는 함수 실행
			}
			else {	//입력받은 아이디 값이 존재 하지 않을 경우 실행
				cout << "아이디 혹은 패스워드를 잘못입력하였습니다." << endl;
				cout << "1.재로그인 2.초기화면 3.시작화면==>";
				cin >> menu;	//선택한 메뉴를 menu 변수에 저장
				if (menu == 1)	//1을 입력 하였을 경우 실행
					Login();	//다시 로그인을 할 수 있게 Login()함수를 실행한다.
				else if (menu == 2)	//2를 입력 하였을 경우 실행
					SitterHandler::LoginMenu();	//SitterHandler의 정적함수인 LoginMenu()를 실행한다(베이비시터를 선택 후 처음에 실행되는 메뉴)
				else if (menu == 3)	//3을 입력 하였을 경우 실행
					MainHandler::StartMenu();	//MainHandler의 정적함수인 StartMenu()를 실행한다(프로그램 시작시 보여지는 메뉴)
				else	//1,2,3 외의 입력을 하였을 겨우 실행
					cout << "메뉴를 잘못 선택하였습니다." << endl; 
			}
		}
			else {
					cout << "아이디 혹은 패스워드를 잘못입력하였습니다." << endl<<endl;
					cout << "1.재로그인 2.초기화면 3.시작화면==>";
					
					cin >> menu;	//선택한 메뉴를 menu 변수에 저장
					if (menu == 1)	//1을 입력 하였을 경우 실행
						Login();	//다시 로그인을 할 수 있게 Login()함수를 실행한다.
					else if (menu == 2)	//2를 입력 하였을 경우 실행
						SitterHandler::LoginMenu();	//SitterHandler의 정적함수인 LoginMenu()를 실행한다(베이비시터를 선택 후 처음에 실행되는 메뉴)
					else if (menu == 3)	//3을 입력 하였을 경우 실행
						MainHandler::StartMenu();	//MainHandler의 정적함수인 StartMenu()를 실행한다(프로그램 시작시 보여지는 메뉴)
					else	//1,2,3 외의 입력을 하였을 겨우 실행
						cout << "메뉴를 잘못 선택하였습니다." << endl;
				}
			
		}
	in.close();		//파일을 닫는다.
}
void Parent::Chatting() {
	string tmp;		//파일의 내용을 한줄 씩 읽어 저장할 변수
	string chat;	//채팅시 문자열을 입력받아 저장할 변수
	ifstream in("chatting.txt", ios::in);	//chatting.txt파일을 읽기 전용으로 연다

	if (in.is_open() == false)	//파일 열기가 실패할 경우 실행
		cout << "파일 열기 실패";

	else {	//파일이 정상적으로 열렸을 경우 실행	
		while (true) {	//무한반복문 실행
			getline(in, tmp);	//파일을 한줄씩 읽어서 tmp변수에 저장
			cout << tmp << endl;	//한 줄씩 읽은 정보를 출력
			if (in.eof())break;	//파일의 끝까지 읽으면 반목문 종료

		}
		in.close();	//파일을 닫는다
	}
	ofstream out("chatting.txt", ios_base::out | ios_base::app);	//chatting.txt를 쓰기 전용으로 열고 추가 작성시 파일 포인터가 끝에 가게 한다.
	if (out.is_open() == false)		//파일이 열리지 않았을 경우 실행
		cout << "File open failed";
	cout << "Parent==>";
	getline(cin, chat);		//chat변수에 입력받은 값을 저장
	getline(cin, chat);		//버퍼를 한번 비우기 위해 사용
	out << "Parent==>" << chat << endl;	//파일에 입력한 내용을 쓴다.
	out.close();	//파일을 닫는다.
	Show();	//베이비시터 정보를 보여주는 함수 실행
	
}
Parent::~Parent()
{
}

