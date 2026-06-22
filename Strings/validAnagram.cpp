// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

#include <bits/stdc++.h>
using namespace std;    

bool isAnagram(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

bool isAnagram1(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
        mp[t[i]]--;
    }
    for(auto it:mp){
        if(it.second!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    bool result = isAnagram(s,t);
    cout<<result;
    return 0;
}