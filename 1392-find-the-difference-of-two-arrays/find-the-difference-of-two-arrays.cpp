class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int x : nums1)
            mp1[x]++;

        for (int x : nums2)
            mp2[x]++;

        vector<vector<int>> ans(2);

        for (auto& [x, freq] : mp1) {
            if (!mp2.count(x))
                ans[0].push_back(x);
        }

        for (auto& [x, freq] : mp2) {
            if (!mp1.count(x))
                ans[1].push_back(x);
        }

        return ans;
    }
};