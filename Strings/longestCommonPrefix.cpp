// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix=strs[0];
    for(int i=1;i<strs.size();i++){
        int l=min(prefix.size(),strs[i].size());
        int j=0;
        while(j<l && prefix[j]==strs[i][j]){
            j++;
        }   
        prefix=prefix.substr(0,j);
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl; // Output: "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs2) << endl; // Output: ""
    return 0;
}