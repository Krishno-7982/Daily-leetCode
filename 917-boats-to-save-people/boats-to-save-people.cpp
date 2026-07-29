class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat = 0;
        sort(people.begin(), people.end());
        int st = 0, end = people.size()-1;
        while(st<=end){
            if(people[st] + people[end] <= limit){
                st++;
                end--;
            }else{
                end--;
            }
            boat++;
        }
        return boat;
    }
};