class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if (n >= 1000) {
            ans += n - 999;          // 1000 to n
        }

        if (n >= 1000000) {
            ans += n - 999999;       // 1,000,000 to n
        }

        if (n >= 1000000000) {
            ans += n - 999999999;    // 1,000,000,000 to n
        }

        if (n >= 1000000000000LL) {
            ans += n - 999999999999LL;
        }
        if (n >= 1000000000000000LL) {
            ans += n - 999999999999999LL;
        }
        return ans;
    }
};