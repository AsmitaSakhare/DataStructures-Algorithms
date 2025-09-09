#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int n1 = a.size();
        int n2 = b.size();
        vector <int> unionArr;
        int i = 0;
        int j = 0;
        
         while (i < n1 && j < n2) {
            // Add smaller element or unique values from both arrays
            if (a[i] < b[j]) {
                if (unionArr.empty() || unionArr.back() != a[i]) {
                    unionArr.push_back(a[i]);
                }
                i++;
            } else if (a[i] > b[j]) {
                if (unionArr.empty() || unionArr.back() != b[j]) {
                    unionArr.push_back(b[j]);
                }
                j++;
            } else {
                // Both elements are equal; add one and move both pointers
                if (unionArr.empty() || unionArr.back() != a[i]) {
                    unionArr.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        // Add remaining elements in `a`
        while (i < n1) {
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        }

        // Add remaining elements in `b`
        while (j < n2) {
            if (unionArr.empty() || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
        
        
        
        // return vector with correct order of elements
        return unionArr;
    }
};


