#pragma once

class Fraction {

	/*
	
		num    - числитель
		denum  - знаменатель
		factor - целая часть

	*/

private:

	int \
		num    = 1,\
		denum  = 1,\
		factor = 0;  

	char comment[64] = "N/A";
  

	friend int CommonDenum(int left, int right);
	void Reduce();

public:

	Fraction(int num, int denum, int factor = 0);
	Fraction(int num, int denum, char factor);

	int getNum();
	int getDenum();
	int getFactor();

	void ShowFraction();

	bool RemoveFactor();
	bool ReturnFactor();
	
	Fraction operator--();
	Fraction operator--(int notused);
	Fraction operator=(Fraction &right);

	bool operator==(Fraction &right);
	bool operator!=(Fraction &right);
	friend Fraction operator+(Fraction &left, Fraction &right);
	
	
};

int CommonDenum(int left, int right);

Fraction operator+(Fraction& left, Fraction& right);
Fraction operator*(Fraction& victim, Fraction& mltplr);
