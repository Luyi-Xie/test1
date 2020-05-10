#include <iostream>
#include <string>

using namespace std;

/*//������ͨд���Ͷ�̬����ʵ�ּ�������

//��ͨд��
class  Calculator{
public:
	int m_NUM1;
	int m_NUM2;
	int getResult(string oper){
		if (oper == "+") return m_NUM1 + m_NUM2;
		else if (oper == "-") return m_NUM1 - m_NUM2;
		else if (oper == "*") return m_NUM1 * m_NUM2;
		//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
		//����ʵ�Ŀ����У��ᳫ����ԭ��
		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
	}
};

void test01(){
	Calculator c;
	c.m_NUM1 = 10;
	c.m_NUM2 = 10;

	cout << c.m_NUM1 << "+" << c.m_NUM2 << "=" << c.getResult("+") << endl;
	cout << c.m_NUM1 << "-" << c.m_NUM2 << "=" << c.getResult("-") << endl;
	cout << c.m_NUM1 << "*" << c.m_NUM2 << "=" << c.getResult("*") << endl;
}

//���ö�̬ʵ�ּ�����

//ʵ�ּ�����������
//��̬�ô���
//1.��֯�ṹ����
//2.�ɶ���ǿ
//3.����ǰ�ںͺ�����չ�Լ�ά���Ը�
class AbstractCalculator{
public:
	virtual int getResult(){
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

//��Ƽӷ���������
class AddCalculator :public AbstractCalculator{
public:
	int getResult(){
		return m_Num1 + m_Num2;
	}
};

//��Ƽ�����������
class SubCalculator :public AbstractCalculator{
public:
	int getResult(){
		return m_Num1 - m_Num2;
	}
};

//�˷���������
class MulCalculator :public AbstractCalculator{
public:
	int getResult(){
		return m_Num1 * m_Num2;
	}
};

void test02(){
	//��̬ʹ������
	//�����ָ���������ָ���������

	//�ӷ�����
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//�����ǵ�����
	delete abc;

	//��������
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//�˷�ԭ��
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
}
int main(){
	test02();
	int n; cin >> n;
	return 0;
}*/


/*//���麯��
class Base{
public:
	virtual void func() = 0;//���麯��
	//ֻҪ��һ�����麯��������Ϊ������
	//�������ص㣺
	//1.�޷�ʵ��������ջ�ϺͶ��������У�
	//
};

//���������д�����еĴ��麯������������ҲΪ������
class Son :public Base{
public:
	void func(){ cout << "��������" << endl; }
};




void test01(){
	//Base b;		//�������޷�ʵ��������
	//new Base;	//����Ҳ�޷�ʵ��������
	Son s;
	Base* base = new Son;
	base->func();
	delete base;
}


int main(){
	test01();
	int n = 0; cin >> n;
	return 0;
}*/

/*//��̬����2
class AbstractDrinking{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	void makeDrink(){
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffe :public AbstractDrinking{
public:
	//��ˮ
	virtual void Boil(){
		cout << "��ũ��ɽȪ" << endl;
	}
	//����
	virtual void Brew(){
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup(){
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething(){
		cout << "����ɰ�Ǻ�ţ��" << endl;
	}
};

//�ݲ�
class Tea :public AbstractDrinking{
public:
	//��ˮ
	virtual void Boil(){
		cout << "��ũ��Ȫˮ" << endl;
	}
	//����
	virtual void Brew(){
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup(){
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void PutSomething(){
		cout << "��������" << endl;
	}
};

void doWork(AbstractDrinking* abc){
	abc->makeDrink();
	delete abc;//�ͷ�
}

void test01(){
	//��������
	doWork(new Coffe);
	cout << "------------------" << endl;
	//�ݲ�
	doWork(new Tea);
}

int main(){
	test01();
	int n; cin >> n;
	return 0;
}*/

/*//�������ʹ�������
class Animal{
public:
	Animal(){
		cout << "Animal����" << endl;
	}
	//���麯��
	virtual void speak() = 0;
	//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
	/*virtual ~Animal(){
		cout << "Animal����" << endl;
	}
	//�����д���ʵ�� ��Ȼ�ᱨ��
	//���˴��������Ժ������Ҳ���ڳ����࣬�޷�ʵ��������
	//1.�������������������������ͨ������ָ���ͷ��������
	//2.���������û�ж������ݣ����Բ�дΪ��������������
	//3.ӵ�д���������������Ҳ���ڳ�����
	virtual ~Animal() = 0;

};

Animal::~Animal(){ cout << "Animal��������" << endl; }

class Cat :public Animal{
public:
	Cat(string name){
		cout << "cat����" << endl;
		m_Name = new string(name);
	}
	virtual void speak(){
		cout << *m_Name <<"������������" << endl;
	}
	string* m_Name;
	~Cat(){
		if (m_Name != NULL){
			cout << "Cat����" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};

void test01(){
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ��������ʱ�����������������������������������ж������ԣ�����ڴ�й¶
	delete animal;
}


int main(){
	test01();
	int n; cin >> n;
	return 0;
}*/

//������װ����

//����ͬ�����
class CPU{
public:
	//������㺯��
	virtual void calculate() = 0;
};

class VideoCard{
public:
	//������ʾ����
	virtual void display() = 0;
};

class Memory{
public:
	//����洢����
	virtual void storage() = 0;
};

//������
class computer{
public:
	computer(CPU* m_cpu, VideoCard* m_vc, Memory* m_mem){
		cpu = m_cpu;
		vc = m_vc;
		mem = m_mem;
	}

	void work(){
		cpu->calculate();
		vc->display();
		mem->storage();
	}
	~computer(){
		if (cpu != NULL){ cout << "cpuֹͣ����" << endl; delete cpu; cpu = NULL; }
		if (vc != NULL){ cout << "�Կ�ֹͣ����" << endl; delete vc; vc = NULL; }
		if (mem != NULL){ cout << "�ڴ���ֹͣ����" << endl; delete mem; mem = NULL; }
	}
private:
	CPU* cpu;//CPU�ĵ����ָ��
	VideoCard* vc;//�Կ����ָ��
	Memory* mem;//�ڴ������ָ��
};

//intel���
class intelCPU:public CPU{
public:
	//������㺯��
	virtual void calculate() {
		cout << "intel��CPU��ʼ������" << endl;
	}
};

class intelVideoCard :public VideoCard{
public:
	//������ʾ����
	virtual void display() {
		cout << "intel���Կ���ʼ������" << endl;
	}
};

class intelMemory :public Memory{
public:
	//����洢����
	virtual void storage(){
		cout << "intel���ڴ�����ʼ������" << endl;
	}
};

//Lenovo���
class LenovoCPU :public CPU{
public:
	//������㺯��
	virtual void calculate() {
		cout << "Lenovo��CPU��ʼ������" << endl;
	}
};

class LenovoVideoCard :public VideoCard{
public:
	//������ʾ����
	virtual void display() {
		cout << "Lenovo���Կ���ʼ������" << endl;
	}
};

class LenovoMemory :public Memory{
public:
	//����洢����
	virtual void storage(){
		cout << "Lenovo���ڴ�����ʼ������" << endl;
	}
};

void test(){
	//��һ̨���ԣ�ʹ��Intel���
	CPU* cp = new intelCPU;
	VideoCard* vd = new intelVideoCard;
	Memory* me = new intelMemory;

	computer computer1(cp, vd, me);
	computer1.work();

	//�ڶ�̨���ԣ�ʹ��Lenovo���
	computer computer2(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2.work();

	//����̥���ԣ�ʹ�û�����
	computer computer3(new LenovoCPU, new intelVideoCard, new LenovoMemory);
	computer3.work();

}

int main(){
	test();
	int n; cin >> n;
	return 0;
}
