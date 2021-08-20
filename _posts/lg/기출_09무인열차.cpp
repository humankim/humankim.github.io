/*
FloodFill 을 통해 그룹핑을 해놓고,
그 안에서 4방향 모두 가는 (감싸져 있는) 경우를 제외하곤, 큐에 삽입해 놓는다. 

BFS 연산, cur를 기준으로 4방향.. next는 좌표 뿐 아니라 cur.t + 1씩 큐에 저장
새로운 그룹이 나오면 cur.t를 리턴.
tuple 사용 :  typedef tuple<int,int,int> tu; make_tuple(0, 0, 0);
*/
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int A[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
typedef tuple<int, int, int> coord;
queue<coord> q;

void input() {
    cin >> N >> M;
      for(int i=0; i<N; i++) {
          for(int j=0; j<M; j++) {
              cin >> A[i][j];
          }
      }
}
int floodfill(int x, int y) {
    if(A[x][y] != 1) return 0;
    A[x][y] = 2;
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >=0 && ny < M) {
            cnt += floodfill(nx, ny);
        }
    }
    if(cnt < 4) {
        q.push(make_tuple(x, y, 0));
    }
    return 1;
}
void callFloodFill() {
      for(int i=0; i<N; i++) {
          for(int j=0; j<M; j++) {
              if(A[i][j]==1) {
                  floodfill(i, j);
                  return;
              }
          }
      }
}
int bfs() {
    while(!q.empty()) {
        coord cur = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int nx =  get<0>(cur) + dx[i];
            int ny =  get<1>(cur) + dy[i];
            if(nx >= 0 && nx < N && ny >=0 && ny < M) {
                if(A[nx][ny] == 1) {
                    return get<2>(cur);
                }
                if(A[nx][ny] == 0) {
                    q.push(make_tuple(nx, ny, get<2>(cur)+1));
                }
            }
        }
    }
    return -1;
}

int main() {
    input();
    callFloodFill();
    cout << bfs() << '\n';
    return 0;
}