// 6  <= N <= 80000,   1 <= H <= 1000000000
// 오로지 낮은 건물 너머로 다음 건물 볼 수 있음 (같아도 넘길수 없음)
// 5 2 4 2 6 1
// push 5,  while(!empty) { (5 > 2) break; } cnt += size(), push(2)
// while(!empty)   (5)  (2 <=4) pop,   (5 > 4) break }  cnt += size(), push(4)
// while(!empty)   (5)  (4 > 2) break }  cnt += size(), push(2)
// while(!empty)   (5, 4)  (2 <= 6) pop,  (4 <= 6) pop, (5 <= 6) pop}  cnt += size(), push(2)

// 스택이 비워있을 떄까지, 스택탑의 높이 > 현재 높이이면 break, 아니면 POP.  스택의 갯수 더하고 현재 높이 PUSH. 

#include <iostream>
#include <stack>
using namespace std;

int N, cnt = 0;;
int A[80001];

void solve() {
    stack<int> s;
    s.push(A[0]);
    for(int i=1; i<N; i++) {
        while(!s.empty()) {
            if(s.top() > A[i]) break;
            else s.pop();
        }
        cnt += s.size();
        s.push(A[i]);
    }
    cout << cnt << '\n';
}
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    solve();
    return 0;
} 