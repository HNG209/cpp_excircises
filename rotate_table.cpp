#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void rotate90(char& c, char query) {
	if (query == 'L') {
		switch (c)
		{
		case '^':
			c = '<';
			break;
		case '<':
			c = 'v';
			break;
		case 'v':
			c = '>';
			break;
		case '>':
			c = '^';
			break;
		}
	}
	if (query == 'R') {
		switch (c)
		{
		case '^':
			c = '>';
			break;
		case '>':
			c = 'v';
			break;
		case 'v':
			c = '<';
			break;
		case '<':
			c = '^';
			break;
		}
	}

}
vector<string> rotate(vector<string> v, string query) {
	vector<string> temp = v;
	for (int i = 0; i < query.length(); i++) {
		if (query[i] == 'L') {
			vector<string> t = temp;
			vector<string> ::iterator it = t.begin();
			temp.erase(temp.begin(), temp.end());
			for (int a = (*it).size() - 1; a >= 0; a--) {
				string s;
				for (it = t.begin(); it != t.end();++it) {
					s += (*it)[a];
				}
				temp.push_back(s);
			}
			for (auto _i = temp.begin(); _i != temp.end(); ++_i) {
				for (int a = 0; a < (*_i).size(); a++) {
					rotate90((*_i)[a], query[i]);
				}
			}
		}
		if (query[i] == 'R') {
			vector<string> t = temp;
			vector<string> ::iterator it = t.begin();
			temp.erase(temp.begin(), temp.end());
			int size = (*it).size();
			for (int a = 0; a < size; a++) {
				string s;
				for (it = t.end(); it != t.begin();) {
					--it;
					s += (*it)[a];
				}
				temp.push_back(s);
			}
			for (auto _i = temp.begin(); _i != temp.end(); ++_i) {
				for (int a = 0; a < (*_i).size(); a++) {
					rotate90((*_i)[a],'R');
				}
			}
		}
	}
	return temp;
}
//Overloaded method
vector<string> rotate(vector<string> v, char query) {
	vector<string> temp = v;
		if (query == 'L') {
			vector<string> t = temp;
			vector<string> ::iterator it = t.begin();
			temp.erase(temp.begin(), temp.end());
			for (int a = (*it).size() - 1; a >= 0; a--) {
				string s;
				for (it = t.begin(); it != t.end(); ++it) {
					s += (*it)[a];
				}
				temp.push_back(s);
			}
			for (auto _i = temp.begin(); _i != temp.end(); ++_i) {
				for (int a = 0; a < (*_i).size(); a++) {
					rotate90((*_i)[a], query);
				}
			}
		}
		if (query == 'R') {
			vector<string> t = temp;
			vector<string> ::iterator it = t.begin();
			temp.erase(temp.begin(), temp.end());
			int size = (*it).size();
			for (int a = 0; a < size; a++) {
				string s;
				for (it = t.end(); it != t.begin();) {
					--it;
					s += (*it)[a];
				}
				temp.push_back(s);
			}
			for (auto _i = temp.begin(); _i != temp.end(); ++_i) {
				for (int a = 0; a < (*_i).size(); a++) {
					rotate90((*_i)[a], query);
				}
			}
	    }
	return temp;
}
int main() {
	vector<string> s{ "v.v","v.v","v.v" };
	vector<string> v = s;
	string query = "LRLLRL";
	printf_s("code build success!!");
	//for (int i = 0; i < query.length(); i++) {
	//	v = rotate(v, query[i]);
	//	cout << "rotate 90 degrees to the " << query[i] << endl;
	//	for (const auto& it : v) {
	//		cout << it << '\n';
	//	}
	//}
	return 0;
}