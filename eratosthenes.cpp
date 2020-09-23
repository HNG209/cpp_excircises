#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> eratosthenes(int n){
    int k = 2;//first prime
    vector<bool> notPrime(n + 1,true);//because first index is 1,skip index 0
    vector<int> prime;
    while(true){
        if(k * k > n) break;//k² > n ->stop and filt prime numbers
        int i = 0;
        int p = k * (k + i);
        while(p <= n){
            notPrime.at(p) = false;
            i++;
            p = k * (k + i);
            if(p > n){
                k++;
            }
        }
    }
    for(int i = 2;i <= n;i++){
        if(notPrime.at(i) == true){
            prime.push_back(i);
        }
    }
    return prime;
}
int main(){
    cout << "enter range to find:";
    int n = 0;
    cin >> n;
    vector<int> prime = eratosthenes(n);
    for(const auto& i : prime){
        cout << i << '\t';
    }
    return 0;
}