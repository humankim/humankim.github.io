/**
   <아주 평이함. 다시 볼 필요 없음>
  직원수  1 <= N <= 100000
  산책시간   1 <= T <= 1000000000
  직원개별 출발위치   0 <= Pi <= 1000000000
  직원개별 산책속도   0 <= Si <= 1000000000
  역탐색만 하면 간단하게 풀이됨
 */

#include <iostream>

using namespace std;

#define MAXN 1000000
int N, T;
long long P[MAXN], S[MAXN], L[MAXN];
int gcount = 0;

void solve() {
    for(long long i=N-1; i>=0; i--) {
        L[i] = P[i] + ((long long)T * S[i]);
        if( (i < N-1) && (L[i] > L[i+1]) ) {
            L[i] = L[i+1];
        }
        if ( (i==N-1) || L[i] < L[i+1]) {
            gcount++;
        }
    }
    cout << gcount << '\n';
}
void input() {
    cin >> N >> T;
    for(long long i=0; i<N; i++) {
        cin >> P[i] >> S[i];
    }
}
int main() {
    input();
    solve();
    return 0;
}