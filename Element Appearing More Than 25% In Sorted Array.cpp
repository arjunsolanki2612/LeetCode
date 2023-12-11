/*
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1

*/
// as the arr is sorted we just have to check whether the element is occuring more than n/4 times so we have to check weather the element are in the range if it is then it is the number otherwise there
// no number
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), t = n/4;

        for(int i=0;i<n-t;i++){
            if(arr[i]==arr[i+t]){
                return arr[i];
            }
        }
        return -1;
    }
};
