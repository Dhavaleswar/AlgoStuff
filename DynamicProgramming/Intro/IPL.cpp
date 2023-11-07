// Zonal Computing Olympiad 2014, 30 Nov 2013
// https://www.codechef.com/practice/INTDP01/problems/ZCO14004

#include <iostream>

using namespace std;

int assign_maxamount_games(int *games_money, int n_games) {
    int cumulative_max[n_games][3];
    for(size_t i = 0; i < n_games; i++) {
        if(i == 0) {
            cumulative_max[i][0] = 0;
            cumulative_max[i][1] = games_money[0];
            cumulative_max[i][2] = games_money[0];
        }
        else {
            int c = i < 2 ? 0 : cumulative_max[i-2][0];
            int b = i < 2 ? 0 : max(cumulative_max[i-1][0], cumulative_max[i-1][1]);
            cumulative_max[i][0] = max(cumulative_max[i-1][0], max(cumulative_max[i-1][1], cumulative_max[i-1][2]));
            cumulative_max[i][1] = games_money[i] + cumulative_max[i-1][0];
            cumulative_max[i][2] = games_money[i] + + games_money[i-1] + c;
        }
    }

    return max(cumulative_max[n_games-1][0], max(cumulative_max[n_games-1][1], cumulative_max[n_games-1][2]));
}

int main() {
    int n_games;
    cin >> n_games;
    int games_money[n_games];
    for(size_t i = 0; i < n_games; i++) {
        cin >> games_money[i];
    }

    int max_amount = assign_maxamount_games(games_money, n_games);
    cout << max_amount << endl;
    return 0;
}