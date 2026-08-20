class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int n_non_overlap = 1;
        int last_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= last_end) {
                n_non_overlap++;
                last_end = intervals[i][1]; 
            }
        }

        return intervals.size() - n_non_overlap;
    }
};