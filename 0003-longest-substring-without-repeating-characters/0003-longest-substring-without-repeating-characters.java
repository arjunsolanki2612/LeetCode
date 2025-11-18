class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = 0; int l=0, r=0;
        Map<Character,Integer> mp = new HashMap<>();
        while(r<s.length()){
            char c = s.charAt(r);
            if(mp.containsKey(c)){
                if(mp.get(c)>=l){
                    l = mp.get(c) + 1;
                }
            }

            len = Math.max(len,r-l+1);
            mp.put(c,r);
            r++;
        } 
        return len;   
    }
}