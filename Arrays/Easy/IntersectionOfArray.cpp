#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0, n = nums1.size(), m = nums2.size();
    while(i < n && j < m){
        // Skip duplicates in nums1
        if(i > 0 && nums1[i] == nums1[i-1]) { i++; continue; }
        // Skip duplicates in nums2
        if(j > 0 && nums2[j] == nums2[j-1]) { j++; continue; }
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            i++; j++;
        } else if(nums1[i] < nums2[j]){
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

};