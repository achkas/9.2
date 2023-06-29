// Перегрузка операторов 9.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction() = default;
	
	void set_numerator_(int numerator) { if (numerator > 0) numerator_ = numerator; }
	void set_denominator_(int denominator) { if (denominator > 0) denominator_ = denominator; }	
	
	int get_numerator_() { return numerator_; }
	int get_denominator_() { return denominator_; }	

	int nod(int a, int b) {
		while (b > 0) {
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}	

	int nok(int a, int s) {
		return nod(a, s) * a * s;
	}	

	void operator++()
	{
		numerator_ = numerator_ + denominator_;		
	}

	void operator++(int)
	{
		numerator_ = numerator_ + denominator_;
	}

	void operator--()
	{
		numerator_ = numerator_ - denominator_;
	}

	void operator--(int)
	{
		numerator_ = numerator_ - denominator_;
	}

	void operator-()
	{
		numerator_ = -numerator_;
		denominator_ = -denominator_;
	}	

	Fraction operator+(const Fraction& other) {
		int unionDenominator = nok(denominator_, other.denominator_);
		int relNumerator = numerator_ * other.denominator_;
		int mulNumerator = other.numerator_ * denominator_;
		numerator_ = relNumerator + mulNumerator;
		denominator_ = unionDenominator;
		int red = nod(abs(numerator_), (denominator_));
		if (red != 1) {
			numerator_ = numerator_ / red;
			denominator_ = denominator_ / red;
		}
		return /*Fraction(numerator_, denominator_)*/*this;
	}

	Fraction operator-(const Fraction& other) {
		int unionDenominator = nok(denominator_, other.denominator_);
		int relNumerator = numerator_ * other.denominator_;
		int mulNumerator = other.numerator_ * denominator_;
		numerator_ = relNumerator - mulNumerator;
		denominator_ = unionDenominator;
		int red = nod(abs(numerator_), (denominator_));
		if (red != 1) {
			numerator_ = numerator_ / red;
			denominator_ = denominator_ / red;
		}
		return /*Fraction(numerator_, denominator_)*/*this;
	}

	Fraction operator*(const Fraction& other) {
		int unionDenominator = denominator_* other.denominator_ ;
		int relNumerator = numerator_ * other.numerator_;		
		numerator_ = relNumerator ;
		denominator_ = unionDenominator;		
		int red = nod(abs(numerator_), (denominator_));
		if (red != 1) {numerator_ = numerator_ / red;
			           denominator_ = denominator_ / red;}
		return Fraction(numerator_, denominator_)/**this*/;
	}

	Fraction operator/(const Fraction& other) {		
		int relNumerator = numerator_ * other.denominator_;
		int muldenominator = other.numerator_ * denominator_;
		numerator_ = relNumerator ;
		denominator_ = muldenominator;
		int red = nod(abs(numerator_), (denominator_));
		if (red != 1) {
			numerator_ = numerator_ / red;
			denominator_ = denominator_ / red;
		}
		return /*Fraction(numerator_, denominator_)*/*this;
	}

	void print_info(Fraction*) {
		std::cout << get_numerator_()<<"/" << get_denominator_() << std::endl;

	}
};

int main()

{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction f1(1,1), f2(1,1); //<< std::endl	

	int numerator1, denominator1, numerator2, denominator2;

	std::cout << "Введите числитель дроби 1: " ;
	std::cin >> numerator1;
	f1.set_numerator_(numerator1);
	
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;
	f1.set_denominator_(denominator1);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	f2.set_numerator_(numerator2);

	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;
	f2.set_denominator_(denominator2);

	
	Fraction sum = f1 + f2;
	sum.print_info(&sum);

	/*std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " + "
	<< f2.get_numerator_() << "/" << f2.get_denominator_() << "= "
	<< sum.get_numerator_() << "/" << sum.get_denominator_() << std::endl;*/
	
	/*Fraction f4 = f1- f2;
	f4.print_info(&f4);*/

	/*Fraction f5 = f1 * f2;
	f5.print_info(&f5);*/

	/*Fraction f6 = f1 / f2;
	f6.print_info(&f6);*/

	/* ++f1;
	f1.print_info(&f1);*/

	/*--f1;
	f1.print_info(&f1);*/ 

	return 0;
}


