class Solution {
public:

    pair<int,int> getnumber(string s) {

        int pos = s.find('+', 1);

        int a = stoi(s.substr(0, pos));

        int b = stoi(s.substr(pos + 1, s.size() - pos - 2));

        return {a, b};
    }

    string complexNumberMultiply(string num1, string num2) {

        pair<int,int> p1 = getnumber(num1);
        pair<int,int> p2 = getnumber(num2);

        int r = p1.first * p2.first -
                p1.second * p2.second;

        int im = p1.first * p2.second +
                 p1.second * p2.first;

        return to_string(r) + "+" + to_string(im) + "i";
    }
};