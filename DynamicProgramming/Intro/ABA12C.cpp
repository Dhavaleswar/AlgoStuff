#include <iostream>
#include <climits>

using namespace std;




int min_cost(int *prices, int N, int K) {
}

int main() {
    int n_tests;
    cin >> n_tests;
    for(int t = 0; t < n_tests; t++) {
        cin >> n_tests;
        int N, K;
        cin >> N >> K;
        int prices[N];
        for(int i = 0; i < N; i++) {
            cin >> prices[i];
        }
        int min_price = min_cost(prices, N, K);
        cout << min_price << endl;
    }
    
}