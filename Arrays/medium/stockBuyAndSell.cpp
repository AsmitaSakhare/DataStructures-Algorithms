


#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        int n = prices.size();
        //you keep updating mini to get the max difference in one pass solution
        for(int i = 1;i<n;i++){
           int cost = prices[i]-mini;//wihout cost , profit will get updated in each iteration but if we don't do max we won't get maximum difference
           profit = max(cost,profit);
           mini = min(mini,prices[i]);
        }
        return profit;
    }

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(prices);
    cout << "Max profit is: " << maxPro << endl;
}
