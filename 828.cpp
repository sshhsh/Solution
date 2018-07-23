//
// Created by zhucebiao on 2018/7/23.
//
#include <string>
#include <iostream>

using namespace std;

int unique(string& s, int len){
    int count[26]={0};
    int tmp = 0;
    int sum = 0;
    for(int i=0;i<s.length();++i){
        if(count[s[i]-'A'] == 1)
            --tmp;
        ++count[s[i]-'A'];
        if(count[s[i]-'A'] == 1)
            ++tmp;
        if(i == len - 1)
            sum += tmp;
        if(i>=len){
            if(count[s[i-len]-'A'] == 1)
                --tmp;
            --count[s[i-len]-'A'];
            if(count[s[i-len]-'A'] == 1)
                ++tmp;
            sum += tmp;
        }
    }

    return sum%1000000007;
}

int uniqueLetterString(string S) {
    int sum = 0;
    for(int i = 1; i <= S.length(); ++i)
        sum+=unique(S, i);
    return sum%1000000007;
}

int main(){
    int res = uniqueLetterString("ABIQWGIQWGRIQUBFUASBFIASUDHOIWQNFOIWHFOIASFOIHWIHFOANFIA");
    cout << res;
}