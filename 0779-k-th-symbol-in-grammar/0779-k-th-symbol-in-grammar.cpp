class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k ==1){// if its first row's first element
            return 0;
        }
        int length = pow(2,n-1);
        int mid = length/2;

        if(k<=mid){// if k is till the mid then no. are similar to the previous row
            return kthGrammar(n-1,k);

        }
        else{// if k>mid then it is the not value of the previous row
            return 1 - kthGrammar(n-1,k-mid);
        }
    }
};