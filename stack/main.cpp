
#include <iostream>
#include <cstdlib>
#include "Stack.h"
#include "windows.h"
#include "triangle.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	/*STACK Stack;
	Stack.initial(); // �������������(���������� NULL ������� ��������)
	Stack.Push(1); // ���������� �������� � ����
	Stack.Push(15);
	
	Stack + 6; // ���������� �������� � ����
	Stack + 10;
	
	--Stack; // �������� Pop - ������ �������(� ������ ������ 10)

	Stack.OutPut(); // ����� ����� �� �����

	if (Stack.operator bool()) // ���������� ��������� bool
	{
		cout <<"\nStack is empty!\n\n"<< endl;
	}
	else
	{
		cout <<"\nStack is not empty!\n\n"<< endl;
	}
	
	STACK test;
	test.initial();
	Stack > test; // ����������� �� ����������� �� ������ ����
	test.OutPut(); */

	Triangle a(0,0,0,3,3,0), b(0, 0, 0, 6, 6, 0), c(0, 0, 0, 4, 4, 0);
	a.Length();
	b.Length();
	c.Length();
	cout << "��������� : " << endl;
	cout << a.GetPer() << endl;
	cout << b.GetPer() << endl;
	cout << c.GetPer() << endl;
	
	
	STACK<Triangle> test;
	test.Push(a);
	test.Push(b);
	test.Push(c);
	cout << Bigger<STACK<Triangle>>(test, 7) << endl;
	
	/*STACK<int> test2;
	test2.Push(123);
	test2.Push(100);
	test2.Push(70);
	cout << Bigger<STACK<int>>(test2, 80) << endl;
	*/


	system("pause");

}