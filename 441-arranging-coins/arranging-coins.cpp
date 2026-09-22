class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int ct = 0;

        while(n >= i) {
            n -= i;
            ct++;
            i++;
        }

        return ct;
    }
};