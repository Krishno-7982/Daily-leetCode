class Solution {
public:
    static const int M = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix sum of digits
        vector<long long> pfSum(n + 1, 0);

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            pfSum[i + 1] = pfSum[i] + (s[i] - '0');

            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // pref[i] = number formed by first i digits
        vector<long long> pref(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pref[i + 1] = (pref[i] * 10 + digit[i]) % M;
        }

        // powers of 10
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        vector<int> ans;

        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];

            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            // No non-zero digit
            if (left > right) {
                ans.push_back(0);
                continue;
            }

            long long sum = pfSum[r + 1] - pfSum[l];

            int len = right - left + 1;

            long long x = (pref[right + 1] -
                           pref[left] * pow10[len] % M +
                           M) % M;

            ans.push_back((x * (sum % M)) % M);
        }

        return ans;
    }
};
