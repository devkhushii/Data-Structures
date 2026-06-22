// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

#include <bits/stdc++.h>
using namespace std;    

vector<int> rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k is larger than n
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[(i + k) % n] = nums[i];
    }
    return result;
}
vector<int> rotateInPlace(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k is larger than n
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    return nums;
} 

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    vector<int> result = rotate(nums, k);
    vector<int> resultInPlace = rotateInPlace(nums, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < resultInPlace.size(); i++) {
        cout << resultInPlace[i] << " ";
    }
    return 0;
}