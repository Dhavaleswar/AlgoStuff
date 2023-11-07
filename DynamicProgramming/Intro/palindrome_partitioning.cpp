#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string s;
    map<int, vector<vector<string>>> memo;
    vector<vector<int>> palindromes;
    

    bool isPalindrome(int start, int end) {
        if(palindromes[start][end] != -1) {
            return palindromes[start][end];
        }
        while(start < end) {
            if(this->s[start] != this->s[end]) {
                palindromes[start][end] = false;
                return false;
            }
            start++;
            end--;
        }
        palindromes[start][end] = true;
        return true;
    }

    
    vector<vector<string>> dp(int i) {
        if(this->memo[i].size() > 0) {
            return this->memo[i];
        }
        if(i == this->s.size()) {
            return vector<vector<string>>{{}};
        }
        vector<vector<string>> ans;
        for(int j = i; j < this->s.size(); j++) {
            if(this->isPalindrome(i, j)) {
                vector<vector<string>> sub_ans = this->dp(j+1);
                for(auto &v : sub_ans) {
                    v.insert(v.begin(), this->s.substr(i, j-i+1));
                }

                for(auto v : sub_ans) {
                    ans.push_back(v);
                }
            }
        }
        this->memo[i] = ans;
        return ans;
    }

    vector<vector<string>> partition(string s) {
        this->s = s;
        for(size_t i = 0; i < s.size(); i++) {
            vector<int> row;
            for(size_t j = 0; j < s.size(); j++) {
                row.push_back(-1);
            }
            this->palindromes.push_back(row);
        }

        for(size_t i = 0; i < s.size(); i++) {
            this->memo[i] = vector<vector<string>>();
        }

        return this->dp(0);
    }
};

int main() {
    string s;
    cin >> s;
    vector<vector<string>> ans = Solution().partition(s);
    for(auto v : ans) {
        for(auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}
