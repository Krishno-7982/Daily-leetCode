
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        unordered_set<string> st;
        for (auto word : wordDict) {
            st.insert(word);
        }

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;

            for (int j = i; j < n; j++) {
                string k = s.substr(i, j - i + 1);

                if (st.find(k) != st.end()) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[n];
    }
};
