/*
격자에서 A-> 로 이동하기 위한 최소갑 -> BFS
최소값을 구할 방법은...강의 참고함.
visit 배열을 아주 크게 잡아 놓고,  dst의 의 visit 배열 >  src의 visit배열 + dst 의 실제값 일때만 
dst의 visit 배열 = src visit 배열 + dst 실제값 갱신 및 큐 저장
while 루프 종료 후,  visit[N-1][N-1]이 답.

다시 내 식대로 .. 
모든 좌표의 누적값을 저장한다. 그 좌표가 다른경로를 통해 또 올 수도 있으니 방문체크는 하지말자. 
대신 이미 저장된 누적값이 더 클때만 갱신하자. 고로, 초기화시 최대값을 저장해놔야 한다.
누적값이 더 클때란 의미는 좀 전에 지나친 곳은 또 갈 필요 없다는 말임.
*/

#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int  N;
int A[101][101];
int check[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void go(int first) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = first;

    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if(nx >= 0 && nx < N && ny >=0 && ny < N) {
                if(check[nx][ny] > check[cur.first][cur.second] + A[nx][ny]) {
                    check[nx][ny] = check[cur.first][cur.second] + A[nx][ny];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    cout << check[N-1][N-1] << '\n';
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%1d", &A[i][j]);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            check[i][j] = INT_MAX; 
        }
    }
    go(A[0][0]);
    return 0;
}