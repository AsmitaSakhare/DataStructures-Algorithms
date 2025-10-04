#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& arr, int k) {
      unordered_map<int,int> mpp;
      int preSum = 0;
      mpp[0]=1;
      int count = 0;
      for(int i = 0;i<arr.size();i++){
        preSum+=arr[i];
        int remove = preSum-k;
        count+=mpp[remove];
        mpp[preSum]++;
      }
      return count;
    }

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}