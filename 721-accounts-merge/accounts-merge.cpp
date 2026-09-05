class Solution {
public:

    vector<int> parent;

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b, vector<int>& size){

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(size[a] < size[b]){
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;

        int id = 0;

        // STEP 1: Give every unique email an ID
        for(int i = 0; i < accounts.size(); i++){

            for(int j = 1; j < accounts[i].size(); j++){

                if(emailToId.find(accounts[i][j]) == emailToId.end()){
                    emailToId[accounts[i][j]] = id++;
                }

                if(emailToName.find(accounts[i][j]) == emailToName.end()){
                    emailToName[accounts[i][j]] = accounts[i][0];
                }
            }
        }

        // STEP 2: Initialize DSU
        parent.resize(id);

        vector<int> size(id, 1);

        for(int i = 0; i < id; i++){
            parent[i] = i;
        }

        // STEP 3: Union emails belonging to the same account
        for(int i = 0; i < accounts.size(); i++){

            int firstEmail = emailToId[accounts[i][1]];

            for(int j = 2; j < accounts[i].size(); j++){

                int currentEmail = emailToId[accounts[i][j]];

                Union(firstEmail, currentEmail, size);
            }
        }

        // STEP 4: Group emails according to DSU root
        unordered_map<int, vector<string>> groups;

        for(auto &[email, id] : emailToId){

            int root = find(id);

            groups[root].push_back(email);
        }

        // STEP 5: Sort every group
        for(auto &[root, emails] : groups){
            sort(emails.begin(), emails.end());
        }

        // STEP 6: Build answer
        vector<vector<string>> ans;

        for(auto &[root, emails] : groups){

            vector<string> account;

            // Add name
            account.push_back(emailToName[emails[0]]);

            // Add sorted emails
            for(auto email : emails){
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};