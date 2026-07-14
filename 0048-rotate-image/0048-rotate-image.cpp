class Solution{
     
private:
    void reverse(vector<int>& row ){
       int p1=0; 
       int p2=row.size()-1;
       while(p1<p2){
        swap(row[p1],row[p2]);
        p1++;p2--;
       }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
 //       int n = matrix.size();
 //       vector<vector<int>> ans(n, vector<int>(n));
 //       for (int i =0; i<n;i++){
 //           for(int j = 0 ; j< n; j++){
 //               ans[j][(n-1)-i]= matrix[i][j];
 //           }
 //       }
 //       matrix = ans;
 
          int n = matrix.size();

          for(int i =0 ; i<n-1;i++){
            for (int j =i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
          }
          for (int i = 0 ; i<n ; i++){
            reverse(matrix[i]);
          }


    }
};