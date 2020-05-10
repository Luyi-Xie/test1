#include <iostream>
#include <string>

using namespace std;

/*//利用普通写法和多态技术实现计算器类

//普通写法
class  Calculator{
public:
	int m_NUM1;
	int m_NUM2;
	int getResult(string oper){
		if (oper == "+") return m_NUM1 + m_NUM2;
		else if (oper == "-") return m_NUM1 - m_NUM2;
		else if (oper == "*") return m_NUM1 * m_NUM2;
		//如果想扩展新的功能，需要修改源码
		//在真实的开发中，提倡开闭原则
		//开闭原则：对扩展进行开放，对修改进行关闭
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

//利用多态实现计算器

//实现计算器抽象类
//多态好处：
//1.组织结构清晰
//2.可读性强
//3.对于前期和后期扩展以及维护性高
class AbstractCalculator{
public:
	virtual int getResult(){
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

//设计加法计算器类
class AddCalculator :public AbstractCalculator{
public:
	int getResult(){
		return m_Num1 + m_Num2;
	}
};

//设计减法计算器类
class SubCalculator :public AbstractCalculator{
public:
	int getResult(){
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class MulCalculator :public AbstractCalculator{
public:
	int getResult(){
		return m_Num1 * m_Num2;
	}
};

void test02(){
	//多态使用条件
	//父类的指针或者引用指向子类对象

	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;

	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//乘法原酸
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


/*//纯虚函数
class Base{
public:
	virtual void func() = 0;//纯虚函数
	//只要又一个纯虚函数这个类称为抽象类
	//抽象类特点：
	//1.无法实例化对象（栈上和堆区都不行）
	//
};

//子类必须重写父类中的纯虚函数，否则子类也为抽象类
class Son :public Base{
public:
	void func(){ cout << "函数调用" << endl; }
};




void test01(){
	//Base b;		//抽象类无法实例化对象
	//new Base;	//堆区也无法实例化对象
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

/*//多态案例2
class AbstractDrinking{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	void makeDrink(){
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffe :public AbstractDrinking{
public:
	//煮水
	virtual void Boil(){
		cout << "煮农夫山泉" << endl;
	}
	//冲泡
	virtual void Brew(){
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup(){
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething(){
		cout << "放入砂糖和牛奶" << endl;
	}
};

//泡茶
class Tea :public AbstractDrinking{
public:
	//煮水
	virtual void Boil(){
		cout << "煮农矿泉水" << endl;
	}
	//冲泡
	virtual void Brew(){
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup(){
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething(){
		cout << "放入柠檬" << endl;
	}
};

void doWork(AbstractDrinking* abc){
	abc->makeDrink();
	delete abc;//释放
}

void test01(){
	//制作咖啡
	doWork(new Coffe);
	cout << "------------------" << endl;
	//泡茶
	doWork(new Tea);
}

int main(){
	test01();
	int n; cin >> n;
	return 0;
}*/

/*//虚析构和纯虚析构
class Animal{
public:
	Animal(){
		cout << "Animal构造" << endl;
	}
	//纯虚函数
	virtual void speak() = 0;
	//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	/*virtual ~Animal(){
		cout << "Animal析构" << endl;
	}
	//必须有代码实现 不然会报错
	//有了纯虚析构以后这个类也属于抽象类，无法实例化对象
	//1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
	//2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
	//3.拥有纯虚析构函数的类也属于抽象类
	virtual ~Animal() = 0;

};

Animal::~Animal(){ cout << "Animal纯虚析构" << endl; }

class Cat :public Animal{
public:
	Cat(string name){
		cout << "cat构造" << endl;
		m_Name = new string(name);
	}
	virtual void speak(){
		cout << *m_Name <<"：喵喵喵喵喵" << endl;
	}
	string* m_Name;
	~Cat(){
		if (m_Name != NULL){
			cout << "Cat析构" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};

void test01(){
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构时不会调用子类中析构函数，导致子类如果有堆区属性，造成内存泄露
	delete animal;
}


int main(){
	test01();
	int n; cin >> n;
	return 0;
}*/

//电脑组装案例

//抽象不同零件类
class CPU{
public:
	//抽象计算函数
	virtual void calculate() = 0;
};

class VideoCard{
public:
	//抽象显示函数
	virtual void display() = 0;
};

class Memory{
public:
	//抽象存储函数
	virtual void storage() = 0;
};

//电脑类
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
		if (cpu != NULL){ cout << "cpu停止工作" << endl; delete cpu; cpu = NULL; }
		if (vc != NULL){ cout << "显卡停止工作" << endl; delete vc; vc = NULL; }
		if (mem != NULL){ cout << "内存条停止工作" << endl; delete mem; mem = NULL; }
	}
private:
	CPU* cpu;//CPU的的零件指针
	VideoCard* vc;//显卡零件指针
	Memory* mem;//内存条零件指针
};

//intel零件
class intelCPU:public CPU{
public:
	//抽象计算函数
	virtual void calculate() {
		cout << "intel的CPU开始计算了" << endl;
	}
};

class intelVideoCard :public VideoCard{
public:
	//抽象显示函数
	virtual void display() {
		cout << "intel的显卡开始工作了" << endl;
	}
};

class intelMemory :public Memory{
public:
	//抽象存储函数
	virtual void storage(){
		cout << "intel的内存条开始工作了" << endl;
	}
};

//Lenovo零件
class LenovoCPU :public CPU{
public:
	//抽象计算函数
	virtual void calculate() {
		cout << "Lenovo的CPU开始计算了" << endl;
	}
};

class LenovoVideoCard :public VideoCard{
public:
	//抽象显示函数
	virtual void display() {
		cout << "Lenovo的显卡开始工作了" << endl;
	}
};

class LenovoMemory :public Memory{
public:
	//抽象存储函数
	virtual void storage(){
		cout << "Lenovo的内存条开始工作了" << endl;
	}
};

void test(){
	//第一台电脑，使用Intel零件
	CPU* cp = new intelCPU;
	VideoCard* vd = new intelVideoCard;
	Memory* me = new intelMemory;

	computer computer1(cp, vd, me);
	computer1.work();

	//第二台电脑，使用Lenovo零件
	computer computer2(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2.work();

	//第三胎电脑，使用混合零件
	computer computer3(new LenovoCPU, new intelVideoCard, new LenovoMemory);
	computer3.work();

}

int main(){
	test();
	int n; cin >> n;
	return 0;
}
