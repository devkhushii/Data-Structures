#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int SubArraySumEqualK(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // Initialize with sum 0 having one occurrence

    for (int num : nums) {
        sum += num;
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }
        prefixSumCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = SubArraySumEqualK(nums, k);
    cout << "Number of subarrays with sum equal to " << k << ": " << result << endl;
    return 0;
}