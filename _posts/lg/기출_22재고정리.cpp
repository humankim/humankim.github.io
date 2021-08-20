/*
   N개 제품, M개 종류
   1 2 2 2 1 2 1
   5번째를 0번쨰를 서로 (2회) 바꾸면 끝

   DFS돌려서 종류의 순서를 배치. 시퀀스배열에 현재 숫자 저장.
   갯수 도달하면 주어진 입력값과 몇개가 배열에 저장된 숫자와 틀린지 카운트.
*/
#include <iostream>
using namespace std;

int N, M;
int sum[10][10001]; // 구간합
int A[100001];
int ans = 0;
int cnt[10];
int seq[10];
bool check[10];

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
}
int getCount() {

}
//종류가 3개일 경우,  {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1} 을 만든다. 인덱스가 도달했을 떄, 최소갯수 구함.
void dfs(int n, int p, int m) {
    if(ans <= m) return;//이전답보다 좋지 않음
    if(n > M) {
        ans = m; 
        return;
    }
    for(int i=1; i<=M; i++) {
        if(check[i] == false) {
            check[i] = true;
            int mcnt = cnt[i] - (sum[i][p+cnt[i] -1] - sum[i][p-1]);
            dfs(n+1, p + cnt[i], m + mcnt);
            check[i] = false;
        }
    }
}
void solve() {
    for(int i=1; i<=N; i++) sum[A[i]][i] = 1;
    for(int i=1; i<=M; i++) {
        for(int j=2; j <= N; j++) sum[i][j] += sum[i][j-1];
        cnt[i] = sum[i][N];
    }
    ans = N;
    dfs(1, 1, 0);
    cout << ans << '\n';
}
int main() {
    input();
    solve();
    return 0;
}