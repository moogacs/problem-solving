/*

   Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

   A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void printVector(vector<string>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << "\"" <<v[i] << "\"";
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]";
}

// So we need to MAP letters to numbers, I wonder WHAT we could use to do that. Yes, that's
// right, we use a Hash Table a.k.a. Hash Map a.k.a. std::unordered_map<K, V>. The only 
// complicated part of the question is the fact that it asks you for every possible combination,
// which clearly indicates this is a backtracking question. For every digit we read, we need to
// check all combinations that can be made with all the characters in  our map for that key,
// so we basically recurse over all combinations and once we processed the whole string of digits,
// we add that combination to our answer.
void helper(string combination, string digits, unordered_map<char, string>& map,
        vector<string>& output) {
    if (digits.empty())
        output.push_back(combination);
    else {
        string letters = map[digits[0]];
        for (auto letter : letters) {
            helper(combination + letter, digits.substr(1), map, output);
        }
    }
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";

    vector<string> output;
    if (!digits.empty()) helper("", digits, map, output);
    return output;
}

int main() {
    // Read input
    string input;
    while (cin >> input) {
        // Write output
        auto answer = letterCombinations(input);
        printVector(answer);
    }

    return 0;
}
