/*
 내 : -1000000000 ~ -1, 외 : 1 ~ 1000000000
 내1 + 외1  = 0에 가깝게
 다 연산하면 시간초과 나므로, 정렬해서 서로 이웃한 것만 검사하자.    0-1, 1-2, 2-3, ... 
 ; 보다 좋은 방법은 정렬 필요없이 맨앞 맨뒤를 줄여나가는 식..
 i + j 가 0이면 끝.
 절대값을 작게 하기 위해, 
 i + j 가 양수면 j 감소
 i + j 가 음수면 i 증가
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N;
int A[100001];
vector<pair<int, int>> Abs;
//int Abs[100001][2];

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        Abs.push_back(make_pair(abs(A[i]), i));
    }
}

void solve2() {
    int i=0, j=N-1, minsum = 1000000, sum, minans, maxans;
    while(i<j) {
        sum = A[i] + A[j];
        if(minsum > abs(sum)) {
            minsum = abs(sum);
            minans = i;
            maxans = j;
        }
        if(sum > 0) j--;
        else if(sum < 0) i++;
        else break;
    }
    cout << minans << ' ' << maxans << '\n';
}

void solve1() {
    int sum = 0, minv = 10000000, finali = 0, finalj = 0;
    sort(Abs.begin(), Abs.end());
    
    for(int i=0; i<N-1; i++) {
        sum = abs(Abs[i].first - Abs[i+1].first);
        if(minv >= sum) {
            minv = sum;
            int prev = finali + finalj;
            if(Abs[i].second < finali || Abs[i+1].second < finalj || (finali==0 && finalj==0)) {
                finali = Abs[i].second; finalj = Abs[i+1].second;
            }
        }
    }

    if(finali > finalj) {
        cout << finalj  << ' ' << finali << '\n';
    } else {
        cout << finali << ' ' << finalj << '\n';
    }
    


}

int main() {
    input();
    solve2();
    return 0;
}