/**
 * 거리 배열을 최대화로 초기화
 * 정점만큼 BFS 루프 돌림
 * BFS의 내부에서는 
 *  1. check 배열 최대값 초기화
 *  2. Q Push, check 값 갱신 
 *  3. 큐가 비어있을때까지,  1~N까지 Loop
 *  4. Loop의 조건 : check[i] > check[cur] + dist[cur][i]
 *  5. 조건에 만족하면  Q Push, check 값 갱신
 *  6. while문 밖에서,  1~N 
 */

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

#define MAXN 1000000
int N, M;
int check[101];
int dist[100][101];
queue<int> q;

void init() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) 
            dist[i][j] = MAXN;
    }
}

void input() {
    cin >> N >> M;
    init();
    for(int i=0; i<M; i++) {
        int A,B,D;
        cin >> A >> B >> D;
        dist[A][B] = dist[B][A] = D;
    }
}

int bfs(int c) {
    for(int i=1; i<=N; i++) check[i] = MAXN;
    q.push(c);
    check[c] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i=1; i<=N; i++) {
            if(check[i] > check[cur] + dist[cur][i] ) {
                check[i] = check[cur] + dist[cur][i];
                q.push(i);
            }
        }
    }
    int maxn = 0;
    for(int i=1; i<=N; i++) {
        maxn = max(maxn, check[i]);
    }
    return maxn;
}

void go() {
    int minn = MAXN;
    for(int i=1; i<=N; i++) {
        minn = min(minn, bfs(i));
    }
    cout << minn << '\n';
}

int main() {
    input();
    go();
    return 0;
}
 