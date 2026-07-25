class Solution {
public:
    int maxProduct(int n) {
        int largest = -1, second_largest = -1;
        while(n>0){
            int digit = n%10;
            if(digit>=largest){
                second_largest = largest;
                largest = digit;
            }else if(digit>second_largest){
                second_largest = digit;
            }
            n/=10;
        }
        return largest*second_largest;
    }
};