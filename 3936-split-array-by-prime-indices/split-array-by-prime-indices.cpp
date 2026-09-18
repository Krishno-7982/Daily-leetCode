class Solution {
public:
    bool isPrime[100005];

    void prime() {
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i < 100005; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j < 100005; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    long long splitArray(vector<int>& nums) {
        memset(isPrime, true, sizeof(isPrime));

        prime();

        long long sum1 = 0;
        long long sum2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(isPrime[i]) {
                sum1 += nums[i];
            } else {
                sum2 += nums[i];
            }
        }

        return abs(sum1 - sum2);
    }
};