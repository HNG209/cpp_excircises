#include<iostream>
using namespace std;
void trim(string& s,char c){
    s += c;
}
void trim_whitespace(string& s){
    int count = 0;
    string temp;
    while(count < s.length()){
        if(s[count] != ' '){
            temp += s[count];
        }
        ++count;
    }
    s = temp;
}
int onesAndZeros(string& s)
{
    trim(s,' ');
    for(int i = 0;i < s.length() - 1;i++){
        if(s[i] == ' '){
            i++;
        }
        char first_digit = s[i];
        char second_digit = s[i+1];
        if(first_digit == '0'){
            if(second_digit == '1'){
                s[i] = ' ';
                s[i+1] = ' ';
            }
        }
        if(first_digit == '1'){
            if(second_digit == '0'){
                s[i] = ' ';
                s[i+1] = ' ';
            }
        }
    }
    trim_whitespace(s);
    return s.length();
}
int main(){
    int t = 0;
    cout << "enter looping time:";
    cin >> t;
    while(t--){
        string s;
        cout << "enter your string:";
        cin >> s;
        cout << "size:" << onesAndZeros(s) << endl;
        cout << "character left:" << s << endl;
    }
    return 0;
}