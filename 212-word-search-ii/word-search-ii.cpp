
class Solution {
public:
    int n, m;

    struct Node {
        Node* children[26];
        bool isEnd;
        string word;

        Node() {
            isEnd = false;
            word = "";

            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    vector<pair<int, int>> movements = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    Node* root = new Node();

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == NULL) {
                curr->children[idx] = new Node();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
        curr->word = word;
    }

    vector<string> ans;

    void dfs(int x, int y, Node* curr,
             vector<vector<char>>& board,
             vector<vector<int>>& visited) {

        if (!isValid(x, y)) return;
        if (visited[x][y]) return;

        int idx = board[x][y] - 'a';

        if (curr->children[idx] == NULL) {
            return;
        }

        curr = curr->children[idx];

        if (curr->isEnd) {
            ans.push_back(curr->word);
            curr->isEnd = false;  // Prevent duplicate answers
        }

        visited[x][y] = 1;

        for (auto movement : movements) {
            int nx = x + movement.first;
            int ny = y + movement.second;

            dfs(nx, ny, curr, board, visited);
        }

        visited[x][y] = 0;//backtrack
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        n = board.size();
        m = board[0].size();

        ans.clear();

        // Build the Trie
        root = new Node();

        for (string word : words) {
            insert(word);
        }

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Start DFS from every board cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, root, board, visited);
            }
        }

        return ans;
    }
};
