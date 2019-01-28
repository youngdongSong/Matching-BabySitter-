#pragma warning(disable:4996)
#include"Parent.h"

using namespace std;

Parent::Parent() {}
void Parent::Show() {	//���̺� ������ ������ �����ִ� �Լ�
	string line;		//���Ͽ��� ���� ��
	
	int input;	//�޴����� �Է¹��� ������ ������ ����
	unordered_map<string, string> map2;		//unordered_map ��ü <string,strng>���� ���ʸ��� map2�� ����
	ifstream in("sitterInfo.txt", ios::in);	//sitterInfo.txt�� �б� ���� ����
	if (in.is_open() == false)	//���� ���н� ����
		cout << "���� ���� ����";
	else {	//���⿡ ������ ��� ����
		cout << "=====���̺� ���� ����=====" << endl;
		cout << "    ����ó    �̸� ���� ���� ���ɽð� Ư�� ��"<<endl<<endl;
		while (true) {	//���� �ݺ��� ����
			getline(in, line);	//���Ͽ��� �� �� �� ���� ������ ���� line�� ����	
			cout << line << endl;	//�� �� �� ���
			if (in.eof())break;	//������ ������ ������ ������ �ݺ��� ����
			
		}
		cout << endl;
		cout << "1.����ȭ�� 2.���ã�� 3.ä�� 4.���� ==>";
		cin >> input;	//�޴��� �Է¹޾� ���� input�� ����
		if (input == 1)	//1�� �Է� �޾��� ��� ����
			MainHandler::StartMenu();	//���α׷� ������ ���� �޴� �����ϴ� �Լ� ����

		else if (input == 2)	//2�� �Է� �޾��� ��� ����
			this->Favorites();	//���ã�� ����� �ϴ� Favorites()�Լ� ����

		else if (input == 3)	//3�� �Է� �޾��� ��� ����
			this->Chatting();	//ä�� ����� �ϴ� Chatting() �Լ� ����

		else if (input == 4)	//4�� �Է� �޾��� ��� ����
			exit(0);	//���α׷��� �����Ѵ�.
		

		in.close();	//������ �ݴ´�.
	}
}
void Parent::Favorites() {	//���ã�� ����� �ϴ� �Լ�	
	int input;		//���ã�⸦ �߰�, ���ã�� ���� �� �Է¹��� ������ ���� �ϴ� ����
	int	input3;		//����ȭ��, ���ã��,.ä��, ���� �� �Է¹��� ������ ���� �ϴ� ����
	int input2;		//����ȭ��, ���ã�� ȭ��, ���� �� �Է¹��� ������ ���� �ϴ� ����
	char number[15];	//���Ͽ��� ���� ����ó ������ �����ϴ� char�� �迭 ����
	char name[7];		//���Ͽ��� ���� �̸� ������ �����ϴ� char�� �迭 ����
	char age[5];		//���Ͽ��� ���� ���� ������ �����ϴ� char�� �迭 ����
	char sex[20];		//���Ͽ��� ���� ���� ������ �����ϴ� char�� �迭 ����
	char time[100];		//���Ͽ��� ���� ���� �ð� ������ �����ϴ� char�� �迭 ����
	char specialty[50];//���Ͽ��� ���� Ư�� ������ �����ϴ� char�� �迭 ����
	string result;		//���Ͽ��� ���� ������ string�� ���� result�� ��� �ֱ� ���� ����
	string fname;		//���ã�� �߰� �� ���̺������ �̸��� �Է¹ޱ����� ���� ����
	string line;		//���Ͽ��� �� �� �� �о� ����� ����
	unordered_map<string, string> map2;		//unordered_map ��ü <string,strng>���� ���ʸ��� map2�� ����
	
	cout << "1.���ã�� �߰� 2.���ã�� ����==>";
	cin >> input;	//�Է¹��� ������ input�� ����

	if (input == 1) {	//1�� �Է� ���� ��� ����
		ifstream in("sitterInfo.txt", ios::in);	//sitterInfo.txt������ �б� �������� ����	
		if (in.is_open() == false)	//���� ���⿡ �����ϸ� ����
			cout << "���� ���� ����";
		
		else {		//������ ������ ��� ����
			while (true) {	//���� �ݺ��� ����
				in >> number >> name >> age >> sex >> time >> specialty;	//������ ������ �о� �ش� ������ �����Ѵ�.
				result += number; result += name; result += age;		//result������ �о���� ������ �߰������� �ִ´�.
				result += sex; result += time; result += specialty;
				map2[name] = result;	//�̸��� key������ result�� value������ �־� �����Ѵ�.
				getline(in, line);		//�� �� �� �о� ���� line�� ����
				if (in.eof())break;		//������ ���� ������ �ݺ����� �����.
				result = "";			//���� ���̺������ ������ �����ϱ� ���� result ������ null�� �Ѵ�.
			}
		}
		in.close();	//������ �ݴ´�.
		ofstream out("sitterFavorite.txt", ios_base::out | ios_base::app);	//sitterFavorite.txt�� ������� ���� ������ ���� ���� �����Ͱ� �� ���� �ڸ��Ѵ�.
		if (out.is_open() == false)	//������ ������ ���� ��� ����
			cout << "File open failed";
		cout << "�̸��� �Է��ϼ���==>";
		cin >> fname;	//�Է¹��� ���� fname�� �����Ѵ�.
		
		if (map2.find(fname)!=map2.end()) {		//�Է¹��� ���̺������ �̸��� ���̺���� ������ �����ϸ� ����			
			out << map2.find(fname)->second<<endl;	//���̺� ������ ������ ���Ͽ� ����.
			cout << endl;	//�� ���
			cout << "�߰��Ǿ����ϴ�." << endl<<endl;
			out.close();	//������ �ݴ´�.
			cout << "1.����ȭ�� 2.���ã�� ȭ�� 3.����==>";
			cin >> input2;	//�޴��� �Է¹޾� input2�� �����Ѵ�.
			if (input2 == 1)	//1�� �Է¹��� ��� ����
				MainHandler::StartMenu();	//�ʱ� �޴��� ���ư��� �Լ� ����
			else if (input2 == 2)	//2�� �Է¹��� ��� ����
				Favorites();	//���ã�� ����� �Լ� ����
			
			else if (input2 == 3)	//3�� �Է¹��� ��� ����
				exit(1);	//���α׷� ����
		}
		else {	//���̺���� ������ �Է¹��� �̸��� ���� �̸��� ���� ��� ����
			cout << "�ش� �̸��� �����ϴ�." << endl<<endl;
			out.close();	//������ �ݴ´�.
			cout << "1.����ȭ�� 2.���ã�� ȭ�� 3.����==>";
			
			cin >> input2;	//�޴��� �Է¹޾� input2�� �����Ѵ�.
			if (input2 == 1)	//1�� �Է¹��� ��� ����
				MainHandler::StartMenu();	//�ʱ� �޴��� ���ư��� �Լ� ����
			else if (input2 == 2)	//2�� �Է¹��� ��� ����
				Favorites();	//���ã�� ����� �Լ� ����

			else if (input2 == 3)	//3�� �Է¹��� ��� ����
				exit(1);	//���α׷� ����
		}

	}
	else if (input == 2) {	//���ã�� ���⸦ �����Ͽ��� ��� ����
		string tmp;		//���Ͽ��� �� �� �� ���� ���� �����ϱ� ���� ����
		ifstream in2("sitterFavorite.txt", ios::in);	//sitterFavorite.txt�� �б� ���� ����.
		
		if(in2.is_open() == false)	//���� ���� ������ ��� ����
			cout << "���� ���� ����";

		else {	//������ ������ ��� ����
			cout << "=====���ã��=====" << endl;
			while (true) {	//���� �ݸ� ����
				getline(in2, tmp);	//������ �� �� �� �о� tmp�� ����
				cout << tmp << endl;	//���� ���
				if (in2.eof())break;		//������ ������ �о����� �ݺ����� �����.
				
			}
			cout << "1.����ȭ�� 2.���ã�� 3.ä�� 4.���� ==>";
			cin >> input3;	//�Է¹��� ���� ������ ����
			if (input3 == 1)	//1�� �Է¹޾��� ��� ����
				MainHandler::StartMenu();	//�ʱ�޴��� ���ư������� �Լ� ����

			else if (input3 == 2) {	//2�� �Է� �޾��� ��� ����
				fname = "";		//���� �Է¹��� ���̺���� �̸��� null�� �Ѵ�.
				this->Favorites();	//���ã�� ����� �Լ� ����
			}
			else if (input3 == 3)	//3�� �Է� �޾��� ��� ����
				this->Chatting();	//ä�� ��� �Լ� ����

			else if (input3 == 4)	//4�� �Է� �޾��� ��� ����
				exit(0);			//���α׷��� ����ȴ�.

		}
		in2.close();	//������ �ݴ´�.
	}
}
void Parent::Join() {	//ȸ�� ���� �Լ�
	string id,pwd,name,age,sex,child_name,child_age,child_sex,number;	//ȸ�������� �����ϱ� ���� ����
	cout << "���̵� �Է��ϼ���==>";
	cin >> id;	//���̵� �Է¹޾� ������ ����
	this->setID(id);	//��ü�� ���̵� ���� set�Ѵ�.
	cout << "�н����带 �Է��ϼ���==>";
	cin >> pwd;	//�н����带 �Է¹޾� ������ ����
	this->setPwd(pwd);	//��ü�� �н����� ���� set�Ѵ�.
	cout << "����ó�� �Է��ϼ���==>";
	cin >> number;	//����ó�� �Է¹޾� ������ ����
	this->setNumber(number);	//��ü�� ����ó ���� set�Ѵ�.
	cout << "�̸��� �Է��ϼ���==>";
	cin >> name;	//�̸��� �Է¹޾� ������ ����
	this->setName(name);	//��ü�� �̸� ���� set�Ѵ�.
	cout << "���̸� �Է��ϼ���==>";
	cin >> age;	//���̸� �Է¹޾� ������ ����
	this->setAge(age);	//��ü�� ���� ���� set�Ѵ�.
	cout << "������ �Է��ϼ���==>";
	cin >> sex;	//������ �Է¹޾� ������ ����
	this->setSex(sex);	//��ü�� ���� ���� set�Ѵ�.
	cout << "������ �̸��� �Է��ϼ���==>";
	cin >> child_name;	//������ �̸��� �Է¹޾� ������ ����
	this->setChild_name(child_name);	//��ü�� ������ �̸� ���� set�Ѵ�.
	cout << "������ ���̸� �Է��ϼ���==>";
	cin >> child_age;	//������ ���̸� �Է¹޾� ������ ����
	this->setChild_age(child_age);	//��ü�� ������ ���� ���� set�Ѵ�.
	cout << "������ ������ �Է��ϼ���==>";
	cin >> child_sex;		//������ ������ �Է¹޾� ������ ����
	this->setChild_sex(child_sex);	//��ü�� ������ ���� ���� set�Ѵ�.

}
void Parent::Set() {		//ȸ�������� ���Ͽ� ���� �ϴ� �Լ�
		ofstream out("parent.txt", ios_base::out | ios_base::app);	//parent.txt������ ����,append���� ����
		if (out.is_open() == false)	//���� ���� ���� �� ��� ����
			cout << "File open failed";
		out << this->getID() << " ";			//���Ͽ� ���̵� ���� ����.
		out << this->getPwd() << " ";			//���Ͽ� �н����� ���� ����.
		out << this->getNumber() << " ";		//���Ͽ� ����ó ���� ����.
		out << this->getName() << " ";			//���Ͽ� �̸� ���� ����.
		out << this->getAge() << " ";			//���Ͽ� ���� ���� ����.
		out << this->getSex() << " ";			//���Ͽ� ���� ���� ����.
		out << this->getChild_name() << " ";	//���Ͽ� ������ �̸� ���� ����.
		out << this->getChild_age() << " ";		//���Ͽ� ������ ���� ���� ����.
		out << this->getChild_sex() << " ";		//���Ͽ� ������ ���� ���� ����.
		out << endl;	//�� �ٲ�
		out.close();	//������ �ݴ´�.

		ofstream out2("parentInfo.txt", ios_base::out | ios_base::app);	////parentIfo.txt������ ����,append���� ����
		if (out2.is_open() == false)	//���� ���� ���� �� ��� ����
			cout << "File open failed";
		out2 << this->getName() << " ";			//���Ͽ� �̸� ���� ����.
		out2 << this->getAge() << " ";			//���Ͽ� ���� ���� ����.
		out2 << this->getSex() << " ";			//���Ͽ� ���� ���� ����.
		out2 << this->getChild_name() << " ";	//���Ͽ� ������ �̸� ���� ����.
		out2 << this->getChild_age() << " ";		//���Ͽ� ������ ���� ���� ����.
		out2 << this->getChild_sex() << " ";		//���Ͽ� ������ ���� ���� ����.
		out2 << endl;	//�� ���
		out2.close();	//������ �ݴ´�.
}
void Parent::Login() {	//�α��� ����� �ϴ� �Լ�
	string pid;		//�Է� ���� ���̵� ���� ���� �ϱ� ���� ����
	string ppwd;	//�Է� ���� �н����� ���� ���� �ϱ� ���� ����
	string line;	//������ �� ������ �о� ������ ����
	int menu;		//�޴��� �Է¹��� ���� 
	char id[10];	//���Ͽ��� ���̵��� �о� ������ char�� �迭 ����
	char pwd[10];	//���Ͽ��� �н����尪�� �о� ������ char�� �迭 ����
	unordered_map<string, string> map1;	//unordered_map ���� map1 ����
	
	cout << "���̵� �Է��ϼ���==>";
	cin >> pid;	//���̵� ���� �Է� �޾� ������ ����
	cout << "�н����带 �Է��ϼ���==>";
	cin >> ppwd;	//�н����� ���� �Է� �޾� ������ ����
	

	ifstream in("parent.txt", ios::in);	//parent.txt ������ �б� ���� ����.
	if (in.is_open() == false)	//���� ���� ���� �� ��� ����
		cout << "���� ���� ����";
	else {	//������ ���� ��� ����
		while(!in.eof()){	//������ ������ �ݺ�
			in >> id>>pwd;	//������ ���̵𰪰� �н����� ���� ���� id,pwd�� ����
			map1[id] = pwd;	//���̵��� key���� �н����� ���� value���� ����
			getline(in, line);	//�� �� �� �о� ���� line�� ����
			if (in.eof())	//������ ������ ������ �ݺ��� ����
				break; 
		}
		if (!(map1.find(pid) == map1.end())) {	//�Է¹��� ���̵� ���� ���� �Ұ�� ����
			if (map1.find(pid)->second == ppwd) {	//�Է¹��� �н����� ���� ���� �� ��� ����
				cout << endl << "=====" << pid << "�� " << "ȯ���մϴ�.=====" << endl << endl;
				Show();	//���̺� ���� ������ �����ִ� �Լ� ����
			}
			else {	//�Է¹��� ���̵� ���� ���� ���� ���� ��� ����
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
			else {
					cout << "���̵� Ȥ�� �н����带 �߸��Է��Ͽ����ϴ�." << endl<<endl;
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
	in.close();		//������ �ݴ´�.
}
void Parent::Chatting() {
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
	cout << "Parent==>";
	getline(cin, chat);		//chat������ �Է¹��� ���� ����
	getline(cin, chat);		//���۸� �ѹ� ���� ���� ���
	out << "Parent==>" << chat << endl;	//���Ͽ� �Է��� ������ ����.
	out.close();	//������ �ݴ´�.
	Show();	//���̺���� ������ �����ִ� �Լ� ����
	
}
Parent::~Parent()
{
}

