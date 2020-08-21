#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> v{ 1,-2,-3,4,5,-6 };
	vector<int> tempo;
	for (int i = 0; i < v.size(); i++) {
		int sum{};
		for (int j = i; j < v.size(); j++) {
			sum += v[j];
			tempo.push_back(sum);
		}
	}
	auto max = std::max_element(tempo.begin(), tempo.end());
	for (const auto& i : tempo) {
		cout << i << '\t';
	}
	cout << endl;
	printf_s("max is:%d", *max);
	return 0;
}