// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


#include <vector>
using namespace std;    

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    // i -> points to the last valid element of nums1
    int i = m - 1;

    // j -> points to the last element of nums2
    int j = n - 1;

    // k -> points to the last position of nums1
    // where we will place the next largest element
    int k = m + n - 1;


    // Continue until one of the arrays is exhausted
    while(i >= 0 && j >= 0){

        // Compare the largest remaining elements
        if(nums1[i] > nums2[j]){

            // nums1[i] is larger
            // Put it at position k
            nums1[k] = nums1[i];

            // Move i left because we used nums1[i]
            i--;
        }
        else{

            // nums2[j] is larger (or equal)
            // Put it at position k
            nums1[k] = nums2[j];

            // Move j left because we used nums2[j]
            j--;
        }

        // One position is filled
        // Move k left
        k--;
    }


    // If nums2 still has elements left,
    // copy them into nums1
    while(j >= 0){

        nums1[k] = nums2[j];

        j--;
        k--;
    }
}