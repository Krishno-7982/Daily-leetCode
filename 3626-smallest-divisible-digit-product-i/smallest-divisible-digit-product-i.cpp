class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n<=t) return t;
        if(n%10==0 || t==1) return n;
        if(n<10){
            while(n<10){
                if(n%t==0) return n;
                n++;
            }
        }
        while(true){
            int d1 = n/10;
            int d2 = n%10;
            int pro = d1*d2;
            if(pro%t==0){
                return n;
            }
            n++;
        }
        return -1;
    }
};