#include <iostream>

using namespace std;

// define function to return boolean list
int assign_mintime_activities(int *activity_mins, size_t n_activities) {
    int *cumulative_mins = new int[n_activities];
    for(size_t i = 0; i < n_activities; i++) {
        if(i < 3) {
            cumulative_mins[i] = activity_mins[i];
        }
        else {
            cumulative_mins[i] = activity_mins[i] + min(cumulative_mins[i-1], min(cumulative_mins[i-2], cumulative_mins[i-3]));
        }
    }
    return min(cumulative_mins[n_activities-1], min(cumulative_mins[n_activities-2], cumulative_mins[n_activities-3]));
}

int main() {
    int n;
    cin >> n;
    int activity_mins[n];
    for(size_t i = 0; i < n; i++) {
        cin >> activity_mins[i]; 
    }
    int min_time = assign_mintime_activities(activity_mins, n);
    cout << min_time << endl;
    return 0;
}