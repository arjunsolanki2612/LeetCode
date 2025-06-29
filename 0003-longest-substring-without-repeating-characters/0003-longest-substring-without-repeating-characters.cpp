class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;

        int l=0, r=0;
        unordered_set<char> st;

        while(r<s.size()){

            while(st.find(s[r])!=st.end()){
                
                st.erase(s[l]);
                l++;
            }
               st.insert(s[r]);
               len = max(len,r-l+1);
               r++;

        }
        return len;
    }
};