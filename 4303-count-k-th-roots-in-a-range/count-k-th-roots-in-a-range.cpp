class Solution {
public:

    long long multiply(long long mid, int k, long long x) {
        long long ans = 1;

        for (int i = 1; i <= k; i++) {
            ans *= mid;

            if (ans > x)
                return ans;
        }

        return ans;
    }

    long long getKthRoot(long long x, int k) {
        long long lo = 1, hi = x;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (multiply(mid, k, x) <= x) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return hi;
    }

    int countKthRoots(int l, int r, int k) {

        if (l == 0)
            return getKthRoot(r, k) + 1;

        long long right = getKthRoot(r, k);

        long long left = getKthRoot(l, k);

        // Convert floor root into ceil root
        if (multiply(left, k, l) != l)
            left++;

        if (left > right)
            return 0;

        return right - left + 1;
    }
};