class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>st;
        int n = candyType.size();
        for(int i=0;i<n;i++){
            st.insert(candyType[i]);
        }
        return min(n/2, (int)st.size());
    }
};