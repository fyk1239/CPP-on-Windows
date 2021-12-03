// 文件路径名: calculator\calculator.h
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "linstack.h" // 链栈类

// 计算器类
class Calculator
{
private:
	// 辅助函数:
	static bool IsOperator(char ch);												// 判断字符ch是否为操作符
	static char Precede(char theta1, char theta2);									// 判断相继出现的操作符theta1和theta2的优先级
	static double Operate(double left, char theta, double right);					// 执行运算left theta right
	static void Get2Operands(LinkStack<double> &opnd, double &left, double &right); // 从栈opnd中退出两个操作数

public:
	// 接口方法声明:
	Calculator(){};			 // 无参数的构造函数
	virtual ~Calculator(){}; // 析构函数
	static void Run();		 // 执行表达式求值计算
};

// 计算器类的实现部分
bool Calculator::IsOperator(char ch)
// 操作结果：判断ch是否为操作符
{
	if (ch == '=' || ch == '(' || ch == '^' || ch == '*' ||
		ch == '/' || ch == '%' || ch == '+' || ch == '-' || ch == ')')
		return true;
	else
		return false;
};

char Calculator::Precede(char theta1, char theta2)
// 操作结果：判断相继出现的操作符theta1和theta2的优先级
{
	// 对各种可能theta1与theta2之值进行穷举
	if (theta1 == '+' && theta2 == '+')
		return '>';
	else if (theta1 == '+' && theta2 == '-')
		return '>';
	else if (theta1 == '+' && theta2 == '*')
		return '<';
	else if (theta1 == '+' && theta2 == '/')
		return '<';
	else if (theta1 == '+' && theta2 == '(')
		return '<';
	else if (theta1 == '+' && theta2 == ')')
		return '>';
	else if (theta1 == '+' && theta2 == '=')
		return '>';
	else if (theta1 == '-' && theta2 == '+')
		return '>';
	else if (theta1 == '-' && theta2 == '-')
		return '>';
	else if (theta1 == '-' && theta2 == '*')
		return '<';
	else if (theta1 == '-' && theta2 == '/')
		return '<';
	else if (theta1 == '-' && theta2 == '(')
		return '<';
	else if (theta1 == '-' && theta2 == ')')
		return '>';
	else if (theta1 == '-' && theta2 == '=')
		return '>';
	else if (theta1 == '*' && theta2 == '+')
		return '>';
	else if (theta1 == '*' && theta2 == '-')
		return '>';
	else if (theta1 == '*' && theta2 == '*')
		return '>';
	else if (theta1 == '*' && theta2 == '/')
		return '>';
	else if (theta1 == '*' && theta2 == '(')
		return '<';
	else if (theta1 == '*' && theta2 == ')')
		return '>';
	else if (theta1 == '*' && theta2 == '=')
		return '>';
	else if (theta1 == '/' && theta2 == '+')
		return '>';
	else if (theta1 == '/' && theta2 == '-')
		return '>';
	else if (theta1 == '/' && theta2 == '*')
		return '>';
	else if (theta1 == '/' && theta2 == '/')
		return '>';
	else if (theta1 == '/' && theta2 == '(')
		return '<';
	else if (theta1 == '/' && theta2 == ')')
		return '>';
	else if (theta1 == '/' && theta2 == '=')
		return '>';
	else if (theta1 == '(' && theta2 == '+')
		return '<';
	else if (theta1 == '(' && theta2 == '-')
		return '<';
	else if (theta1 == '(' && theta2 == '*')
		return '<';
	else if (theta1 == '(' && theta2 == '/')
		return '<';
	else if (theta1 == '(' && theta2 == '(')
		return '<';
	else if (theta1 == '(' && theta2 == ')')
		return '=';
	else if (theta1 == '(' && theta2 == '=')
		return 'e';
	else if (theta1 == ')' && theta2 == '+')
		return '>';
	else if (theta1 == ')' && theta2 == '-')
		return '>';
	else if (theta1 == ')' && theta2 == '*')
		return '>';
	else if (theta1 == ')' && theta2 == '/')
		return '>';
	else if (theta1 == ')' && theta2 == '(')
		return 'e';
	else if (theta1 == ')' && theta2 == ')')
		return '>';
	else if (theta1 == ')' && theta2 == '=')
		return '>';
	else if (theta1 == '=' && theta2 == '+')
		return '<';
	else if (theta1 == '=' && theta2 == '-')
		return '<';
	else if (theta1 == '=' && theta2 == '*')
		return '<';
	else if (theta1 == '=' && theta2 == '/')
		return '<';
	else if (theta1 == '=' && theta2 == '(')
		return '<';
	else if (theta1 == '=' && theta2 == ')')
		return 'e';
	else if (theta1 == '=' && theta2 == '=')
		return '=';
};

double Calculator::Operate(double left, char theta, double right)
// 操作结果：执行运算left op right
{
	double result;
	if (theta == '+')
		result = left + right; // 加法运算
	else if (theta == '-')
		result = left - right; // 减法运算
	else if (theta == '*')
		result = left * right; // 乘法运算
	else if (theta == '/' && right == 0)
		throw "除数为零!"; // 抛出异常
	else if (theta == '/' && right != 0)
		result = left / right; // 除法运算
	else if (theta == '%' && (long)right == 0)
		throw "除数为零!"; // 抛出异常
	else if (theta == '%' && (long)right != 0)
		result = (long)left % (long)right; // 整除运算
	else if (theta == '^')
		result = pow(left, right); // 乘方运算
	return result;				   // 返回result
}

void Calculator::Get2Operands(LinkStack<double> &opnd, double &left, double &right)
// 操作结果：从栈opnd中退出两个操作数
{
	if (opnd.Pop(right) != SUCCESS)
		throw Error("表达式有错!"); // 抛出异常
	if (opnd.Pop(left) != SUCCESS)
		throw Error("表达式有错!"); // 抛出异常
}

void Calculator::Run()
// 操作结果:按算符优先法进行表达式求值计算
{
	LinkStack<double> opnd; // 操作数栈
	LinkStack<char> optr;	// 操作符栈
	optr.Push('=');			// 在optr栈中加入一个'='
	char ch;				// 临时字符
	char optrTop;			// 临optr栈的栈顶字符
	double operand;			// 操作数
	char theta;				// 操作符

	cin >> ch; // 从输入流获取一字符ch
	while ((optr.Top(optrTop), optrTop != '=') || ch != '=')
	{
		if (!IsOperator(ch))
		{						// ch不是操作符
			cin.putback(ch);	// 将字符ch放回输入流
			cin >> operand;		// 读操作数operand
			opnd.Push(operand); // 进入opnd栈
			cin >> ch;			// 读入下一字符ch
		}
		else
		{ // ch是操作符
			switch (Precede(optrTop, ch))
			{
			case '<':		   // 栈顶操作符优先级低
				optr.Push(ch); // ch入optr栈
				cin >> ch;	   // 从输入流中取下一字符ch
				break;
			case '=': // 栈顶操作符与ch优先级相等
				if (ch == ')')
				{					   // 此时optrTop == '('
					optr.Pop(optrTop); // 去括号
					cin >> ch;		   // 从输入流中取下一字符ch
				}
				break;
			case '>':									// 栈顶操作符优先级高
				double left, right;						// 操作数
				Get2Operands(opnd, left, right);		//取出两个操作数
				optr.Pop(theta);						// 从optr栈退出theta
				opnd.Push(Operate(left, theta, right)); // 运算结果进入opnd栈
				break;
			case 'e': // 操作符匹配错
				cout << "操作符匹配错" << endl;
				exit(2);
			}
		}
	}

	opnd.Top(operand); // opnd栈的栈顶元素为表达式的值
	cout << "表达式值为:" << operand << endl;
}

#endif