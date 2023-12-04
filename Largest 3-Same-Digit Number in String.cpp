/*
https://leetcode.com/problems/largest-3-same-digit-number-in-string/submissions/1112248181?envType=daily-question&envId=2023-12-04
2264. Largest 3-Same-Digit Number in String

Easy
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
*/

class Solution {
public:
    string largestGoodInteger(string num) {
        
        int ans = INT_MIN;
        int i=0;
        while(i<num.size()){
            char numAti = num[i];
            if( num[i+1]==numAti && num[i+2]==numAti){
                int val = numAti - '0';
                if(val>ans){
                    ans=val;
                }
                i=i+3;
            }else{
                i++;
            }
        }

        if(ans==INT_MIN){
            return "";
        }

        string str="";
        char ch = ans + '0';
        for(int i=0;i<3;i++){
            str.push_back(ch);
        }
        return str;


    }
};
