class Solution {
public:
    double power(double x,long long n){
        if(n==0)return 1;
        double half = power(x,n/2);// half the power
        if(n%2==0){// if n is even
            return half*half;
        }
        else{// if n is odd
            return x*half*half;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){// if n is negative
            x=1/x;// reciprocal the no.
            N=-N;// make N positive
        }
        return power(x,N);
    }
};