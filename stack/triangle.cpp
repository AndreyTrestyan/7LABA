#include "triangle.h"
#include <iostream>
using namespace std;

int Triangle::counter;

Triangle::Triangle()
{
	Counter();
}


Triangle::Triangle(int x1, int x2, int x3, int y1, int y2, int y3)
{
	x_[0] = x1;
	x_[1] = x2;
	x_[2] = x3;
	y_[0] = y1;
	y_[1] = y2;
	y_[2] = y3;
	Counter();
}


Triangle::Triangle( Triangle &obj)
{
	x_[0] = obj.x_[0];
	x_[1] = obj.x_[1];
	x_[2] = obj.x_[2];
	y_[0] = obj.y_[0];
	y_[1] = obj.y_[1];
	y_[2] = obj.y_[2];

	Counter();
}


Triangle::~Triangle()
{
	counter--;
}



void Triangle::SetXY(int X, int X2, int X3, int Y, int Y2, int Y3)
{
	x_[0] = X;
	x_[1] = X2;
	x_[2] = X3;
	y_[0] = Y;
	y_[1] = Y2;
	y_[2] = Y3;
}



int Triangle::GetXY()
{
	return x_[0], x_[1], x_[2], y_[1], y_[2], y_[0];
}


void Triangle::Counter()
{
	counter++;
}



void Triangle::Length()
{
	for (int i = 0; i <= 2; i++)
	{
		if (i == 2) {
			length[i] = sqrt(pow((x_[0] - x_[i]), 2) + pow(y_[0] - y_[i], 2));
			break;
		}
		length[i] = sqrt(pow((x_[i + 1] - x_[i]), 2) + pow(y_[i + 1] - y_[i], 2));
		if (length[i]<0)
		{
			cout << "ERROR, one length less then 0" << endl;
		}

	}
}

bool Triangle::Ravnost()
{
	return (length[0] == length[1]) & (length[1] == length[2]) & (length[2] == length[0]);
}


bool Triangle::Ravnobed()
{
	return (((length[0] == length[1]) & (length[0] != length[2])) |
		((length[1] == length[2]) & (length[1] != length[0])) |
		((length[2] == length[0]) & (length[1] != length[0])));
}




bool Triangle::Pryamoug()
{
	return (length[0] == sqrt(pow(length[1], 2) + pow(length[2], 2))) ||
		(length[1] == sqrt(pow(length[0], 2) + pow(length[2], 2))) ||
		(length[2] == sqrt(pow(length[1], 2) + pow(length[0], 2)));
}

bool Triangle::Proizvol()
{
	return ((length[0] != length[1]) & (length[0] != length[2]) & (length[2] != length[1]) &
		(length[0] != (sqrt(pow(length[1], 2) + pow(length[2], 2)))) &
		(length[1] != (sqrt(pow(length[0], 2) + pow(length[2], 2)))) &
		(length[2] != (sqrt(pow(length[1], 2) + pow(length[0], 2)))));
}



bool Triangle::CheckTriangle()
{
	return (((length[0] + length[1]) < length[2]) || ((length[0] + length[2]) < length[1]) | ((length[1] + length[2]) < length[0]));
}


double Triangle::GetPer()
{
	Length();
	return length[0] + length[1] + length[2];
}

bool Triangle::operator>(int &n)
{
	if (GetPer() > n)
	{
		return true;
	}

	else
	{
		return false;
	}
}







