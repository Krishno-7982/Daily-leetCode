class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>&path,vector<int>&nums,int start, int k){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(path, nums, i+1, k);
            path.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums(n);
        for(int i = 0;i<n;i++){
            nums[i]=i+1;
        }
        vector<int>path;
        
        backtrack(path,nums, 0, k);
        return ans;
    }
};