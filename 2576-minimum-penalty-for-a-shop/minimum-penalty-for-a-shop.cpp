class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;

        for(auto c : customers){
            if(c=='Y'){
                totalY++;
            }
        }
        int rightY = totalY;
        int leftN = 0;

        int panelty = rightY;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                rightY--;
            }else{
                leftN++;
            }
            int currentPanelty = leftN + rightY;
            if(currentPanelty < panelty){
                panelty = currentPanelty;
                ans = i+1;
            }
        }
        return ans;
    }
};