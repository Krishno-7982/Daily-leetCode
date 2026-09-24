class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bit = 0;bit<32;bit++){
            int ct = 0;
            for(auto x : nums){
                if(x & (1<<bit)){
                    ct++;
                }
            }

            if(ct%3 != 0){
                ans |= (1<<bit);
            }
        }
        return ans;
    }
};