#include <bits/stdc++.h>
using namespace std;

//brute force
class Solution {
public:

    void markRow(vector<vector<int>>& matrix,int row, int n, int m){
         for(int k = 0;k<m;k++){
            if(matrix[row][k]!=0){
                matrix[row][k]=-1;

            }
                }
    }

    void markCol(vector<vector<int>>& matrix,int col, int n, int m){
        for(int l = 0;l<n;l++){
            if(matrix[l][col]!=0){
                matrix[l][col]=-1;

            }
                }
    }
    void setZeroes(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j]==0){
                markRow(matrix,i,n,m);//marking them as -1 first, so no mistake in marking as zero
                markCol(matrix,j,n,m);
            }
        }
      }
      for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
      }
    }
};

//T.C. = O(n*m)*O(n+m)+ O(n*m)
//S.C. = O(1)

//better approach
void setZeroes(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<int> row(n,0);
      vector<int> col(m,0);

      for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
      }
      for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
      }
    }
//T.C. = O(n*m)+O(n*m)
//S.C. = O(n)+O(m)