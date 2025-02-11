// Problem Link
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

// Source Code

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int partLen = part.size();

        for (char c : s) {
            stk.push(c);

            // Check if the last "partLen" characters in the stack match "part"
            if (stk.size() >= partLen) {
                string temp = "";
                for (int i = 0; i < partLen; i++) {
                    temp = stk.top() + temp;
                    stk.pop();
                }

                // If temp is not "part", push it back onto stack
                if (temp != part) {
                    for (char ch : temp) {
                        stk.push(ch);
                    }
                }
            }
        }

        // Build the resulting string from the stack
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};
