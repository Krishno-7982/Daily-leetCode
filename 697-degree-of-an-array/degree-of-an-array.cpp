
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;

        int degree = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (freq[x] == 0) {
                first[x] = i;
            }

            freq[x]++;
            last[x] = i;

            degree = max(degree, freq[x]);
        }

        int ans = nums.size();

        for (auto &p : freq) {
            int x = p.first;

            if (p.second == degree) {
                int len = last[x] - first[x] + 1;
                ans = min(ans, len);
            }
        }

        return ans;
    }
};
