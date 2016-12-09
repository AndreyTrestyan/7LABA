#pragma once
#include <iostream>
#include <windows.h>
#include "triangle.h"
#define N 1024 // ����������� ���������� ����������� ���������� ���������� �������� ��� �����
using namespace std;


template <class T>
struct ELEMENT
{
	T Content;
	ELEMENT *Next;
	ELEMENT<T>() {};
	ELEMENT<T>(ELEMENT<T> &obj)
	{
		Content = obj.Content;
		Next = obj.Next;
	}
};




template <class T>
class STACK
{
private:
	int numberofelements = 0; // ���������� ��������� �� ���������
public:

	void initial();
	int Push(T Content);
	int Pop(T &Content);
	bool Empty(int Content);
	int Full(int Content);
	void OutPut();
	ELEMENT<T>* Start;


	friend STACK<T> operator + (STACK<T>& x, const int n)
	{
		x.Push(n);
		return x;
	}

	friend STACK<T> operator--(STACK<T>& x)
	{
		int n = 1;
		x.Pop(n);
		return x;
	}

	operator bool() const
	{

		if (!Start || Start == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	STACK<T> operator>(STACK<T>& y)
	{
		int i = 0;
		if (!Start)
		{
			printf("���� ����\n");
			return y;
		}
		int *n = new int[numberofelements];
		ELEMENT<T>* Temp = Start;
		while (Temp)
		{
			n[i] = Temp->Content;
			i++;
			Temp = Temp->Next;
		}

		int k, p, flag = 1;
		int temp;
		int numLength = numberofelements;
		for (k = 1; (k <= numLength) && flag; k++)
		{
			flag = 0;
			for (p = 0; p < (numLength - 1); p++)
			{
				if (n[p + 1] > n[p])
				{
					temp = n[p];
					n[p] = n[p + 1];
					n[p + 1] = temp;
					flag = 1;
				}
			}
		}

		int u = 0;
		Temp = Start;
		while (Temp)
		{
			y.Push(n[u]);
			u++;
			Temp = Temp->Next;
		}
		delete[]n;
		return y;
	}
};




template <class T>
void STACK<T>::initial() //������������� ������� ��������
{
	Start = NULL;
}

template <class T>
bool STACK<T>::Empty(int Content) //�������� �� �������
{
	if (Content == 0)
		return true;
	else
		return false;

}

template <class T>
int STACK<T>::Full(int Content) // �������� �� �������
{
	if (Content == N)
		return 1;
	else
		return 0;

}

template <class T>
int STACK<T>::Push(T Content) // �������� ������� �� ����
{
	ELEMENT<T>* NE = new ELEMENT<T>;
	if (!NE)
		return 0;
	NE->Content = Content;
	NE->Next = Start;
	Start = NE;
	numberofelements++;
	return 1;
}

template <class T>
int STACK<T>::Pop(T &Content) // ������� ������� � ��������
{
	if (!Start)
		return 0;
	Content = Start->Content;
	int k = Start->Content;
	ELEMENT<T>* Temp = Start;
	Start = Start->Next;
	delete Temp;
	numberofelements--;
	return k;
}

template <class T>
void STACK<T>::OutPut() // ����� ����� �� �������
{
	if (!Start)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	ELEMENT<T>* Temp = Start;
	while (Temp)
	{
		cout << Temp->Content << endl;
		Temp = Temp->Next;
	}
	cout << "\n\n" << endl;

}
