#include<bits/stdc++.h>
using namespace std;
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n = arr.size();
        int maxi = arr[n-1];
        ans.push_back(maxi);
        for(int i = n-2;i>=0;i--){
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

