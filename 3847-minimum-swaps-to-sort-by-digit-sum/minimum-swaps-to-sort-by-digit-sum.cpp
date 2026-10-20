class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            int digitSum = 0;
            int x = nums[i];
            while(x>0){
                int digit = x%10;
                digitSum += digit;
                x/=10;
            }
            v.push_back({digitSum, nums[i]});
        }
        sort(v.begin(), v.end());
        vector<int>nums2;
        for(auto x : v){
            nums2.push_back(x.second);
        }
        unordered_map<int, int>targetIndex;
        for(int i=0;i<n;i++){
            targetIndex[nums[i]] = i;
        }
        vector<int>visited(n, 0);
        int min_swaps = 0;
        for(int i=0;i<n;i++){
            if(visited[i] || targetIndex[nums2[i]] == i){
                continue;

            }
            int j = i;
            int cycle_size = 0;
            while(!visited[j]){
                visited[j] = 1;
                j = targetIndex[nums2[j]];
                cycle_size++;
            }
            min_swaps += cycle_size - 1;
        }
        return min_swaps;
    }
};