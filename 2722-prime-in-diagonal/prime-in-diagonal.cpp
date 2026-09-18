class Solution {
public:
    bool isPrime(int num) {
        if(num < 2) return false;

        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0)
                return false;
        }

        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        int k = nums.size() - 1;

        for(int i = 0; i < nums.size(); i++) {
            int num1 = nums[i][i];
            int num2 = nums[i][k-i];

            if(isPrime(num1)) {
                ans = max(ans, num1);
            }

            if(isPrime(num2)) {
                ans = max(ans, num2);
            }
        }

        return ans;
    }
};