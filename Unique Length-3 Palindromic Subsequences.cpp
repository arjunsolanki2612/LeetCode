//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/submissions/1098719802/?envType=daily-question&envId=2023-11-14
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>indices(26,{-1,-1});
        // precompute the first and the last indexes of the character
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int idx = ch-'a';
            
            if(indices[idx].first==-1){
                indices[idx].first=i;
            }
            indices[idx].second=i;
        }

        int result=0;
        for(int i=0;i<26;i++){
            // har ek letter ko moka dena h ki iss letter se palindrome ban sakta h ki nhi
            int right_idx = indices[i].first;
            int left_idx = indices[i].second;

            if(left_idx==-1){
                continue;
            }

            unordered_set<char>st;
            for(int mid = right_idx+1; mid<=left_idx-1; mid++){
                st.insert(s[mid]);
            }
            result+=st.size();
        }
        return result;
    }
};

----------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>letters;
        for(int i=0;i<s.size();i++){
            letters.insert(s[i]);
        }
        int result=0;
        for(auto lttr : letters){
            // har ek letter ko moka dena h ki iss letter se palindrome ban sakta h ki nhi
            int firstIdx = -1;
            int lastIdx = -1;
            for(int i=0;i<s.size();i++){
                if(lttr == s[i]){
                    if(firstIdx==-1){
                        firstIdx=i;
                    }
                     lastIdx = i;
                }
               
            }

            unordered_set<char>st;
            for(int mid = firstIdx+1; mid<=lastIdx-1; mid++){
                st.insert(s[mid]);
            }
            result+=st.size();
        }
        return result;
    }
};
