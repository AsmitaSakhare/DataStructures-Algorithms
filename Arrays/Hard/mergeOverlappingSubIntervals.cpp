#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> ans;
       int n = intervals.size();

    //    if(n==1) return intervals;

       sort(intervals.begin(),intervals.end());
       
       int i = 0;
       while(i<n){
        int start = intervals[i][0];
        int end = intervals[i][1];
        int j = i+1;
        while(j<n && intervals[j][0]<=end){
            end = max(end,intervals[j][1]);
            j++;
        }
        ans.push_back({start,end});
        i=j;
       }
       return ans;
    }
    //T.C. = O(nlogn)+O(2n) sorting and every element gets iterated over twice
};

//optimal
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> ans;
       int n = intervals.size();

    //    if(n==1) return intervals;

       sort(intervals.begin(),intervals.end());
       
      for(int i = 0;i<n;i++){
        if(ans.empty() || intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
        }else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
      }
       return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = sol.merge(intervals);

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}