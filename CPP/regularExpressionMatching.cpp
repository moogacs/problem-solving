/*

   Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.


   '.' Matches any single character.

   '*' Matches zero or more of the preceding element.

   The matching should cover the entire input string (not partial).


Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

*/

#include <vector>
#include <iostream>

using namespace std;

// To get to this solution, you need to have a strong understanding of dynamic programming.
// First let's think of a simple way to solve the question, in particular when we have a
// * pattern. Without it we would only check the pattern from left to right and match with
// the string, but when it's present, we need to check recursively if we can ignore this part
// of the pattern, which means 0 characters, or erase the matching character if possible and 
// check for the same pattern. The last step makes it possible to check for any occurrences
// of said character since we will check the matching character without changing the pattern,
// so we will be checking for the * again.
// 
// Now let's think of what we are trying to achieve with this. We are basically checking if 
// the substring of string s starting from i matches the substring of pattern p starting from j.
// If we keep track if both match or not, we can avoid repeating matching checks in our recursion.
// That way we could introduce a Hash Table with the key being (i, j) and if they match or not.
// Going to a bottom-up approach, we know that the substring that starts at the end of s matches
// the substring that starts at the end of p, since both are the empty string, and from there we can
// start building up our array of boolean values. First we check if the s[i] matches with p[j], or
// if p[j] is '.', since it will match with any character. Then we define our dp[i][j] as this match and
// the match of the subsequent substring from s and p, since we have matched i and j, now we are checking
// the next characters in line. But if this is a * pattern, which means the first letter after j is *,
// we need to do what we did previously in our recursive answer, check if ignoring the pattern is a match,
// or checking if we have an initial match and checking the next substring of s without changing our 
// pattern. 
//
// At the end of this building process, our array at the index (0, 0) will contain the answer if
// the substring of s starting at 0, which is s, matches the substring of p starting at 0, which is p. 
// Therefore we arrived at our solution successfully.
bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[s.size()][p.size()] = true;

    for (int i = s.size(); i >= 0; i--) {
        for (int j = p.size() - 1; j >= 0; j--) {
            bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            if (j + 1 < p.size() && p[j + 1] == '*') 
                dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
            else
                dp[i][j] = firstMatch && dp[i+1][j+1];
        }
    }

    return dp[0][0];
}

int main() {
    // Read input
    string text, pattern;
    cin >> text >> pattern;

    // Write output
    cout << (isMatch(text, pattern) ? "true": "false") << endl;

    return 0;
}
