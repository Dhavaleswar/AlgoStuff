#include <iostream>
#include <climits>

using namespace std;

int do_dp(int n, int *memo) {
    if(memo[n] != -1) {
        return memo[n];
    }
    if(n == 1) {
        memo[n] = 0;
        return memo[n];
    }
    int steps1 = 1 + do_dp(n-1, memo);
    int steps2 = n%2 == 0 ? 1 + do_dp(n/2, memo) : INT_MAX;
    int steps3 = n%3 == 0 ? 1 + do_dp(n/3, memo) : INT_MAX;
    memo[n] = min(steps1, min(steps2, steps3));
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    int memo[n+1];
    for(size_t i = 0; i < n+1; i++) {
        memo[i] = -1;
    }
    int min_steps = do_dp(n, memo);
    cout << min_steps << endl;
    return 0;
}