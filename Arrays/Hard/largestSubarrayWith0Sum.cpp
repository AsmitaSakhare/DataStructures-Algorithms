#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE: generate all subarrays
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int maxCount = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int sum = 0;
            int count = 0;
            for(int j = i;j<n;j++){
                sum+=arr[j];
                count++;
                if(sum==0){
                    maxCount = max(count,maxCount);
                }
            }
        }
        return maxCount;
    }
};

//OPTIMAL: hashing
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        int maxi = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(sum==0) maxi = i+1;
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi = max(maxi,i-mpp[sum]);
                }else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};
