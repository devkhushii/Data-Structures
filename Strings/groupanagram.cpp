
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]


#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
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
// Brute force solution
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    vector<bool> visited(strs.size(), false);
    for(int i=0;i<strs.size();i++){
        if(visited[i]){
            continue;
        }
        vector<string> temp;
        temp.push_back(strs[i]);
        visited[i] = true;
        for(int j=i+1;j<strs.size();j++){
            if(!visited[j] && isAnagram(strs[i], strs[j])){
                temp.push_back(strs[j]);
                visited[j] = true;
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
// Optimized solution using sorting and hash map
vector<vector<string>> groupAnagramsOptimized(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for(string s: strs){
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}


int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagramsOptimized(strs);
    for(auto it: ans){
        for(auto str: it){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}