#include <iostream>
#include <vector>

using namespace std;


int maximal_price(int *prices, vector<int>memo, int n) {
    if(memo[n] == -1) {
        int max_price = -1;
        for(int i = 1; i <= n; i++) {
            int curr_price = prices[i-1] + maximal_price(prices, memo, n-i);
            max_price = max(max_price, curr_price);
        }
        memo[n] = max_price;
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    int prices[n];
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    vector<int> memo;
    memo.clear();
    memo.assign(n+1, -1);
    memo[0] = 0;
    int max_price = maximal_price(prices, memo, n);
    cout << max_price << endl;
}