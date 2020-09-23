#include<iostream>
using namespace std;
template<typename T>
T reverseNumber(T n){
    int rslt{};
    while(n > 0){
        rslt = rslt * 10 + n % 10;
        n /= 10;
    }
    return rslt;
}
int main(){
    long long n = 1234567;
    cout << "your reverse number:" << reverseNumber(n) << endl;
    return 0;
}