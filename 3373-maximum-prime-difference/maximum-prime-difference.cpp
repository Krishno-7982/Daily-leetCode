class Solution {
public:
    bool isPrime[105];

    void prime() {
        fill(isPrime, isPrime + 105, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < 105; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 105; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int maximumPrimeDifference(vector<int>& nums) {
        prime();

        int first = -1, last = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (isPrime[nums[i]]) {
                if (first == -1) first = i;
                last = i;
            }
        }

        return last - first;
    }
};