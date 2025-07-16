# Explanation how we can optimize the function further 

## Problem explanation
    - The standanrd Levenstein algorithm uses the DP table of size "n x m" where:
        n = length of string s1
        m = length of string s2
    - This results in :
        Time Complexity: O(n x m)
        Space Complexity: O(n x m)
    This is efficient for the small inputs but if we have very large string then this approach can become impractical due to the memory and time constraints.


## So to optimize the above problem we can use the following techniques:

    1. Space optimisation by using only two rows:-
        - So in this technique we don't need to store the entire DP matrix rather we will use only two rows i.e previous row and currect row at any time.

        `vector<int> prev(n + 1), curr(n + 1)`
        By using the above declaration we will declare these two rows to compute the curr and 
