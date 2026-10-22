class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto num : nums){
            pq.push(num);
        }
        int total_sum = 0;
        while(!pq.empty()){
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            total_sum += min(x, y);
        }
        return total_sum;
    }
};