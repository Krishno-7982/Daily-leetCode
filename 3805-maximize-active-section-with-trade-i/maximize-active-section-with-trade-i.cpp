class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Count original active sections (number of 1's)
        int totalOnes = 0;
        for (char c : s)
            if (c == '1') totalOnes++;

       
        s = "1" + s + "1";

  
        vector<pair<char, int>> groups;
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                groups.push_back({s[i - 1], cnt});
                cnt = 1;
            }
        }
        groups.push_back({s.back(), cnt});

        int ans = totalOnes;

        
        for (int i = 1; i + 1 < groups.size(); i++) {
            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                int removedOnes = groups[i].second;
                int mergedZeros = groups[i - 1].second + removedOnes + groups[i + 1].second;

                int current = totalOnes - removedOnes + mergedZeros;
                ans = max(ans, current);
            }
        }

       
        return ans;
    }
};