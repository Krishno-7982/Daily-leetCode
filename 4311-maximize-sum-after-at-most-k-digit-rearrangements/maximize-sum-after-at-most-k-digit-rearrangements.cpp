
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {

        priority_queue<int> pq;
        long long ans = 0;

        for(int x : nums) {

            ans += x;

            string s = to_string(x);

            sort(s.begin(), s.end(), greater<char>());

            int newN = stoi(s);

            int gain = newN - x;

            if(gain > 0) {
                pq.push(gain);
            }
        }

        while(k > 0 && !pq.empty()) {

            ans += pq.top();
            pq.pop();

            k--;
        }

        return ans;
    }
};
