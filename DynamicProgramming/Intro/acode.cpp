#include <iostream>
#include <string>

using namespace std;

int number_of_encodings(string enc) {
    if(enc.size() == 1) {
        return enc == "0" ? 0 : 1;
    }
    int prev_1 = 0;
    int prev_2 = 0;
    int curr = 0;
    curr = enc[0] == '0' ? 0 : 1;
    prev_1 = curr;
    prev_2 = curr;
    for(size_t  i = 1; i < enc.size(); i++) {
        curr = 0;
        int curr_zero = enc[i] == '0' ? 0 : 1;
        int last_two = stoi(enc.substr(i-1, 2));
        if(last_two <= 26 && last_two >= 10) {
            curr += prev_2;
        }
        curr += curr_zero*prev_1;
        prev_2 = prev_1;
        prev_1 = curr;
    }
    return curr;
}

int main() { 
    bool done = false;
    while(!done) {
        string line;
        getline(cin, line);
        if(line == "0") {
            done = true;
        } else {
            int encodings = number_of_encodings(line);
            cout << encodings << endl;
        }
    }
}