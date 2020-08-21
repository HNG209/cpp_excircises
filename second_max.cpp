#include<iostream>
#include<vector>
using namespace std;
int max;
int find_2nd_max(vector<int> arr) {
	int size;
	cout << "enter your array's size:";
	cin >> size;
	for (size_t i = 0; i < size; i++)
	{
		int temp;
		cout << "enter the " << i + 1 << " value:";
		cin >> temp;
		arr.push_back(temp);
	}
	int max = 0;
	vector<int> ::iterator it;
	it = arr.begin();
	while (it != arr.end())
	{
		if (*it > max) {
			max = *it;
		}
		++it;
	}
	int max_2nd = 0;
	it = arr.begin();
	while (it != arr.end()) {
		if (*it > max_2nd && *it != max)
		{
			max_2nd = *it;
		}
		++it;
	}
	return max_2nd;
}
int main() {
	vector<int> arr;
	cout << "max 2nd is " << find_2nd_max(arr);
	return 0;
}