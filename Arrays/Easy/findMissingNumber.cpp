#include <bits/stdc++.h>
using namespace std;


//brute force: check if every element in the range [0,n] is present in the array
int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    //T.C. = O(N^2)
    //S.C. = O(1);
    return -1;
}

//better solution: hashing
int missingNumber(vector<int>&a, int N) {

    int hash[N + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
    //T.C. = O(2(N+1))
    //S.C. = O(N+1)
}

//optimal: use XOR or the sum formula
int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int sum = n*(n+1)/2;
       int arrSum = 0;
       for(int i = 0;i<n;i++){
           arrSum = arrSum + nums[i];
       }
       int ans = sum - arrSum;
       return ans;
    }

     int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for(int i = 0;i<n;i++){
           xor1 = xor1^nums[i];
           xor2 = xor2^i;//can do i+1 here
        }
        xor2= xor2^n;
        return xor1^xor2;
    }

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}