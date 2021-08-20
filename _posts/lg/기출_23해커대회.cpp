/*
주어진 문자열 + 커맨드로 문자열 조작.
두개의 스택으로 하면 풀이가 쉽다.
s1은 bottom 부터 읽고, s2는 top부터 읽고.
*/

#include <iostream>
#include <stack>
#include <algorithm> //reverse
#include <cstring> //strcpy

using namespace std;

#define MAXN  100001
string S, C;
char SA[MAXN];
char CA[5*MAXN];
stack<char> s1, s2;

void input() {
    cin >> S;
    cin >> C;

    strcpy(SA,  S.c_str());
    strcpy(CA,  C.c_str());

    for(int i=0; i<S.length(); i++) {
        s1.push(SA[i]);
    }
}
void answer() {
    string ans1 = "", ans2 = "";
    while(!s1.empty()) {
        ans1 += s1.top();
        s1.pop();
    }
    reverse(ans1.begin(), ans1.end());
    while(!s2.empty()) {
        ans2 += s2.top();
        s2.pop();
    }
    cout << ans1 <<  ans2 << '\n';
}
void solve() {
    for(int i=0; i<C.length(); i++) {
        char cmd = C[i];
        switch(cmd) {
            case 'L':
            {
              char cur1 = s1.top(); 
              s1.pop();
              s2.push(cur1);
              break;
            }
            case 'R':
            {
              char cur2 = s2.top(); 
              s2.pop();
              s1.push(cur2);
              break;
            }
            case 'B':
            {
              s1.pop();
            break;
            }
            default:
            {
                s1.push(cmd);
            break;
            }
        }
    }

}

int main() {
    input();
    solve();
    answer();
    return 0;
}