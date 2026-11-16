
class Solution {
public:
    struct Node {
        Node* children[26];
        vector<string> pro;

        Node() {
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* curr = root;

        for(auto ch : word) {
            int idx = ch - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new Node();
            }

            curr = curr->children[idx];

            if(curr->pro.size() < 3) {
                curr->pro.push_back(word);
            }
        }
    }

    vector<vector<string>> suggestedProducts(
        vector<string>& products, string searchWord
    ) {
        sort(products.begin(), products.end());

        for(auto word : products) {
            insert(word);
        }

        vector<vector<string>> ans;
        Node* curr = root;

        for(auto ch : searchWord) {
            int idx = ch - 'a';

            if(curr != NULL) {
                curr = curr->children[idx];
            }

            if(curr == NULL) {
                ans.push_back({});
            }
            else {
                ans.push_back(curr->pro);
            }
        }

        return ans;
    }
};
