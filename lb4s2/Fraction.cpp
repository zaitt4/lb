#include "Fraction.h"
#include <stdio.h>
#include <cmath>


int Fraction::getNum() {

	return num;
}


int Fraction::getDenum() {

	return denum;
}


int Fraction::getFactor() {

	return factor;
}


Fraction::Fraction(int num, int denum, int factor) {

	if (num < 0 && denum < 0) {

		num      = abs(num);
		denum    = abs(denum);
	}

	else if ((num < 0 || denum < 0) && factor != 0) {
		
		if (num < 0) {

			num    = abs(num);
			factor = -factor;
		}
		
		if (denum < 0) {

			denum  = abs(denum);
			factor = -factor;
		}
	}

	this->num    = num;
	this->denum  = denum;
	this->factor = factor;

	ShowFraction();
}


//Костыль недружественной функции
Fraction::Fraction(int num, int denum, char factor) {

	this->num   = num;
	this->denum = denum;

	if (factor == '~') {

		ReturnFactor();
		Reduce();
	}

}


//Преобразование в неправильную дробь
bool Fraction::RemoveFactor() {

	if (factor != 0) {

		num    += (denum * abs(factor));

		if (factor < 0)

			num = -num;

		factor  = 0;

		printf("\nУдалена целая часть: ");
		ShowFraction();

		return true;
	}

	printf("Дробь правильная\n");
	return false;
}


//Выделение целой части
bool Fraction::ReturnFactor() {

	if (abs(num) < abs(denum) || abs(num) == abs(denum) || abs(num) % abs(denum) == 0) {

		printf("Дробь правильная\n");
		return false;
	}

	if (factor == 0) {

		if (num < 0 || denum < 0) {

			factor = abs(num) / abs(denum);
			num    = abs(num) % abs(denum);

			factor = -factor;
		}

		else {

			factor = abs(num) / abs(denum);
			num    = abs(num) % abs(denum);
		}
		
		printf("\nВыделена целая часть: ");
		ShowFraction();

		return true;
	}

	printf("Дробь правильная\n");
	return false;
}


//Общий знаменатель
int CommonDenum(int left, int right) {

	int k;

	if (left < right) {

		k = left;
	}

	else {

		k = right;
	}

	while (true) {

		if (k % left == 0 && k % right == 0) {

			return k;
		}

		k++;
	}
}


void Fraction::ShowFraction() {

	if (factor == 0)

		printf("\nДробь %d/%d\n", num, denum);

	else

		printf("\nДробь %d*(%d/%d)\n", factor, num, denum);
}


//Сложение
Fraction operator+(Fraction& left, Fraction& right) {

	Fraction tmp;
	if (left.factor  != 0) left.RemoveFactor();
	if (right.factor != 0) right.RemoveFactor();

	int _denum = CommonDenum(abs(left.denum), abs(right.denum));

	tmp.num    = left.num * (_denum / left.denum) + right.num * (_denum / right.denum);
	tmp.denum  = _denum;

	tmp.ReturnFactor();
	tmp.Reduce();

	return tmp;
}


//Умножение
Fraction operator*(Fraction& victim, Fraction& mltplr) {

	if (victim.getFactor() != 0) victim.RemoveFactor();
	if (mltplr.getFactor() != 0) mltplr.RemoveFactor();

	int _num   = victim.getNum()   * mltplr.getNum();
	int _denum = victim.getDenum() * mltplr.getDenum();

	if (_num < 0 && _denum < 0) {

		_num   = abs(_num);
		_denum = abs(_denum);		
	}

	char spike = '~';
	Fraction tmp(_num, _denum, spike);

	return tmp;
}


//Сокращение
void Fraction::Reduce() {

	if (num != 0 && denum != 0) {

		int k = num;

		if (num > denum) {

			k = denum;
		}

		while (true) {

			if (num % k == 0 && denum % k == 0) {

				num   = num   / k;
				denum = denum / k;
				break;
			}

			k--;
		}
	}
}


//Декремент постфикс
Fraction Fraction::operator--() {

	ReturnFactor();

	if (factor != 0) {

		Reduce();
		factor -= 1;
	}
	
	else {

		Reduce();
		num    -= denum;
	}


	return *this;
}


Fraction Fraction::operator--(int notused) {

	Fraction tmp = *this;

	ReturnFactor();

	if (factor != 0) {

		Reduce();
		factor -= 1;
	}

	else {

		Reduce();
		num    -= denum;
	}


	return tmp;
}


Fraction Fraction::operator=(Fraction &right) {

	num    = right.num;
	denum  = right.denum;
	factor = right.factor;

	return *this;
}


bool Fraction::operator==(Fraction &right) {

	RemoveFactor(); right.RemoveFactor();
	Reduce();		right.Reduce();

	if (num == right.num && denum == right.denum && factor == right.factor) {

		return true;
	}

	return false;
}


bool Fraction::operator!=(Fraction &right) {

	RemoveFactor(); right.RemoveFactor();
	Reduce();		right.Reduce();

	if (num != right.num || denum != right.denum || factor != right.factor) {

		return true;
	}

	return false;
}
