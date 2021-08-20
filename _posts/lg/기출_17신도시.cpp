/*
Lookup table을 만들자.
*/

// if(A[map[i][j]][0] == 1)  상   
// if(A[map[i][j]][1] == 1)  하
// if(A[map[i][j]][2] == 1)  좌
// if(A[map[i][j]][3] == 1)  우
//  상 <->하    좌<->우  가 연결되므로
//  i 가 dir[i] 과 연결된다 가정했을 때, 
// dir[4] = {1, 0, 3, 2}; 로 해놓고  현재는 그냥i, 대상은 dir[i] 히자.
#include <iostream>
#include <queue>
using namespace std;

int N;
int X, Y;
int D[10][10];
bool check[10][10];
//Lookup table
int A[][4] = {
    {0, 0, 0, 0},
    {0, 0, 1, 1},
    {1, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 0, 1, 0},
    {1, 0, 0, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 1, 1},
};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dir[4] = {1, 0, 3, 2}; 
int zerocount = 0;

void input() {
    cin >> N;
    cin >> X >> Y;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%1d", &D[i][j] );
            if(D[i][j] == 0) zerocount++;
        }
    }

}

void bfs() {
    int cnt  = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(Y, X));
    check[Y][X] = true;
    cnt++;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(A[D[cur.first][cur.second]][i] == 1 && A[D[ny][nx]][dir[i]] == 1 && check[ny][nx] == false) {
                    q.push(make_pair(ny, nx));
                    check[ny][nx] = true;;
                    cnt++;
                }
            }
        }
    }
    int total = (N*N)-zerocount-cnt;
    cout << total << '\n';
}

int main() {
    input();
    bfs();
    return 0;
}