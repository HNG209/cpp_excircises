#include<iostream>
#include<vector>
using namespace std;
//function definition
bool check_uppercase(char);//kiểm tra chữ hoa
void check_whitespace(string&);//kiểm tra khoảng trắng
void trim_whitespace(string&);//cắt khoảng trắng đầu dòng
inline char toUppercase(char);//in hoa chữ cái
inline char toLowercase(char);//in thường chữ cái
void encode(string&);//mã hóa
bool check_uppercase(char c) {
	return (c < 91 && c > 64) ? true : false;//true if character has uppercase,else false if character has lowercase
}
void check_whitespace(string& s) {
	int whitespace_count = 0;
	vector<string> temp;
	string new_string;
	string s_temp;
	int count = 0;
	for (int i = 0; i <= s.length(); i++) {
		if (i == s.length()) {
			temp.push_back(s_temp);
		}
		else {
		if (s[i] != ' ') {
			count = 0;
			s_temp += s[i];
		}
		else {
			count++;
			if (count < 2) {
				temp.push_back(s_temp);
				s_temp = "";
			}
		}
		}
	}
	int size_of_temp = temp.size();
	vector<string>::iterator it;
	//dùng để kiểm tra kí tự đầu của mỗi từ xem đã được in hoa chưa
	for (it = temp.begin(); it != temp.end(); ++it) {
		if (!check_uppercase((*it)[0])) {//nếu chưa thì in hoa lên
			(*it)[0] = toUppercase((*it)[0]);
		}
	}
	for (int i = 0; i < size_of_temp; i++) {
		if (true) {
			new_string += temp[i];
		}
		new_string += ' ';
	}
	s = new_string;
}
void trim_whitespace(string& s) {//cắt khoảng trắng đầu dòng
	int i = 0;
	string new_string;
	while (s[i] == ' ') {
		++i;
	}
	for (int j = i; j < s.length(); j++) {
		new_string += s[j];
	}
	s = new_string;
}
inline char toUppercase(char c) {
	return c - 32;//tra bảng ASCII để biết thêm
}
inline char toLowercase(char c) {
	return c + 32;//tra bảng ASCII để biết thêm
}
void encode(string& s) {
	string new_string;
	trim_whitespace(s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			if(s[i] < 65 || s[i] > 90){//lower cases
				if (s[i] < 97 || s[i] > 122) {
					//s[i] = ' ';
				}
				else {
					new_string += s[i];
				}
			}
			else {
				new_string += s[i];
			}
		}
		else {
			new_string += s[i];
		}
	}
	for (int i = 0; i < new_string.length(); i++) {
		if (check_uppercase(new_string[i])) {
			new_string[i] = toLowercase(new_string[i]);
		}
	}
	check_whitespace(new_string);
	if (!check_uppercase(new_string[0])){//first character of string must be uppercased
		toUppercase(new_string[0]);
	}
	s = new_string;
}
int main() {
	string s = "   627hell*o&&**))(9      w897or98898ld m3y nam32e i21s Hu89ng";
	string s2 = "my n?><:'|~ame is!@#$%^&*(),_+}{][\ HUNG";
	string s3 = "d89JT   M((*)e)) M76^7ay";
	cout << "input string:" << s3 << endl;
	encode(s3);
	cout << "output string:" << s3 << endl;
	return 0;
}