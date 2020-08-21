#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string div_more_dec_point(int a, int b,int max_dec_point) 
{
    if (b == 0)
	{
		throw exception("can not be divided by 0");
	}
    int value = a / b;
	string s_value = to_string(value);
		if (a % b != 0)
		{
			s_value += '.';
			int surplus;//số dư
			surplus = (a % b) * 10;
			int dec_point;
			for (size_t i = 0; i < max_dec_point; i++)
			{
				dec_point = surplus % b;
				s_value += to_string(surplus / b);
				surplus = dec_point * 10;
				if (dec_point == 0)
				{
					return s_value;
				}
			}
		}
		else 
		{
			return s_value;
		}
	return s_value;
}
int main() 
{
	char option;
	do {
		try {//dùng try catch để xử lí ngoại lệ(chia cho 0)
			int a, b;
			int dec_point;
			cout << "enter the first value:";
			cin >> a;
			cout << "enter the second value:";
			cin >> b;
			cout << "how many decimal point do you want to have? \n>";
			cin >> dec_point;
			cout << "your value " << div_more_dec_point(a, b, dec_point) << endl;
		}
		catch (const std::exception& err) {
			cout << err.what() << endl;
		}
		cout << "begin?:[Y] / [N]:";
		cin >> option;
	} while (option != 'N');

	return 0;
}