class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rowString(numRows);

        int row = 0;
        int direction = 1;

        for (char c : s) {
            rowString[row].push_back(c);

            if (row == 0)
                direction = 1;
            else if (row == numRows - 1)
                direction = -1;

            row += direction;
        }

        string ans;
        for (string &str : rowString)
            ans += str;

        return ans;
    }
};