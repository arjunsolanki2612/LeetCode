class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;

        int l=0, r=0;
        unordered_map<char,int> st;

        while(r<s.size()){

            if(st.find(s[r])!=st.end()){
                if(st[s[r]]>=l){
                    l = st[s[r]] + 1;
                }
            }
               
               len = max(len,r-l+1);
               st[s[r]] = r;
               r++;

        }
        return len;
    }
};