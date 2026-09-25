class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v=heights;
        sort(heights.begin(), heights.end());
        int ct = 0;
        for(int i=0;i<v.size();i++){
            if(heights[i]!=v[i]){
                ct++;
            }
        }
        return ct;
    }
};