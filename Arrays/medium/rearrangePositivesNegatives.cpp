class Solution {
    //brute force
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> positives;
       vector<int> negatives;
       for(int i = 0;i<n;i++){
           if(nums[i]>0){
            positives.push_back(nums[i]);
           }else{
            negatives.push_back(nums[i]);
           }
       }
       
       for(int i = 0;i<positives.size();i++){
          nums[2*i] = positives[i];
       }
       for(int i  = 0;i<negatives.size();i++){
        nums[2*i+1] = negatives[i];
       }
       return nums;
    }

    //optimal
    vector<int> rearrangeArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans(n);
       //2 pointer approach 
       int positive = 0, negative = 1;
       for(int i = 0;i<n;i++){
        if(nums[i]<0){
            ans[negative] = nums[i];
            negative = negative+2;
        }else{
            ans[positive] = nums[i];
            positive = positive+2;
        }
       }
       return ans;
    }
};