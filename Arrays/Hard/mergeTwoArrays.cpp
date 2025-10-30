class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0;i<n;i++){
            nums1[i+m] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    Solution().merge(nums1, m, nums2, n);

    // Print merged array
    for (int num : nums1) cout << num << " ";
    return 0;
}