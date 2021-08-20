/*
N명.  S ~ M 장기자랑.  N-1명 남고, 그 다음 직원부터 또 M번째 장기자랑
*/

#include <iostream>
#include <queue>

using namespace std;

int N, S, M;
void input() {
    cin >> N >> S >> M;;
}

queue<int> q1, q2;

void solve() {
    int j=S;
    for(int i=1; i<=N; i++) {
        q1.push(j);
        if(++j > N) j = 1;
    }
    for(int i=0; i<N; i++) {
        if(!q1.empty()) {
            for(int j=0; j<M-1; j++) {
                int cur  = q1.front();
                q1.pop();
                q1.push(cur);
            }
            q2.push(q1.front());
            q1.pop();
        }
    }

    while(!q2.empty()) {
        cout << q2.front()  << ' ';
        q2.pop();
    }
    
}

int main() {
    input();
    solve();
    return 0;
}