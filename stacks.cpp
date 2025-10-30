class Solution {
public:
    bool isValid(string s) {
        // Create a stack to store the opening brackets
        stack<char> st;
        
        // Iterate through each character in the input string
        for (char c : s) {
            // If the character is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If it's a closing bracket, the stack must not be empty
                // (meaning there's no matching opening bracket)
                if (st.empty()) return false;
                
                // Check if the closing bracket matches the top of the stack
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    // Mismatch found
                    return false;
                }
                
                // If it matches, pop the opening bracket from the stack
                st.pop();
            }
        }
        
        // After iterating through the string, the stack must be empty
        // for the string to be valid (meaning all brackets were matched)
        return st.empty();
    }
};