class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(stoi(nums[i],0,2)); // string to integer convert 
            //first parameter = the string you wanna convert
            //second parameter = the index you will start from
            //third parameter = shows the base of the number in this case it is binary
        }

        string result="";
        for(int num=0;num<=n;num++){
            if(st.find(num)==st.end()){
                result = bitset<16>(num).to_string();
                return result.substr(16-n,n);
            }
        }
        return "";
    }
};
