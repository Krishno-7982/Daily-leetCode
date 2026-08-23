class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>& candidates, vector<int>& path, int target, int start){
        
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backtrack(candidates, path, target-candidates[i], i);
            path.pop_back();//backtracking
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        backtrack(candidates, path, target, 0);
        return ans;
    }
};