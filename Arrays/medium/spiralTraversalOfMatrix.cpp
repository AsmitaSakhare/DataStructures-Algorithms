#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans; 

        //set pointers to navigate in spiral manner, top-left and bottom-right
        int top = 0, left = 0, right = m-1, bottom = n-1;
        
        while(top<=bottom && left<=right){
        //moving towards right
        for(int i = left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        //moving towards bottom
        for(int i = top; i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        //moving towards left
        if(top<=bottom){//this check is added for a single row matrix, so we don't traverse it again in reverse
          for(int i = right;i>=left;i--){
            ans.push_back(mat[bottom][i]);
        }
        bottom--;
        }
        

        //moving towards top
        if(left<=right){//this check is added for a single column matrix, so we don't traverse in again in reverse
          for(int i = bottom;i>=top;i--){
            ans.push_back(mat[i][left]);
        }
        left++;
        }
        
      }
    return ans;
    }

    int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = printSpiral(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}