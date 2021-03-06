﻿// написать программу, находящую кол-во делителей натурального числа
#include <iostream>
#include <cmath>
using namespace std;

bool Simple (int x)		//Функция проверки числа на простоту
{	
	bool b = true;
	int n = sqrt(x);
	for (int i = 2; b == true && i <= n; i++ )
	{
		if (x % i == 0) 
		{
		  b = false;	
		}
	}
	return b;
}

void Divisors (int x) 		//Процедура нахождения всех делителей составного числа
{
	int n = x/2;
	for (int i = 1; i <= n; i++)
		if (x % i == 0) cout << i << " ";
	cout << x;	
}

int main() 
{
	int x;
	cin >> x;		//Вводим число
	if (Simple(x)) 		//Проверяем на простоту
	{
	  cout << "Simple" << endl;
	  cout << 1 << " " << x;
	} else 
	{ 
	  cout << "Compound" << endl;
	  Divisors(x);
	}		
	return 0;
}