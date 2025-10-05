#include <bits/stdc++.h>
using namespace std;


//when given c and r
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

//generate one row
void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

//generate entire triangle
class Solution {
public:
    vector<int> generateRow(int n){
        vector<int> row;
        row.push_back(1);
        long long num = 1;
        for(int i = 1;i<n;i++){
           num = num*(n-i);
           num = num/i;
           row.push_back(num);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> ans;
         for(int i = 1;i<=numRows;i++){
            ans.push_back(generateRow(i));
         }
         return ans;
    }
};