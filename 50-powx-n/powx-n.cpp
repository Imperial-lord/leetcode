class Solution {
public:
    double myPow(double x, int num) {
        int isNeg = false;
        long n = num;
        if(n<0){
            isNeg = true;
            n=-n;
        }
        double ans = 1;
        
        while(n>0){
            if(n&1) ans*=x;
            n>>=1;
            x=x*x;
        }

        if(isNeg) ans = 1/ans;
        return ans;
    }
};