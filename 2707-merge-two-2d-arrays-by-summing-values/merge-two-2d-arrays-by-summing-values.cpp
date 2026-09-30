class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;

        for(auto num : nums2) {
            mp[num[0]] = num[1];
        }

        for(auto x : nums1) {
            if(mp.count(x[0])) {
                ans.push_back({x[0], x[1] + mp[x[0]]});
                mp.erase(x[0]);   // important
            }
            else {
                ans.push_back(x);
            }
        }

        for(auto &[x, c] : mp) {
            ans.push_back({x, c});
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};