#include<iostream>
using namespace std;
bool is_prime(int x) {
	if (x == 0 || x == 1) {
		return false;
	}
	if (x < 0) {
		return false;
	}
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
void out_arr(int* arr,int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\t';
	}
}
void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int a, b;//lower bound,upper bound
	int arr[1000];//store prime numbers
	int count = 0;//count for each index
	cout << "lower bound:";
	cin >> a;
	cout << "upper bound:";
	cin >> b;
	if (a > b) {
		swap(a, b);
	}
	for (int i = a; i < b; i++) {
		if (is_prime(i)) {
			arr[count] = i;
			count++;
		}
	}
	cout << "there are " << count << " prime numbers in array" << endl;
	out_arr(arr, count);
	return 0;
}