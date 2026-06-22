// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> answer(n, 1);
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    int i=1,j=n-2;
    while(i<n){
        left[i] = left[i-1]*nums[i-1];
        right[j] = right[j+1]*nums[j+1];
        i++;
        j--;    
}

    for(int i=0;i<n;i++){
        answer[i] = left[i]*right[i];
    }
    return answer;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}