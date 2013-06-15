/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Your friend John uses a lot of emoticons when you talk to him on Messenger. 
 * In addition to being a person who likes to express himself through emoticons, 
 * he hates unbalanced parenthesis so much that it makes him go :(
 * 
 * Sometimes he puts emoticons within parentheses, 
 * and you find it hard to tell if a parenthesis really is a parenthesis or part of an emoticon.
 * 
 * A message has balanced parentheses if it consists of one of the following:
 * - An empty string ""
 * - One or more of the following characters: 'a' to 'z', ' ' (a space) or ':' (a colon)
 * - An open parenthesis '(', followed by a message with balanced parentheses, followed by a close parenthesis ')'.
 * - A message with balanced parentheses followed by another message with balanced parentheses.
 * - A smiley face ":)" or a frowny face ":("
 * Write a program that determines if there is a way to interpret his message while leaving the parentheses balanced.
 *
 * 
 * Input
 * The first line of the input contains a number T (1 ≤ T ≤ 50), the number of test cases. 
 * The following T lines each contain a message of length s that you got from John.
 * 
 * Output
 * For each of the test cases numbered in order from 1 to T, 
 * output "Case #i: " followed by a string stating whether or not it is possible that the message had balanced parentheses. 
 * If it is, the string should be "YES", else it should be "NO" (all quotes for clarity only)
 * 
 * Constraints
 * 1 ≤ length of s ≤ 100
 * 
 * Example input
 * 5
 * :((
 * i am sick today (:()
 * (:)
 * hacker cup: started :):)
 * )(
 *
 * Example output
 * Case #1: NO
 * Case #2: YES
 * Case #3: YES
 * Case #4: YES
 * Case #5: NO
 * -------------------------------------------------------------}}}*/
#include <iostream>
#include <stdio.h>
using namespace std;

bool solve(const char * s, int l, int r, int nl) {
    if (l > r) return nl == 0;

    bool done = false;
    switch (s[l]) {
        case '(':
            done = solve(s, l+1, r, nl+1);
            if (!done) {
                if (l+1<=r && s[l+1] == ':')
                    done = solve(s, l+2, r, nl);
            }
            break;
        case ')':
            done = nl>0?solve(s, l+1, r, nl-1):false;
            if (!done) {
                if (l+1<=r && s[l+1] == ':')
                    done = solve(s, l+2, r, nl);
            }
            break;
        case ':':
            done = solve(s, l+1, r, nl);
            if (!done) {
                if (l+1<=r && (s[l+1] == '(' || s[l+1] == ')'))
                    done = solve(s, l+2, r, nl);
            }
            break;
        default:
            while (s[l] != '(' && s[l] != ')' && s[l] != ':') ++l;
            done = solve(s, l, r, nl);
            break;
    }
    return done;
}

bool solve(const char * s) {
    int len=0;
    if (s) for (; s[len]; ++len);
    return solve(s, 0, len-1, 0);
}

int main() {
    int N;
    char s[101];
    scanf("%d\n", &N);
    for (int i=1; i<=N; ++i) {
        cin.getline(s, sizeof(s));
        printf("Case #%d: %s\n", i, (solve(s)?"YES":"NO"));
    }
    return 0;
}
