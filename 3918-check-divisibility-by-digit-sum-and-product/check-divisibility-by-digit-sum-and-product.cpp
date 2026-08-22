class Solution {
public:
    bool checkDivisibility(int n) {
        long long pro = 1;
        long long sum = 0;
        int c = n;

        while (c > 0) {
            int digit = c % 10;
            sum += digit;
            pro *= digit;
            c /= 10;
        }

        return n % (sum + pro) == 0;
    }
};