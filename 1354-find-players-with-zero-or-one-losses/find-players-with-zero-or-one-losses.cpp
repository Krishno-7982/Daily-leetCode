class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;

        for (auto &match : matches) {
            int winner = match[0];
            int loser = match[1];

            // Ensure winner exists with 0 losses
            if (mp.find(winner) == mp.end()) {
                mp[winner] = 0;
            }

            // Count loser's losses
            mp[loser]++;
        }

        vector<int> zeroloss;
        vector<int> oneloss;

        for (auto &[player, losses] : mp) {
            if (losses == 0) {
                zeroloss.push_back(player);
            }
            else if (losses == 1) {
                oneloss.push_back(player);
            }
        }

        sort(zeroloss.begin(), zeroloss.end());
        sort(oneloss.begin(), oneloss.end());

        return {zeroloss, oneloss};
    }
};