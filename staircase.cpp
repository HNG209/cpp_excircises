#include<iostream>
using namespace std;
void staircase(int n) {
    int j = 0;
    for(int i = n;i > 0;i--){
        for(j = 1;j < i;j++){
            cout << " ";
        }
        do{
            cout << "#";
        }
        while(j++ < n);
        j = 0;
        cout << endl;
    }
}
int main(){
    int t = 0;
    cout << "enter looping time:";
    cin >> t;
    while(t--){
        cout << "enter n:";
        int n;
        cin >> n;
        cout << "your staircase:\n";
        staircase(n);
    }
    return 0;
}