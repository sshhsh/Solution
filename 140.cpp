//
// Created by zhucebiao on 2018/7/24.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> dict;

//bool check(string &s1, string &s2) {
//    if (s1.length() < s2.length())
//        return false;
//    int i;
//    for (i = 0; i < s2.length(); ++i) {
//        if (s1[i] != s2[i])
//            return false;
//    }
//    return true;
//}

//void walk(string &s, vector<string> &wordDict, vector<string> &sentences, string &sen) {
//    for (int i = 0; i < wordDict.size(); ++i) {
//        if (check(s, wordDict[i])) {
//            string s2 = s.substr(wordDict[i].length());
//            unsigned long len = sen.length();
//            if (!sen.empty())
//                sen.append(" ");
//            sen.append(wordDict[i]);
//            if (s2.empty())
//                sentences.push_back(sen);
//            walk(s2, wordDict, sentences, sen);
//            sen.erase(len);
//        }
//    }
//}

//vector<string> wordBreak(string s, vector<string> &wordDict) {
//    vector<string> sentences;
//    string sen;
//    walk(s, wordDict, sentences, sen);
//    return sentences;
//}
vector<string> wordBreak(string s, vector<string> &wordDict){
    if(dict.count(s))
        return dict[s];
    vector<string> res;
    for(int i=0;i<=s.length();++i){
        string start = s.substr(0,i);
        string remain = s.substr(i);
        if(find(wordDict.begin(),wordDict.end(),start)!=wordDict.end()){
            if(remain.empty())
                res.push_back(start);
            else{
                for(auto str : wordBreak(remain, wordDict)){
                    res.push_back(start + " " + str);
                }
            }
        }
    }
    dict[s]=res;
    return res;
}


int main() {
    vector<string> a = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> res = wordBreak("pineapplepenapple", a);
    return 0;
}