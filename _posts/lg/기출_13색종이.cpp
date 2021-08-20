/**
 * 다시 볼 필요 없다
 * 05 그림인식과 유사.
 *  N*N  최대 9 color
 * 가정 많이 겹친 위치 카운트
 * 각 컬러의 left/top, right/bottom 을 알아내서 위치 카운트를 증가시키자.
 * 부분 점수밖에 못 얻는다...솔루션(Solve)도 비슷하게 풀었지만 내 코드(solve)의 버그가 있겠찌.
 * 
 */
#include <iostream>
using namespace std;

int N;
int L[10][10];
bool color[10];
int C[10][10];  //0 빈 공간
pair<int, int> LT[10];
pair<int, int> RB[10];

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%1d", &L[i][j]);
            if(L[i][j] > 0) color[L[i][j]] = true;
        }
    }
    for(int c=1; c<=9; c++) {
        LT[c].first = LT[c].second = -1;
        RB[c].first = RB[c].second = -1;
    }

}
void solve() {
    for(int c=1; c<=9; c++) {
        if(color[c] == false) continue;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(L[i][j] == c) {
                    if(LT[c].first == -1 || LT[c].first > i) LT[c].first = i;
                    if(LT[c].second == -1 || LT[c].second > j) LT[c].second = j;
                    if(RB[c].first == -1 || RB[c].first < i) RB[c].first = i;
                    if(RB[c].second == -1 || RB[c].second < j) RB[c].second = j;
                //    cout << "coord [" << c <<  "]" << LT[c].first << " ," << LT[c].second << ", " << RB[c].first << ", " << RB[c].second;
                }
            }
        }
    }
    int max = 0;
    for(int c=1; c<=9; c++) {
        if(color[c] == false) continue;
        for(int i=LT[c].first; i<=RB[c].first; i++) {
            for(int j=LT[c].second; j<=RB[c].second; j++) {
                C[i][j]++;
                max = (max, C[i][j]);
            }
        }
    }
    cout << max << '\n';
}
void Solve() {
    int i, r, c, minr, minc, maxr, maxc, cnt = 0;
    int check[10+2][10+2] = {0};
    for(i=1; i<=9; i++) {
        minr = minc = 10;
        maxr = maxc = 0;
        for(r=0; r<N; r++) {
            for(c=0; c<N; c++) {
                if(L[r][c] != i) continue;
                if(minr > r) minr = r;
                if(maxr < r) maxr = r;
                if(minc > c) minc = c;
                if(maxc < c) maxc = c;
            }
        }
        if(minr  == 10) continue;
        for(r=minr; r<=maxr; r++) {
            for(c=minc; c<=maxc; c++) {
                check[r][c]++;
            }
        }
    }
    for(r=0; r<N; r++) {
        for(c=0; c<N; c++) {
            if(cnt < check[r][c]) cnt = check[r][c];
        }
    }
    cout << cnt << '\n';

}

int main() {
    input();
    Solve();
    return 0;
}
