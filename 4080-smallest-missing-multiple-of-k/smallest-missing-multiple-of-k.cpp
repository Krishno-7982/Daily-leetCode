class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int max_ele = *(max_element(nums.begin(), nums.end()));
        int i=1;
        while(true){
            if(st.find(i*k)==st.end()){
                return i*k;
            }
            i++;
        }
        return k*n;
        
    }
};