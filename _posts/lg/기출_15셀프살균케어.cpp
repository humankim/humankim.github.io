/**
  N*N 필터
  좌표길이 L
  M 살균대상 좌표

  k = 1 ~ (L/2)
  1~K-1 Loop   ->  h-1; h<K; h++
     w = k-h;
       이중 루프.
          x,y,w,h 매개변수로 한 함수호출..함수내에선 그 안에서 카운트를 셈
 */

#include <iostream>

using namespace std;

int N,L,M; 
int x[100];
int y[100];

void input() {
    cin >> N >> L >> M;
    for(int i=0; i<M; i++) {
        cin >> x[i] >> y[i];
    }
}

int mycount(int r, int c, int h, int w) {
    int i, cnt = 0;
    for(i=0; i<M; i++) {
        if((r <= y[i]) && (y[i] <= h) && (c <= x[i]) && (x[i] <= w)) cnt++;
    }
    return cnt;
}

int solve() {
     int h, w, offset, i, maxv = 0, cnt, k = L/2;
     for(h=1; h < k; h++) {
         w = k-h;
         for(offset = 0; offset <= w; offset++) {
             for(i=0; i<M; i++) {
                 cnt = mycount(y[i], x[i] - offset, y[i] _ h, x[i] - offset +_ w);
                 if(maxv < cnt) maxv = cnt;
             }
         }
     }
     return maxv;
 }

 int main() {
     input();
     solve();
     return 0;
 }