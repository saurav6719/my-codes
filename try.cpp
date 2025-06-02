#include <bits/stdc++.h>
using namespace std;

// Helper function: ek character ka case toggle karta hai
char toggleCase(char c) {
    if ('a' <= c && c <= 'z')  return char(c - 'a' + 'A');
    if ('A' <= c && c <= 'Z')  return char(c - 'A' + 'a');
    return c; // parentheses ya koi aur non-letter character yahan nahin aayega
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = (int)S.size();

    // 1) Precompute matching parentheses indices
    vector<int> match(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (S[i] == '(') {
            st.push(i);
        } else if (S[i] == ')') {
            int j = st.top();
            st.pop();
            match[i] = j;
            match[j] = i;
        }
    }

    // 2) Single pass: direction & flip flag
    string ans;
    ans.reserve(n); // roughly size of final string (parentheses hatjayenge)

    int direction = +1;  // +1 = aage, -1 = peeche
    bool flip = false;   // agar true, toh letters ko toggleCase karenge
    int i = 0;

    while (i >= 0 && i < n) {
        if (S[i] == '(' || S[i] == ')') {
            // Parenthesis encounter → flip toggle & direction reverse
            flip = !flip;
            direction = -direction;
            // Jump to matching bracket, phir ek step aur age/peeche
            i = match[i] + direction;
        } else {
            // Letter: agar flip==true → toggle case, else as is
            if (flip) {
                ans.push_back(toggleCase(S[i]));
            } else {
                ans.push_back(S[i]);
            }
            i += direction;
        }
    }

    // Ab ans mein final string hai (sab parentheses hata ke, reversed & toggled)
    cout << ans;
    return 0;
}
