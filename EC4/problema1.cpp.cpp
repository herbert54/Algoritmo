// class Solution {
// public:
//     int maxDepth(string s) {
        
//     }
// };



#include <iostream>
#include <string>
#include <stack>

using namespace std;

int depth(string s) {
    int max_depth = 0;
    int current_depth = 0;
    stack<char> parentheses;

    for (char c : s) {
        if (c == '(') {
            parentheses.push(c);
            current_depth++;
            max_depth = max(max_depth, current_depth);
        } else if (c == ')') {
            parentheses.pop();
            current_depth--;
        }
    }

    return max_depth;
}

int main() {
    // Ejemplo 1
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << s1 << endl;
    cout <<  depth(s1) << endl << endl;

    // Ejemplo 2
    string s2 = "(1)+((2))+(((3)))";
    cout << s2 << endl;
    cout <<depth(s2) << endl << endl;

    return 0;
}