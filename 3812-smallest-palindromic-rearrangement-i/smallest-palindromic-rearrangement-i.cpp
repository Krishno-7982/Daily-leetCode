class Solution {
public:
    string smallestPalindrome(string s) {
        string a, b;
        vector<int> hsh(26, 0);

        for (char c : s)
            hsh[c - 'a']++;

        // Build left and right halves
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < hsh[i] / 2; j++) {
                a += (char)(i + 'a');
                b += (char)(i + 'a');
            }
        }

        // Middle character (if any)
        for (int i = 0; i < 26; i++) {
            if (hsh[i] % 2 == 1) {
                a += (char)(i + 'a');
                break;
            }
        }

        reverse(b.begin(), b.end());
        a += b;

        return a;
    }
};