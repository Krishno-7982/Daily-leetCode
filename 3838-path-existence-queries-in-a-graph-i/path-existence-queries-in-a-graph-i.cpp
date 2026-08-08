class Solution {
public:
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>components(n);
        int comp = 0;
        components[0]=comp;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                comp++;
            }
            components[i]=comp;
        }
        vector<bool>ans;
        for(auto query : queries){
            int u = query[0];
            int v = query[1];
            if(components[u]==components[v]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};