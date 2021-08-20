/*
 [ 솔루션 참고 ]
  1부터 9까지의 색상이 주어지니   최초 1~9까지 루프를 돌리자 

  그안에서 다시 전체 루프를 돌리며 해당 숫자가 같은 것의 최소최대 가로값 세로값 (위치)를 구하자
  최소값이 구해지지 않은 것은  없는 색이라 간주하고 Continue 하자
  해당 체크 배열에 1을 넣자 (없는 색과 구분하기 위함)
  최소 최대값의 이중루프를 돌려서 해당 색이 아닌 것을 찾아 체크배열의 값을 하나씩 증가시키자 (그럼 덧철한 것이다)

  새로운 1~9 루프를 열어 체크배열이 1인 것만 찾자 . 이것이 숫자는 있되, 덧칠되지 않은 것이다 

*/
#include <iostream>
#include <queue>

using namespace std;
int N;
char A[11][11];

void go() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    //check[0][0] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
    }
}
void solve() {
    int i, r, c, minr, minc, maxr, maxc, cnt = 0;
    int check[10] = {0};
    for(i='1'; i<= '9'; i++) {
        minr = minc = 10;
        maxr = maxc =0;
        for(r =0; r < N; r++) {
            for(c =0; c < N; c++) {
                if( A[r][c] != i) continue;
                if(minr > r) minr = r;
                if(maxr < r) maxr = r;
                if(minc > c) minc = r;
                if(maxc < c) maxc = r;
            }
        }
        if(minr == 10) continue;
        check[i-'0']++;
        for(r=minr; r<=maxr; r++) {
            for(c = minc; c <=maxc; c++) {
                if(A[r][c] == i) continue;
                check[A[r][c]-'0']++;
            }
        }
    }
    for(i=1; i<=9; i++) {
        if(check[i] == 1) cnt++;
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