class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        bool isOdd = false;

        unordered_map<char,int>mp;
        for(auto x: s){
            mp[x]++;
        }

        for(auto [ch,freq]: mp){
            if(freq%2==0){
                count = count+freq;
            }else{
                count = count + freq - 1;
                isOdd = true;
            }
        }

        return isOdd==true?count+1:count;
    }
};