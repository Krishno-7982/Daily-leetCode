class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int sum = 0;
        

        for(int i = 0; i < nums.size(); i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        
        int rows = nums.size();
        int cols = nums[0].size();
        

        for(int j = 0; j < cols; j++) {
            int max_val = 0;
            
           
            for(int i = 0; i < rows; i++) {
                max_val = max(max_val, nums[i][cols - 1 - j]);
            }
            
            sum += max_val;
        }
        
        return sum;
    }
};