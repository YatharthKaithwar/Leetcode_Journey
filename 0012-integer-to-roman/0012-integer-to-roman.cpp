class Solution {
public:
    vector<int> val {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbol{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string ans = "";
        for(int i = 0; i<13; i++){
            if(num==0)break;
            int times = num/val[i];// finding how many times we have to add the symbol by dividing it by val[i]
            while(times--){// decreasing the times count every time we add the symbol
                ans += symbol[i];
            }
            num = num%val[i];// obtaining the remaider for further values
        }
        return ans;
    }
};