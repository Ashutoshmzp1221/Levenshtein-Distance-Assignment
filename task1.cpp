#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task1 {
    public:
    int EditDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector< vector<int> > dp(n + 1, vector<int> (m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min(dp[i][j - 1], 
                                        min(dp[i - 1][j], 
                                        dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Task1 calc;
    cout << "Input: \"kitten\", \"sitting\"\n" << "Output: " << calc.EditDistance("kitten", "sitting") <<"\n"<< endl;
    cout << "Input: \"flaw\", \"lawn\"\n" << "Output: " << calc.EditDistance("flaw", "lawn") <<"\n" << endl;
    cout << "Input: \"algorithm\", \"logarithm\"\n" << "Output: " << calc.EditDistance("algorithm", "logarithm") <<"\n" << endl;
    return 0;
}
