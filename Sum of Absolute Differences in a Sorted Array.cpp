/*
1685. Sum of Absolute Differences in a Sorted Array
https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=daily-question&envId=2023-11-25
You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

 

Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        vector<int>prefixSum(n);

        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++){
            //result[i] = (nums[i]*i) + (0 to i-1 ka sum) + (i+1 to n-1 ka sum) + (nums[i]*(n-i-1))

            int leftSum = prefixSum[i]-nums[i];
            int rightSum = prefixSum[n-1]-prefixSum[i];

            result[i]= (nums[i]*i) - leftSum + rightSum - (nums[i]*(n-i-1));
        }
        return result;
    }
};

// Approach 2: Without extra space
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        
        int sum =  accumulate(begin(nums),end(nums),0);
        int prefixSum = 0;
        for(int i=0;i<n;i++){

            //result[i] = (nums[i]*i) + (0 to i-1 ka sum) + (i+1 to n-1 ka sum) + (nums[i]*(n-i-1))

            int leftSum = prefixSum;
            int rightSum = sum - prefixSum-nums[i];

            result[i]= (nums[i]*i) - leftSum + rightSum - (nums[i]*(n-i-1));
            prefixSum+=nums[i];
        }
        return result;
    }
};

