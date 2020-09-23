#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool checkUpper(char c){
    if(c >= 65 && c <= 90) return true;
    return false;
}
void toLower(char& c){
    if(checkUpper(c)) c = c + 32;
}
void toUpper(char& c){
    if(!checkUpper(c)) c = c - 32;
}
vector<string> split(string s){
    vector<string> temp;
    int i = 0;
    int count = 0;
    int last_count = 0;
    string t;
    if(checkUpper(s[0])) toUpper(s[0]);
    for(int i = 0;i < s.length();i++){
        if(checkUpper(s[i])){
            last_count = count;
            count++;
            toLower(s[i]);
            if(t != ""){
                temp.push_back(t);
                t = "";//refresh
            }
        }
        if(count != last_count){
            t += s[i];//iterate the string
        }
    }
    temp.push_back(t);
    return temp;
}
int main()
{
    vector<string> s = split("ILoveYouBaby");
    for(const auto& i : s){
        cout << i << endl;
    }
    return 0;
}