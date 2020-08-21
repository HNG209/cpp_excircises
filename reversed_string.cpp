#include<iostream>
#include<vector>
#include<string>
using namespace std;
void reverse(string& s) {
	string temp;
	for (int i = s.size() - 1; i >= 0; i--) {
		temp += s[i];
	}
	s.erase(s.begin(), s.end());
	s = temp;
}
int main() {
	string s = "Hung dep trai";
	reverse(s);
	cout << s << endl;
	return 0;
}