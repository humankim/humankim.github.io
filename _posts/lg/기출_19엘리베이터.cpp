/*
 최소 엘베.
 높이  N 층,  좌측- , 우측+
 각층 공급, 소비 좌표
  층간 이동 위해 엘베.
  소비 >= 공급
   if(소비 == 공급) 엘베 도달 ok
  지하층 : 전체 가이드 라인 설치

  정렬 후, a와  b좌표의 비교과정.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
typedef struct {
    int a, b;
} FL;
vector<FL> V;

bool comp_a(FL& fl1, FL& fl2) {
    return fl1.a < fl2.a;
}

bool comp_b(FL& fl1, FL& fl2) {
    return fl1.b < fl2.b;
}

void input() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        int A, B;
        cin >> A >> B;
        FL inputf; inputf.a = A; inputf.b = B;
        V.push_back(inputf);
    }
    #if 0   //A기준 정렬
    sort(V.begin(), V.end(), comp_a);
    #else 
    sort(V.begin(), V.end(), comp_b);
    #endif

    for(int i=0; i<N; i++) {
      cout << V[i].a << ',' << V[i].b << ' ';
    }
}
void solve() {
    int ante = 1;
    int bb = V[0].b;
    for(int i = 1; i < N; i++) {
        if(V[i].a > bb) {
            ante++;
            bb = V[i].b;
        } else if(V[i].b < bb) {
            bb = V[i].b; //B기준 정렬했을 땐 불필요.
        }
    }
    cout << ante  << '\n';
}

int main() {
    input();
    solve();
    return 0;
}