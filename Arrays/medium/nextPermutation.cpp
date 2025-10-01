class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        //finding the break point, first no which is smaller than the next
       for(int i = n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index = i;
            break;
        }
       }
       //if it is the last permutation
       if(index==-1){
        reverse(nums.begin(),nums.end());
        return nums;
       }
       //find the first greater no than index from right and swap
       for(int i = n-1;i>=index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
       }
       //sort the remaining to make the smallest possible no
       sort(nums.begin()+index+1, nums.end());
       return nums;
    }
};

int main()
{
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}