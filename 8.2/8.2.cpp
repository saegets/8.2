//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... . Вилучити з
//цієї послідовності групи символів, які знаходяться між дужками «(», «)».Самі дужки теж
//мають бути вилучені.Вважається, що всередині кожної пари дужок нема інших дужок.Якщо
//всередині деякої пари дужок є пара інших дужок(вкладені дужки), то виводиться
//повідомлення про помилку.

#include <iostream>
#include <string>
using namespace std;

int brCount(string& s)
{
	bool check;
	size_t pos = 0;
	int k1 = 0;
	int k2 = 0;
	while ((pos = s.find('(', pos)) != -1)
	{
		k1++;
		pos++;
	}
	if (k1 > 1)
	{
		pos = 0;
		while ((pos = s.find(')', pos)) != -1)
		{
			k2++;
			pos++;
		}
	}

	if (k1 > 1 && k2 > 1)
		check = true;
	else 
		check = false;
	return check;

}

string Delete(string& s)
{
	size_t pos = s.find("(");
	size_t pos2 = s.find(")", pos + 1);
		s = s.erase(pos, pos2 - pos + 1);
		return s;
}

int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	if(brCount(str))
		cout << endl << "______________________________________________________________________________" << endl
					 << "ERROR! string contains brackets in brackets, or more than one pair of brackets" << endl
					 << "______________________________________________________________________________" << endl;
	else
		cout << Delete(str) << endl;
}

