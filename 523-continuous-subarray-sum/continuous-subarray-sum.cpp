class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        //remainder , index
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i-1]+ nums[i];
        }
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            nums[i] %= k;
            if(mp.find(nums[i])!=mp.end()){
                if(i-mp[nums[i]] >= 2) return true;
            }else{
                mp[nums[i]] = i;
            }
        }
        return false;
      
        
    }
};