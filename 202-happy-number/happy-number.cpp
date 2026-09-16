class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;

        while (n != 1) {
            if (st.find(n) != st.end()) {
                return false;   // cycle detected
            }

            st.insert(n);
            n = digitSquareSum(n);
        }

        return true;
    }
};