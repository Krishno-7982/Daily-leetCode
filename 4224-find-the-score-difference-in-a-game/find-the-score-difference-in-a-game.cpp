class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1_score = 0, p2_score = 0;
        bool p1_active = true;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 != 0) {
                p1_active = !p1_active;
            }

            if ((i + 1) % 6 == 0) {
                p1_active = !p1_active;
            }

            if (p1_active)
                p1_score += nums[i];
            else
                p2_score += nums[i];
        }

        return p1_score - p2_score;
    }
};