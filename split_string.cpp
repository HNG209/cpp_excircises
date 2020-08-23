#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> string_split(string s){
    int count{};
    vector<string> vec;
    string temp;
    for(int i = 0;i <= s.length();i++){
        if(i == s.length()){
            vec.push_back(temp);
        }
        else{
            if(s[i] != ' '){//whitespace have not been detected
                count = 0;
                temp += s[i];//iterate and save each character
            }
            else{
                count++;
                if(count < 2){
                    vec.push_back(temp);
                    temp = "";
                }
            }
        }
    }
    return vec;
}
int main(){
    string s = "hello world I am   HungIT";//even when there were multi whitespace characters
    vector<string> split_str = string_split(s);
    for(const auto& i : split_str){
        cout << i << endl;//print out each word line by line
    }
    return 0;
}