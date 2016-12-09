
#include <iostream>
#include <cstdlib>
#include "Stack.h"
#include "windows.h"
#include "triangle.h"

using namespace std;

template <class T>
int Bigger(T obj, int n)
{
	int i = 0;
	T * temp = &obj;
	while (temp)
	{
		if (temp->Content > n)
		{
			i++;
		}
		temp = temp->Next;
	}
	return i;
}

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
	cout << c.GetPer() << endl << endl;
	
	
	STACK<Triangle> test;
	test.Push(a);
	test.Push(b);
	test.Push(c);
	cout << "Result for Triangle: " << Bigger<ELEMENT<Triangle>>(*(test.Start), 7) << endl << endl;
	
	STACK<int> test2;
	test2.Push(123);
	test2.Push(100);
	test2.Push(70);
	cout << "Result for int: " << Bigger<ELEMENT<int>>(*(test2.Start), 80) << endl;
	


	system("pause");

}