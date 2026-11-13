
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.size();
        if(n < 10) return {};

        long long BASE = 31;
        long long MOD = 1e9 + 7;

        unordered_map<long long, vector<string>> mp;
        unordered_set<string> added;

        int k = 10;
        long long power = 1;

        for(int i = 1; i < k; i++) {
            power = (power * BASE) % MOD;
        }

        long long hash = 0;

        for(int i = 0; i < k; i++) {
            hash = (hash * BASE + (s[i] - 'A' + 1)) % MOD;
        }

        mp[hash].push_back(s.substr(0, 10));

        for(int i = k; i < n; i++) {

            hash = (hash - (s[i-k] - 'A' + 1) * power % MOD + MOD) % MOD;

            hash = (hash * BASE + (s[i] - 'A' + 1)) % MOD;

            string temp = s.substr(i-k+1, 10);

            auto it = mp.find(hash);

            if(it != mp.end()) {
                if(find(it->second.begin(), it->second.end(), temp) != it->second.end()) {
                    added.insert(temp);
                }
            }

            mp[hash].push_back(temp);
        }

        vector<string> ans;

        for(auto temp : added) {
            ans.push_back(temp);
        }

        return ans;
    }
};
