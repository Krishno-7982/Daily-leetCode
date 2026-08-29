class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int, int>> p;

        
        for(int i = 0; i < nums1.size(); i++) {
            p.push_back({nums1[i], nums2[i]});
        }

        // Sort according to nums2 in descending order
        sort(p.begin(), p.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        });

        long long sum = 0;
        long long maxSum = 0;

        // Min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto x : p) {
            pq.push(x.first);
            sum += x.first;

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            
            if(pq.size() == k) {
                maxSum = max(maxSum, sum * x.second);
            }
        }

        return maxSum;
    }
};