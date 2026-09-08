class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        // Count frequency
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        // Store {frequency, word}
        vector<pair<int, string>> v;

        for (auto &[x, cnt] : mp) {
            v.push_back({cnt, x});
        }

        // Sort
        sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            } 
            return a.first > b.first;
        });

        // Take top k
        vector<string> ans;

        for (auto &e : v) {
            if (ans.size() < k) {
                ans.push_back(e.second);
            } else {
                break;
            }
        }

        return ans;
    }
};