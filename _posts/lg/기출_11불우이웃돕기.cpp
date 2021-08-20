/**
 * 그리디
 * solution1)
 * 큰 것부터, 나를 제외하고 나머지로 커버할 수 있는지. 
 * 나머지 > N 이면 나는 포함시킬 필요 없다.
 * 나머지 <= N 이면 나를 써야한다. 보낼갯수 = ( (N-나머지) / 나의 단위 숫자 )  나머지가 있으면 +1 
 * 
 * solution2)
 * 반대로 생각하자. 보내는게 아니라 남겨질 갯수를 계산.
 * 총합에서 주어진 N을 빼고 토탈에 저장
 * 9부터 0까지.. 카운트 = 토탈 / 유닛.  카운트 > A[i] 이면 카운트는 A[i]
 * 토탈에서 유닛*카운트 뺀다.
 * sol[i] = 각 입력값 - 카운트 
 * totalcnt += sol[i]
 * 
 */
#include <iostream>

using namespace std;
int N;
int n[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
int A[10];
int sol[10];
int total = 0;
void input() {
    cin >> N;
    for(int i=0; i<10; i++) {
        cin >> A[i];
        total += A[i] * n[i];
    }
    total -= N;
}

void go() {
    int cnt = 0, totalcnt = 0;
    for(int i=9; i>=0; i--) {
        cnt = total / n[i];
        if(cnt > A[i]) cnt = A[i];
        total -= n[i] * cnt;
        sol[i] = A[i] - cnt;
        totalcnt += sol[i];
    }
    cout << totalcnt << '\n';
}

int main() {
    input();
    go();
    for(int i=0; i<10; i++) {
        cout << sol[i] << ' ';
    }
    return 0;
}