/*
  제품 : 6 <= N <= 50000  종류별 최소 1개 포함. 사진 길이 짧게.
  좌표  1 <= X  <= 1000000000
  ID  1 <= X  <= 1000000000
  사진길이 마지막X-첫번째X

  N제곱으로 하면 시간초과.
  cnt를 세서 cnt가 3이 되는 것을 한 세트로 간주.
  cnt가 1 또는 2일때 가장 마지막 인덱스만 저장   index1, index2
  cnt 3일때  cnt3일때의 인덱스 - index1 하면 값이 나옴.
  다음 셋트 돌릴때, index2부터 다시 시작.
  
  잘 안풀려서, 해답 참고 (Sliding Window 사용)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;
vector<pair<int, int>> V;
set<int> P;
int check[50000] = {0};

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int X, ID;
        cin >> X >> ID;
        V.push_back (make_pair(X, ID) );
        P.insert(ID); // P 갯수 세기 위해 (중복 허용하지 않는 set 사용)
    }
    sort(V.begin(), V.end());
}

void solve() {
    int i = 0, j = 0, cnt = 0, min = 1000000000;
    int max_id_cnt = P.size();

    for( ;; ) {
        while((i < N) && (max_id_cnt > cnt)) {
            if(check[V[i].second]++ == 0) cnt++;
            i++;
        }
        if(max_id_cnt != cnt) break;
        while(check[V[j].second] > 1) {
            check[V[j].second]--;
            j++;
        }
        if(min > V[i-1].first - V[j].first) min = V[i-1].first - V[j].first;
        cnt--;
        check[V[j].second] = 0;
        j++;
    }
    cout << min << '\n';
}
int main() {
    input();
    solve();
	return 0;
}