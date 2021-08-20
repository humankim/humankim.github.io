/*
 1. stack_TOP < 현재높이 :갯수만큼 ++
 2. stack_TOP == 현재높이 : +1
 3. PUSH(현재높이)
*/
#include <iostream>
#include <stack>
using namespace std;

int N;
int H[10<<5];;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> H[i];
    }
}

void solve() {
    int cnt = 0;
    stack<int> s;
    for(int i=0; i<N; i++) {
        while(!s.empty() && s.top() < H[i]) {
            cnt++;
            s.pop();
        }
        if(!s.empty()) {
            cnt++;
            if(s.top() == H[i]) s.pop();
        }
        s.push(H[i]);
    }
    cout << cnt << '\n';
}

int main() {
    input();
    solve();
    return 0;
}