
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        int diff = (sumB - sumA) / 2;

        unordered_set<int> st(bobSizes.begin(), bobSizes.end());

        for (int x : aliceSizes) {
            int y = x + diff;

            if (st.count(y)) {
                return {x, y};
            }
        }

        return {};
    }
};
