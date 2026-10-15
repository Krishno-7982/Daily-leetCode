
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxCt = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int duplicate = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // Normalize vertical lines.
                if (dx == 0) {
                    dy = 1;
                } 
                // Normalize the sign for other slopes.
                else if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                string slope = to_string(dx) + "/" + to_string(dy);
                mp[slope]++;
                currMax = max(currMax, mp[slope]);
            }

            maxCt = max(maxCt, currMax + duplicate + 1);
        }

        return maxCt;
    }
};
