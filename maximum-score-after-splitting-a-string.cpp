/*
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3
*/

//Approach 1 - O(N^2)
class Solution {
public:
    int maxScore(string s) {
        // max sum is the sum of number of zeros in left substring and number of ones in right substr
        
        int sum = INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            int count_zero = 0;
            int count_one = 0;
            for(int j=0;j<=i;j++){
                if(s[j]=='0'){
                    count_zero+=1;
                }
            }

            for(int j=i+1;j<s.size();j++){
                if(s[j]=='1'){
                    count_one+=1;
                }
            }
            // if(count_one==0||count_zero==0){
            //     return s.size()-1;
                
            // }
            sum = max(sum, count_zero+count_one);
            
        }
        
        return sum;

    }
};
//Approach 2: O(N) + O(N) two pass solution
class Solution {
public:
    int maxScore(string s) {
        int total_one = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                total_one++;
            }
        }

        if(total_one==0){
            return s.size()-1;
        }

        int zeros=0, ones=0;
        int sum = INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
             if(s[i]=='1'){
                ones++;
            }

            sum = max(sum , zeros + (total_one-ones));
        }
        return sum;
    }
};

//Approach 3: O(N) solution
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int res = INT_MIN;

        int zeros=0, ones = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                ones++;
            }else{
                zeros++;
            }

            res = max(res, (zeros-ones));
        }
        if(s[n-1]=='1'){
            ones++;
        }
        return res+ones;

    }

};
