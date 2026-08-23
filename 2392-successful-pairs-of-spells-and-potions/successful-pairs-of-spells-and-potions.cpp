class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pairs;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for(int i=0;i<n;i++){
            long long required = (success + spells[i] - 1)/spells[i];
            int index = lower_bound(potions.begin(), potions.end(), required)-potions.begin();
            pairs.push_back(m-index);
        }
        return pairs;
    }
};