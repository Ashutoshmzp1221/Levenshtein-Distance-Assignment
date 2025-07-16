#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task2 {
    public:
    int EditDistance(string s1, string s2, int Ci, int Cd, int Cs) {
        int n = s1.length();
        int m = s2.length();

        vector< vector<int> > dp(n + 1, vector<int> (m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = i * Cd;
        for(int j = 0; j <= m; j++) dp[0][j] = j * Ci;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(
                        dp[i][j - 1] + Ci,
                        min(dp[i - 1][j] + Cd, dp[i - 1][j - 1] + Cs)
                    );
                }
            }
        }
        return dp[n][m];
    }
};

// int main() {
//     Task2 t;
//     cout << "Input: \"kitten\", \"sitting\", 1, 2, 3 \n" << "Output: " << t.EditDistance("kitten", "sitting", 1, 2, 3)<<"\n" << endl;
//     cout << "Input: \"flaw\", \"lawn\", 2, 2, 1) \n" << "Output: "<< t.EditDistance("flaw", "lawn", 2, 2, 1) << "\n" <<endl;
//     cout << "Input: \"algorithm\", \"logarithm\", 1, 3, 2 \n" << "Output: " << t.EditDistance("algorithm", "logarithm", 1, 3, 2) << "\n"<<endl;
//     return 0;
// }