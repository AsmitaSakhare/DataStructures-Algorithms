//better
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
       if (a.empty()) return 0; 
       sort(a.begin(),a.end());
       int n = a.size();
        vector<int> b;
        b.push_back(a[0]); // Always keep the first element so that b isn't empty
        
        for (int i = 1; i < a.size(); i++) {
            if (a[i] != a[i - 1]) {
                b.push_back(a[i]);
            }
        }
       int count = 1, max_Count = 1;
       for (int i = 1; i < b.size(); i++) { // Start from index 1 so that this will not get executed if b only has 1 element
            if (b[i] == b[i - 1] + 1) {
                count++;
                max_Count = max(max_Count, count);
            } else {
                count = 1;
            }
        }
       return max_Count;
    }
};

//optimal
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}