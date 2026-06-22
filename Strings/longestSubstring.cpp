

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int left = 0;
    int right = 0;
    int max_length = 0;
    while (right < s.length()) {
        if (st.find(s[right]) == st.end()) {
            st.insert(s[right]);
            right++;
            max_length = max(max_length, right - left);
        } else {
            st.erase(s[left]);
            left++;
        }
    }
    return max_length;
}   

string LongestSubstring(string s) {
    unordered_set<char> st;
    int left = 0;
    int right = 0;
    int max_length = 0;
    string longest_substring = "";
    while (right < s.length()) {
        if (st.find(s[right]) == st.end()) {
            st.insert(s[right]);
            right++;
            if (right - left > max_length) {
                max_length = right - left;
                longest_substring = s.substr(left, max_length);
            }
        } else {
            st.erase(s[left]);
            left++;
        }
    }
    return longest_substring;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    string longest_substring = LongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    cout << "Longest substring without repeating characters: " << longest_substring << endl;
    return 0;
}