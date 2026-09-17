class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string s;

        int i = a.size() - 1;
        int j = b.size() - 1;

        while(i >= 0 || j >= 0 || c) {
            int x = 0;
            int y = 0;

            if(i >= 0)
                x = a[i] - '0';

            if(j >= 0)
                y = b[j] - '0';

            int sum = x + y + c;

            s += (sum % 2) + '0';
            c = sum / 2;

            i--;
            j--;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};