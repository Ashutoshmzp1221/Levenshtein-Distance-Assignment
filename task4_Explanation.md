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

    1. Space optimisation by using only two rows of the array:-
        - So in this technique we don't need to store the entire DP matrix rather we will use only two rows i.e previous row and currect row at any time.

        <img width="573" height="489" alt="Screenshot 2025-07-16 at 5 56 40 PM" src="https://github.com/user-attachments/assets/464ac3d4-8fdf-40fe-a5ee-ed9cf315fd94" />

        Above is the provide snapshot of the optimized code.
        - This will reduce the space complexity and final space complexity will be :- 
            - Space Complexity :- O(min(n,m));

    2. Optimising the time by using early termination:-
        - As we can see that in the standard levenstein algorithm we use to compute the entire DP table even if we have to only care about whether distance <= k.
        - For example like if we see in real world scenario like in spell checker if a maximum acceptable distance k is known we can abort the calculation early when it exceeds this threshold.
        - This will avoid the uncessary computations and this will might optimize the time a bit.
