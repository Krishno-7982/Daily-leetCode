class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = n - 1;

     
        while(i < j && nums[i] <= nums[i + 1]) {
            i++;
        }

        while(j > i && nums[j] >= nums[j - 1]) {
            j--;
        }

       
        if(i == j) return 0;

        // Find minimum and maximum in the unsorted range
        int min_ele = *min_element(nums.begin() + i, nums.begin() + j + 1);
        int max_ele = *max_element(nums.begin() + i, nums.begin() + j + 1);

        // Expand left boundary
        while(i > 0 && nums[i - 1] > min_ele) {
            i--;
        }

        // Expand right boundary
        while(j < n - 1 && nums[j + 1] < max_ele) {
            j++;
        }

        return j - i + 1;
    }
};