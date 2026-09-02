class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] < k){
                ans.push_back(nums[i]);
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};