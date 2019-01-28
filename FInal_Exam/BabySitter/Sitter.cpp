
#include "Sitter.h"
void Sitter::Join() {		//베이비 시터가 회원가입시 호출되는 함수
	unordered_map<int, string> parttime;	//unordered_map을 <int,string>으로 제너릭하여 생성한다.

	parttime[1] = "(00:00~02:00)";			//회원가입시 일한시간을 정수형으로 받아 입력한 번호에 따라 일 할 시간을 value값에 저장
	parttime[2] = "(02:00~04:00)";
	parttime[3] = "(04:00~06:00)";
	parttime[4] = "(06:00~08:00)";
	parttime[5] = "(08:00~10:00)";
	parttime[6] = "(10:00~12:00)";
	parttime[7] = "(12:00~14:00)";
	parttime[8] = "(14:00~16:00)";
	parttime[9] = "(16:00~18:00)";
	parttime[10] = "(18:00~20:00)";
	parttime[11] = "(20:00~22:00)";
	parttime[12] = "(22:00~00:00)";
	string id, pwd, name, age, sex, time, specialty;	//아이디,패스워드,이름,나이,성별,일할시간,특기를 입력받기 위해 string 변수 선언
	string resulttime;		//최종 일할 시간을 저장하기위한 string 변수 선언
	
	char* stime;	//일할 시간을 토큰단위로 분리해서 저장할 변수
	char* context;	//일할 시간을 토큰단위로 분리 후 저장할 임시 변수
	
	int save;		//입력받은 시간을 정수형으로 형변환하여 저장할 변수
	cout << "아이디를 입력하세요==>";	
	cin >> id;		//변수 id에 입력받은 아이디 정보 저장
	this->SetId(id);//객체에 id값을 set함수를 이용하여 저장
	cout << "패스워드를 입력하세요==>";
	cin >> pwd;		//변수 pwd에 입력받은 패스워드 정보 저장
	this->SetPwd(pwd);//객체에 pwd값을 set함수를 이용하여 저장
	cout << "연락처를 입력하세요==>";
	cin >> number;	//변수 number에 입력받은 연락처 정보 저장
	this->SetNumber(number);//객체에 numer값을 set함수를 이용하여 저장
	cout << "이름을 입력하세요==>";
	cin >> name;	//변수 name에 입력받은 이름 정보 저장
	this->SetName(name);//객체에 name값을 set함수를 이용하여 저장
	cout << "나이를 입력하세요==>";
	cin >> age;		//변수 age에 입력받은 나이 정보 저장
	this->SetAge(age);//객체에 age값을 set함수를 이용하여 저장
	cout << "성별을 입력하세요==>";
	cin >> sex;		//변수 sex에 입력받은 성별 정보 저장
	this->SetSex(sex);//객체에 sex값을 set함수를 이용하여 저장
	cout << "1.(00:00~02:00) 2.(02:00~04:00) 3.(04:00~06:00) 4.(06:00~08:00) 5.(08:00~10:00) 6.(10:00~12:00)" << endl;
	cout << "7.(12:00~14:00) 8.(14:00~16:00) 9.(16:00~18:00) 10.(18:00~20:00) 11.(20:00~22:00) 12.(22:00~00:00)" << endl;
	cout << "일할 수 있는 시간을 입력해 주세요(ex.1,2,3)==>";
	cin >> time;	//변수 time에 입력받은 아이디 정보 저장
	
	vector<char> writabe(time.begin(), time.end());	//string형을 char* 형으로 형변환 (인테넷에서 소스참고)
	writabe.push_back('\0');
	char* ptime = &writabe[0];		//여기까지 소스 참고
	
	stime = strtok_s(ptime, ",", &context);		//입력받은 일할 시간을 , 단위로 토큰을 분리
	while (stime != NULL) {		//토큰이 있는 경우 실행
		save = atoi(stime);		//분리된 토큰을 정수형으로 형변환
		stime = strtok_s(context, ",", &context);	//다음 토큰을 반환
		resulttime += parttime.find(save)->second + " ";	//토큰 분리된 정수 값 key값으로 받는 맵의 find함수를 이용하여 value값 추출 하여  resulttime변수에 연이어 저장
	}
	
	this->SetTime(resulttime);	//최종 일할 시간을 객체에 저장
	
	cout << "특기를 입력하세요(ex.요리,놀이,교육)==>";
	cin >> specialty;		//변수 specialty에 입력받은 특기 정보 저장
	this->SetSpecialty(specialty);	//객체에 specialty값을 set함수를 이용하여 저장
	
}
void Sitter::Set() {		//파일에 회원가입시 작성한 정보들을 저장하는 함수
	//로그인시 활용될 파일
	ofstream out("sitter.txt", ios_base::out | ios_base::app);	//sitter.txt파일을 쓰기 모드로 열고 추가 작성시 파일 위치 포인터가 끝에 가게 한다.
	if (out.is_open() == false)		//파일이 정상적으로 열리지 않았을 경우 실행
		cout << "File open failed";
	out << this->GetId() << " ";		//get함수를 불러 객체의 아이디값을 파일에 저장 
	out << this->GetPwd() << " ";		//get함수를 불러 객체의 패스워드값을 파일에 저장 
	out << this->GetNumber() << " ";	//get함수를 불러 객체의 연락처값을 파일에 저장 
	out << this->GetName() << " ";		//get함수를 불러 객체의 이름값을 파일에 저장 
	out << this->GetAge() << " ";		//get함수를 불러 객체의 나이값을 파일에 저장 
	out << this->GetSex() << " ";		//get함수를 불러 객체의 성별값을 파일에 저장 
	out << this->GetTime() << " ";		//get함수를 불러 객체의 일할 시간값을 파일에 저장 
	out << this->GetSpecialty() << " ";//get함수를 불러 객체의 특기값을 파일에 저장 
	out << endl;	//한 줄 띄어준다.
	out.close();	//파일을 닫는다.
	//부모가 베이비 시터의 정보를 확일할 때 사용될 파일
	ofstream out2("sitterInfo.txt", ios_base::out | ios_base::app);	//sitterInfo.txt파일을 쓰기 모드로 열고 추가 작성시 파일 위치 포인터가 끝에 가게 한다.
	if (out2.is_open() == false)		//파일이 정상적으로 열리지 않았을 경우 실행
		cout << "File open failed";
	out2 << this->GetNumber() << " ";		//get함수를 불러 객체의 연락처값을 파일에 저장 
	out2 << this->GetName() << " ";			//get함수를 불러 객체의 이름값을 파일에 저장 
	out2 << this->GetAge() << " ";			//get함수를 불러 객체의 나이값을 파일에 저장 
	out2 << this->GetSex() << " ";			//get함수를 불러 객체의 성별값을 파일에 저장 
	out2 << this->GetTime() << "  ";		//get함수를 불러 객체의 일할 시간값을 파일에 저장 
	out2 << this->GetSpecialty() << "  ";	//get함수를 불러 객체의 특기값을 파일에 저장 
	out2 << endl;	//한 줄 띄어준다.
	out2.close();	//파일을 닫는다.
}
void Sitter::Login() {		//베이비 시터가 로그인 메뉴를 선택시 실행될 함수
	string pid;		//입력받을 아이디 값을 저장할 변수
	string ppwd;	//입력받을 패스워드 값을 저장할 변수
	char name[5];	//파일에서 읽어온 이름값을 저장할 char형 배열 변수
	char age[3];	//파일에서 읽어온 나이값을 저장할 char형 배열 변수
	char sex[3];	//파일에서 읽어온 성별값을 저장할 char형 배열 변수
	char time[27];	//파일에서 읽어온 일할 시간값을 저장할 char형 배열 변수
	char specialty[10];	//파일에서 읽어온 특기값을 저장할 char형 배열 변수
	string line;	//파일에서 한 줄 씩 읽어서 저장할 변수
	int menu;		//메뉴를 선택하여 입력받아 저장할 변수
	char id[10];	//파일에서 읽어온 아이디값을 저장할 char형 배열 변수	
	char pwd[10];	//파일에서 읽어온 패스워드값을 저장할 char형 배열 변수
	unordered_map<string, string> map1;	//unordered_map 변수 map1 선언
	

	cout << "아이디를 입력하세요==>";
	cin >> pid;	//입력받은 아이디 값을 변수 pid에 저장
	cout << "패스워드를 입력하세요==>";
	cin >> ppwd;//입력받은 패스워드 값을 변수 ppwd에 저장


	ifstream in("sitter.txt", ios::in);	//sitter.txt파일을 읽기 전용으로 연다.
	if (in.is_open() == false)	//파일 열기에 실패하면 실행
		cout << "파일 열기 실패";
	else {	//파일이 정상적으로 열렸으면 실행
		while (!in.eof()) {	//파일의 끝까지 실행한다.
			in >> id >> pwd;	//파일에 저장된 아이디와 패스워드 값을 변수 id, pwd에 각각 저장한다.
			map1[id] = pwd;		//아이디를 key값에 value값을 pwd인 unordered_map 변수 map1에 저장한다. 
			getline(in, line);	//파일에 저장된 다음 줄을 읽어 들인다.
			if (in.eof())		//파일에 더이상 읽어올 내용이 없으면 while문을 벗어난다.
				break;
			}
		
		if (!(map1.find(pid) == map1.end())) {	//입력받은 아이디 값과 회원가입시 저장된 아이디 값이 일치할 경우 실행
			if (map1.find(pid)->second == ppwd) {	//입력받은 패스워드 값과 회원가입시 저장된 패스워드 값이 일치할 경우 실행
				cout << endl << "=====" << pid << "님 " << "환영합니다.=====" << endl << endl;
				Show();		//부모의 정보를 보여주는 Show함수 실행
			}
			else {	//입력받은 아이디 값은 일치 하지만 패스워드가 다를 경우 실행
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
		else {	//입력받은 아이디 값은 일치 하지만 패스워드가 다를 경우 실행
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
	in.close();	//파일을 닫는다
}
void Sitter::Show() {	//부모와 아이의 정보를 보여주는 함수
	string line;	//파일에서 한 줄씩 읽어서 저장할 변수
	int input;		//메뉴 선택시 입력사항을 저장할 변수
	ifstream in("parentInfo.txt", ios::in);	//parentInfo.txt파일을 읽기 전용으로 연다.
	if (in.is_open() == false)	//파일이 정상적으로 열리지 않았을 경우 실행
		cout << "파일 열기 실패";
	else {	//파일이 정상적으로 열렸을 경우 실행
		cout << "=====부모와 아이 정보=====" << endl;
		cout << "     부모           아이" << endl;
		cout << "이름 나이 성별 이름 성별  연락처" << endl;
		while (true) {	//무한반복 실행
			getline(in, line);	//파일을 한줄씩 읽어 변수 line에 저장
			if (in.eof())break;	//파일의 끝까지 읽으면 반복문을 종료
			cout << line << endl;	//파일에서 읽은 정보를 출력한다.
		}
		cout << endl;
		cout << "1.시작화면 2.채팅 3.종료==>";
		cin >> input;	//입력받은 메뉴를 변수 input에 저장한다.
		if (input == 1)	//1을 입력 받을 경우 실행
			MainHandler::StartMenu();	//MainHandler의 정적함수인 StartMenu()를 실행한다(프로그램 시작시 보여지는 메뉴)
		else if (input == 2)	//2를 입력 받을 경우 실행
			this->Chatting();	//채팅 기능을 하는 Chatting() 함수 실행
		else if (input == 3)	//3을 입력 받을 경우 실행
			exit(0);			//종료한다

		in.close();	//파일을 닫는다.
	}
}
void Sitter::Chatting() {	//채팅기능을 하는 함수 
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
	cout << "BabySitter==>";	
	getline(cin, chat);		//chat변수에 입력받은 값을 저장
	getline(cin, chat);		//버퍼를 한번 비우기 위해 사용
	out << "BabySitter==>" << chat << endl;	//파일에 입력받은 값을 저장한다.
	out.close();	//파일을 닫는다.
	Show();	//부모 정보를 보여주는 함수 실행
}

Sitter::Sitter()
{
}


Sitter::~Sitter()
{
}
