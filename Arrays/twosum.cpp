#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){

        int complement = target - nums[i];

        if(mp.find(complement) != mp.end()){
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
    }
};

int main() {
    int target = 9;
    vector<int> nums = {2, 7, 11, 15};

    Solution sol;  // Create object

    vector<int> ans = sol.twoSum(nums, target);

    cout << "Indices: ";
    for(int index : ans) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}