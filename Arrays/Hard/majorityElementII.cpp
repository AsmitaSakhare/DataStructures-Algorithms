#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]+=1;;
        }
        
        vector<int> ans;
        for(auto it : mpp){
            if(it.second>n/3) ans.push_back(it.first);
        }
        return ans;
    }

};    // T.C. = O(NlogN) + O(N)
    // S.C. = O(N)


    

//optimizing T.C.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        int mini = int(n/3)+1;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]+=1;;
            if(mpp[nums[i]]==mini){
              ans.push_back(nums[i]);
            }
            if(ans.size()==2) break;
        }
        
        return ans;
    }
    // T.C. = O(NlogN) 
    // S.C. = O(N)

//optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
    int n = nums.size(); 

    int cnt1 = 0, cnt2 = 0; 
    int el1 = INT_MIN; 
    int el2 = INT_MIN; 
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1) cnt1++;
        else if (nums[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
    vector<int> ls; 
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }
    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);
    return ls;
}

};
};