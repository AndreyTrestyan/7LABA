#pragma once


class Triangle
{
private:
	double length[3];
	static int counter;
	int GetXY();
	static void Counter();
	static const int numberlenght = 3; // количество длин сторон константно  == 3 
	int x_[3], y_[3];

public:
	bool Ravnost();
	bool Pryamoug();
	bool Proizvol();
	bool Ravnobed();
	void Length(); // + lenght check (if < 0  - ERROR)
	bool CheckTriangle();
	int GetPer();
	Triangle(int, int, int, int, int, int);
	Triangle( Triangle &obj);
	Triangle();
	~Triangle();
	void SetXY(int X, int X2, int X3, int Y, int Y2, int Y3);
	bool operator>(int &n);


};