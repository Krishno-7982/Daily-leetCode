
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();

        int total_sum = accumulate(arr.begin(), arr.end(), 0);

        if(total_sum % 3 != 0) return false;

        int target = total_sum / 3;
        int curr_sum = 0;
        int ct = 0;

        for(int j = 0; j < n; j++) {
            curr_sum += arr[j];

            if(curr_sum == target) {
                curr_sum = 0;
                ct++;

                // Leave at least one element for the third part.
                if(ct == 2 && j < n - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
