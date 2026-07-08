class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1 = 0,ct2 = 0;
        int candidate1 = 0,candidate2 = 0;
        for(auto val : nums){
            if(val == candidate1){
                ct1++;
            }else if(val == candidate2){
                ct2++;
            }else if(ct1==0){
                candidate1 = val;
                ct1 = 1;;
            }else if(ct2==0){
                candidate2 = val;
                ct2 = 1;
            }else{
                ct1--;
                ct2--;
            }
        }
        ct1 = 0;
        ct2 = 0;
        for(auto val : nums){
            if (val == candidate1){
                ct1++;
            }else if(val == candidate2){
                ct2++;
            }
        }
        vector<int>ans;
        if(ct1>nums.size()/3){
            ans.push_back(candidate1);
        }
        if(ct2 > nums.size()/3){
            ans.push_back(candidate2);
        }
        return ans;
    
    }
};
