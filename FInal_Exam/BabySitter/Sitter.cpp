
#include "Sitter.h"
void Sitter::Join() {		//���̺� ���Ͱ� ȸ�����Խ� ȣ��Ǵ� �Լ�
	unordered_map<int, string> parttime;	//unordered_map�� <int,string>���� ���ʸ��Ͽ� �����Ѵ�.

	parttime[1] = "(00:00~02:00)";			//ȸ�����Խ� ���ѽð��� ���������� �޾� �Է��� ��ȣ�� ���� �� �� �ð��� value���� ����
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
	string id, pwd, name, age, sex, time, specialty;	//���̵�,�н�����,�̸�,����,����,���ҽð�,Ư�⸦ �Է¹ޱ� ���� string ���� ����
	string resulttime;		//���� ���� �ð��� �����ϱ����� string ���� ����
	
	char* stime;	//���� �ð��� ��ū������ �и��ؼ� ������ ����
	char* context;	//���� �ð��� ��ū������ �и� �� ������ �ӽ� ����
	
	int save;		//�Է¹��� �ð��� ���������� ����ȯ�Ͽ� ������ ����
	cout << "���̵� �Է��ϼ���==>";	
	cin >> id;		//���� id�� �Է¹��� ���̵� ���� ����
	this->SetId(id);//��ü�� id���� set�Լ��� �̿��Ͽ� ����
	cout << "�н����带 �Է��ϼ���==>";
	cin >> pwd;		//���� pwd�� �Է¹��� �н����� ���� ����
	this->SetPwd(pwd);//��ü�� pwd���� set�Լ��� �̿��Ͽ� ����
	cout << "����ó�� �Է��ϼ���==>";
	cin >> number;	//���� number�� �Է¹��� ����ó ���� ����
	this->SetNumber(number);//��ü�� numer���� set�Լ��� �̿��Ͽ� ����
	cout << "�̸��� �Է��ϼ���==>";
	cin >> name;	//���� name�� �Է¹��� �̸� ���� ����
	this->SetName(name);//��ü�� name���� set�Լ��� �̿��Ͽ� ����
	cout << "���̸� �Է��ϼ���==>";
	cin >> age;		//���� age�� �Է¹��� ���� ���� ����
	this->SetAge(age);//��ü�� age���� set�Լ��� �̿��Ͽ� ����
	cout << "������ �Է��ϼ���==>";
	cin >> sex;		//���� sex�� �Է¹��� ���� ���� ����
	this->SetSex(sex);//��ü�� sex���� set�Լ��� �̿��Ͽ� ����
	cout << "1.(00:00~02:00) 2.(02:00~04:00) 3.(04:00~06:00) 4.(06:00~08:00) 5.(08:00~10:00) 6.(10:00~12:00)" << endl;
	cout << "7.(12:00~14:00) 8.(14:00~16:00) 9.(16:00~18:00) 10.(18:00~20:00) 11.(20:00~22:00) 12.(22:00~00:00)" << endl;
	cout << "���� �� �ִ� �ð��� �Է��� �ּ���(ex.1,2,3)==>";
	cin >> time;	//���� time�� �Է¹��� ���̵� ���� ����
	
	vector<char> writabe(time.begin(), time.end());	//string���� char* ������ ����ȯ (���׳ݿ��� �ҽ�����)
	writabe.push_back('\0');
	char* ptime = &writabe[0];		//������� �ҽ� ����
	
	stime = strtok_s(ptime, ",", &context);		//�Է¹��� ���� �ð��� , ������ ��ū�� �и�
	while (stime != NULL) {		//��ū�� �ִ� ��� ����
		save = atoi(stime);		//�и��� ��ū�� ���������� ����ȯ
		stime = strtok_s(context, ",", &context);	//���� ��ū�� ��ȯ
		resulttime += parttime.find(save)->second + " ";	//��ū �и��� ���� �� key������ �޴� ���� find�Լ��� �̿��Ͽ� value�� ���� �Ͽ�  resulttime������ ���̾� ����
	}
	
	this->SetTime(resulttime);	//���� ���� �ð��� ��ü�� ����
	
	cout << "Ư�⸦ �Է��ϼ���(ex.�丮,����,����)==>";
	cin >> specialty;		//���� specialty�� �Է¹��� Ư�� ���� ����
	this->SetSpecialty(specialty);	//��ü�� specialty���� set�Լ��� �̿��Ͽ� ����
	
}
void Sitter::Set() {		//���Ͽ� ȸ�����Խ� �ۼ��� �������� �����ϴ� �Լ�
	//�α��ν� Ȱ��� ����
	ofstream out("sitter.txt", ios_base::out | ios_base::app);	//sitter.txt������ ���� ���� ���� �߰� �ۼ��� ���� ��ġ �����Ͱ� ���� ���� �Ѵ�.
	if (out.is_open() == false)		//������ ���������� ������ �ʾ��� ��� ����
		cout << "File open failed";
	out << this->GetId() << " ";		//get�Լ��� �ҷ� ��ü�� ���̵��� ���Ͽ� ���� 
	out << this->GetPwd() << " ";		//get�Լ��� �ҷ� ��ü�� �н����尪�� ���Ͽ� ���� 
	out << this->GetNumber() << " ";	//get�Լ��� �ҷ� ��ü�� ����ó���� ���Ͽ� ���� 
	out << this->GetName() << " ";		//get�Լ��� �ҷ� ��ü�� �̸����� ���Ͽ� ���� 
	out << this->GetAge() << " ";		//get�Լ��� �ҷ� ��ü�� ���̰��� ���Ͽ� ���� 
	out << this->GetSex() << " ";		//get�Լ��� �ҷ� ��ü�� �������� ���Ͽ� ���� 
	out << this->GetTime() << " ";		//get�Լ��� �ҷ� ��ü�� ���� �ð����� ���Ͽ� ���� 
	out << this->GetSpecialty() << " ";//get�Լ��� �ҷ� ��ü�� Ư�Ⱚ�� ���Ͽ� ���� 
	out << endl;	//�� �� ����ش�.
	out.close();	//������ �ݴ´�.
	//�θ� ���̺� ������ ������ Ȯ���� �� ���� ����
	ofstream out2("sitterInfo.txt", ios_base::out | ios_base::app);	//sitterInfo.txt������ ���� ���� ���� �߰� �ۼ��� ���� ��ġ �����Ͱ� ���� ���� �Ѵ�.
	if (out2.is_open() == false)		//������ ���������� ������ �ʾ��� ��� ����
		cout << "File open failed";
	out2 << this->GetNumber() << " ";		//get�Լ��� �ҷ� ��ü�� ����ó���� ���Ͽ� ���� 
	out2 << this->GetName() << " ";			//get�Լ��� �ҷ� ��ü�� �̸����� ���Ͽ� ���� 
	out2 << this->GetAge() << " ";			//get�Լ��� �ҷ� ��ü�� ���̰��� ���Ͽ� ���� 
	out2 << this->GetSex() << " ";			//get�Լ��� �ҷ� ��ü�� �������� ���Ͽ� ���� 
	out2 << this->GetTime() << "  ";		//get�Լ��� �ҷ� ��ü�� ���� �ð����� ���Ͽ� ���� 
	out2 << this->GetSpecialty() << "  ";	//get�Լ��� �ҷ� ��ü�� Ư�Ⱚ�� ���Ͽ� ���� 
	out2 << endl;	//�� �� ����ش�.
	out2.close();	//������ �ݴ´�.
}
void Sitter::Login() {		//���̺� ���Ͱ� �α��� �޴��� ���ý� ����� �Լ�
	string pid;		//�Է¹��� ���̵� ���� ������ ����
	string ppwd;	//�Է¹��� �н����� ���� ������ ����
	char name[5];	//���Ͽ��� �о�� �̸����� ������ char�� �迭 ����
	char age[3];	//���Ͽ��� �о�� ���̰��� ������ char�� �迭 ����
	char sex[3];	//���Ͽ��� �о�� �������� ������ char�� �迭 ����
	char time[27];	//���Ͽ��� �о�� ���� �ð����� ������ char�� �迭 ����
	char specialty[10];	//���Ͽ��� �о�� Ư�Ⱚ�� ������ char�� �迭 ����
	string line;	//���Ͽ��� �� �� �� �о ������ ����
	int menu;		//�޴��� �����Ͽ� �Է¹޾� ������ ����
	char id[10];	//���Ͽ��� �о�� ���̵��� ������ char�� �迭 ����	
	char pwd[10];	//���Ͽ��� �о�� �н����尪�� ������ char�� �迭 ����
	unordered_map<string, string> map1;	//unordered_map ���� map1 ����
	

	cout << "���̵� �Է��ϼ���==>";
	cin >> pid;	//�Է¹��� ���̵� ���� ���� pid�� ����
	cout << "�н����带 �Է��ϼ���==>";
	cin >> ppwd;//�Է¹��� �н����� ���� ���� ppwd�� ����


	ifstream in("sitter.txt", ios::in);	//sitter.txt������ �б� �������� ����.
	if (in.is_open() == false)	//���� ���⿡ �����ϸ� ����
		cout << "���� ���� ����";
	else {	//������ ���������� �������� ����
		while (!in.eof()) {	//������ ������ �����Ѵ�.
			in >> id >> pwd;	//���Ͽ� ����� ���̵�� �н����� ���� ���� id, pwd�� ���� �����Ѵ�.
			map1[id] = pwd;		//���̵� key���� value���� pwd�� unordered_map ���� map1�� �����Ѵ�. 
			getline(in, line);	//���Ͽ� ����� ���� ���� �о� ���δ�.
			if (in.eof())		//���Ͽ� ���̻� �о�� ������ ������ while���� �����.
				break;
			}
		
		if (!(map1.find(pid) == map1.end())) {	//�Է¹��� ���̵� ���� ȸ�����Խ� ����� ���̵� ���� ��ġ�� ��� ����
			if (map1.find(pid)->second == ppwd) {	//�Է¹��� �н����� ���� ȸ�����Խ� ����� �н����� ���� ��ġ�� ��� ����
				cout << endl << "=====" << pid << "�� " << "ȯ���մϴ�.=====" << endl << endl;
				Show();		//�θ��� ������ �����ִ� Show�Լ� ����
			}
			else {	//�Է¹��� ���̵� ���� ��ġ ������ �н����尡 �ٸ� ��� ����
				cout << "���̵� Ȥ�� �н����带 �߸��Է��Ͽ����ϴ�." << endl;	
				cout << "1.��α��� 2.�ʱ�ȭ�� 3.����ȭ��==>";
				cin >> menu;	//������ �޴��� menu ������ ����
				if (menu == 1)	//1�� �Է� �Ͽ��� ��� ����
					Login();	//�ٽ� �α����� �� �� �ְ� Login()�Լ��� �����Ѵ�.
				else if (menu == 2)	//2�� �Է� �Ͽ��� ��� ����
					SitterHandler::LoginMenu();	//SitterHandler�� �����Լ��� LoginMenu()�� �����Ѵ�(���̺���͸� ���� �� ó���� ����Ǵ� �޴�)
				else if (menu == 3)	//3�� �Է� �Ͽ��� ��� ����
					MainHandler::StartMenu();	//MainHandler�� �����Լ��� StartMenu()�� �����Ѵ�(���α׷� ���۽� �������� �޴�)
				else	//1,2,3 ���� �Է��� �Ͽ��� �ܿ� ����
					cout << "�޴��� �߸� �����Ͽ����ϴ�." << endl;
			}
			
		}
		else {	//�Է¹��� ���̵� ���� ��ġ ������ �н����尡 �ٸ� ��� ����
			cout << "���̵� Ȥ�� �н����带 �߸��Է��Ͽ����ϴ�." << endl;
			cout << "1.��α��� 2.�ʱ�ȭ�� 3.����ȭ��==>";
			cin >> menu;	//������ �޴��� menu ������ ����
			if (menu == 1)	//1�� �Է� �Ͽ��� ��� ����
				Login();	//�ٽ� �α����� �� �� �ְ� Login()�Լ��� �����Ѵ�.
			else if (menu == 2)	//2�� �Է� �Ͽ��� ��� ����
				SitterHandler::LoginMenu();	//SitterHandler�� �����Լ��� LoginMenu()�� �����Ѵ�(���̺���͸� ���� �� ó���� ����Ǵ� �޴�)
			else if (menu == 3)	//3�� �Է� �Ͽ��� ��� ����
				MainHandler::StartMenu();	//MainHandler�� �����Լ��� StartMenu()�� �����Ѵ�(���α׷� ���۽� �������� �޴�)
			else	//1,2,3 ���� �Է��� �Ͽ��� �ܿ� ����
				cout << "�޴��� �߸� �����Ͽ����ϴ�." << endl;
		}

	}
	in.close();	//������ �ݴ´�
}
void Sitter::Show() {	//�θ�� ������ ������ �����ִ� �Լ�
	string line;	//���Ͽ��� �� �پ� �о ������ ����
	int input;		//�޴� ���ý� �Է»����� ������ ����
	ifstream in("parentInfo.txt", ios::in);	//parentInfo.txt������ �б� �������� ����.
	if (in.is_open() == false)	//������ ���������� ������ �ʾ��� ��� ����
		cout << "���� ���� ����";
	else {	//������ ���������� ������ ��� ����
		cout << "=====�θ�� ���� ����=====" << endl;
		cout << "     �θ�           ����" << endl;
		cout << "�̸� ���� ���� �̸� ����  ����ó" << endl;
		while (true) {	//���ѹݺ� ����
			getline(in, line);	//������ ���پ� �о� ���� line�� ����
			if (in.eof())break;	//������ ������ ������ �ݺ����� ����
			cout << line << endl;	//���Ͽ��� ���� ������ ����Ѵ�.
		}
		cout << endl;
		cout << "1.����ȭ�� 2.ä�� 3.����==>";
		cin >> input;	//�Է¹��� �޴��� ���� input�� �����Ѵ�.
		if (input == 1)	//1�� �Է� ���� ��� ����
			MainHandler::StartMenu();	//MainHandler�� �����Լ��� StartMenu()�� �����Ѵ�(���α׷� ���۽� �������� �޴�)
		else if (input == 2)	//2�� �Է� ���� ��� ����
			this->Chatting();	//ä�� ����� �ϴ� Chatting() �Լ� ����
		else if (input == 3)	//3�� �Է� ���� ��� ����
			exit(0);			//�����Ѵ�

		in.close();	//������ �ݴ´�.
	}
}
void Sitter::Chatting() {	//ä�ñ���� �ϴ� �Լ� 
	string tmp;		//������ ������ ���� �� �о� ������ ����
	string chat;	//ä�ý� ���ڿ��� �Է¹޾� ������ ����
	ifstream in("chatting.txt", ios::in);	//chatting.txt������ �б� �������� ����

	if (in.is_open() == false)	//���� ���Ⱑ ������ ��� ����
		cout << "���� ���� ����";

	else {	//������ ���������� ������ ��� ����	
		while (true) {	//���ѹݺ��� ����
			getline(in, tmp);	//������ ���پ� �о tmp������ ����
			cout << tmp << endl;	//�� �پ� ���� ������ ���
			if (in.eof())break;	//������ ������ ������ �ݸ� ����

		}
		in.close();	//������ �ݴ´�
	}
	ofstream out("chatting.txt", ios_base::out | ios_base::app);	//chatting.txt�� ���� �������� ���� �߰� �ۼ��� ���� �����Ͱ� ���� ���� �Ѵ�.
	if (out.is_open() == false)		//������ ������ �ʾ��� ��� ����
		cout << "File open failed";
	cout << "BabySitter==>";	
	getline(cin, chat);		//chat������ �Է¹��� ���� ����
	getline(cin, chat);		//���۸� �ѹ� ���� ���� ���
	out << "BabySitter==>" << chat << endl;	//���Ͽ� �Է¹��� ���� �����Ѵ�.
	out.close();	//������ �ݴ´�.
	Show();	//�θ� ������ �����ִ� �Լ� ����
}

Sitter::Sitter()
{
}


Sitter::~Sitter()
{
}
