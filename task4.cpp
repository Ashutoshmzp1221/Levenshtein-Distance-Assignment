#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task4 {
    public:
    int optimisedEditDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++) {
            curr[0] = i;
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) curr[j] = prev[j - 1];
                else {
                    curr[j] = 1 +  min({
                        prev[j],
                        curr[j - 1],
                        prev[j - 1]
                    });
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    Task4 calc;
    cout << "\nTesting for the Task4 that is the optimise version of first task" << endl; 
    cout << "Input: \"kitten\", \"sitting\"\n" << "Output: " << calc.optimisedEditDistance("kitten", "sitting") <<"\n"<< endl;
    cout << "Input: \"flaw\", \"lawn\"\n" << "Output: " << calc.optimisedEditDistance("flaw", "lawn") <<"\n" << endl;
    cout << "Input: \"algorithm\", \"logarithm\"\n" << "Output: " << calc.optimisedEditDistance("algorithm", "logarithm") <<"\n" << endl;
    return 0;
}
