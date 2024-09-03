#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool check_subset_sum(int *arr, int N, int sum, int currInd, int currSum, map<int, bool> *dp, int* count) {
    // check if key exists in dp
    if(dp[currInd].find(currSum) != dp[currInd].end()) {
        return dp[currInd][currSum];
    }
    int ans = 0;
    if(currInd == N) {
        if(currSum == sum) {
            count[0]++;
            return true;
        }
        return false;
    }
    bool ans1 = false, ans2 = false;
    if(sum >= arr[currInd]) {
        ans1 =  check_subset_sum(arr, N, sum, currInd+1, currSum+arr[currInd], dp, count);
    }
    ans2 = check_subset_sum(arr, N, sum, currInd+1, currSum, dp, count);
    // update dp
    dp[currInd][currSum] =  ans || ans1 || ans2;
    return ans;
}

int subset_sum(int *arr, int N, int sum) {
    // create array of dictionary
    map<int, bool> dp[N];
    int count[1] = {0};
    bool ans = check_subset_sum(arr, N, sum, 0, 0, dp, count);
    return count[0];
    
}

int main() {
    string file_ = __FILE__;
    string path = file_.substr(0, file_.find_last_of("\\/"));
    string new_file = path + "/subset_sum_input.txt";
    freopen(new_file.c_str(), "r", stdin);
    int sum, N;
    cin >> sum >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << "Sum: " << sum << endl;
    cout << "N: " << N << endl;
    cout << "Array: ";
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Subset sum: ";
    int sum_exists = subset_sum(arr, N, sum);
    cout << "Exists " <<  sum_exists <<endl;

    return 0;
}

