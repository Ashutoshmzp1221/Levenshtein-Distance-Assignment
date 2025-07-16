#include <iostream>
#include <vector>
#include <string>
#include "task2.cpp"
using namespace std;

Task2 T2;
class Task3 {
    public:
    vector<string> spellCheacker(string input, vector<string> dictionary, int Ci, int Cd, int Cs) {
        int minCost = INT_MAX;
        vector<string> result;

        for(const string& str : dictionary) {
            int currCost = T2.EditDistance(input, str, Ci, Cd, Cs);
            if(currCost < minCost) {
                minCost = currCost;
                result.clear();
                result.push_back(str);
            } else if(currCost == minCost) {
                result.push_back(str);
            }
        }
        return result;
    }
};

int main() {
    Task3 t3;
    vector<string> dictionary = {"cred", "bet", "shat", "that", "brad", "cart", "brat", "card"};
    string input = "dat";
    vector<string> matches = t3.spellCheacker(input, dictionary, 1, 1, 1);
    cout << "Input: " << '"'<<input <<'"'<< endl;
    cout << "Output: ";
    for (const string& word : matches) {
        cout << '"'<<word <<'"' << " ";
    }
    cout << endl;
    return 0;
}