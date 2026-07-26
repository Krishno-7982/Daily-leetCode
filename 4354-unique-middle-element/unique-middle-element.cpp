class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        vector<int>hsh(101);
        for(int i=0;i<nums.size();i++){
            hsh[nums[i]]++;
        }
        return hsh[nums[nums.size()/2]]==1;
    }
};