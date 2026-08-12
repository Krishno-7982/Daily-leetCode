class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int left = 0, maxlength = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[left]]--;
                left++;      
            }
            maxlength = max(maxlength, i-left + 1);
        }
        return maxlength;
    }
};