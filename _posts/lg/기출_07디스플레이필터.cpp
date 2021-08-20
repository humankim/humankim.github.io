// dfs 돌리면서 최소값을 갱신시켜라
// 
#include <iostream>
#include <stack>
#include <climits>

using namespace std;

int N;
int R[11];
int P[11];
long long mingap = LONG_MAX;
int mincnt = INT_MAX;

void go(int start, int mul, int sum, int cnt) {
    if(cnt > 0) {
        long long gap = abs(mul - sum);
        if(mingap > gap) {
            mingap = gap;
            mincnt = cnt;
        }
    }

    for(int i=start; i<N; i++) {
        go(i+1, mul * R[i], sum + P[i], cnt+1);
    }
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> R[i] >> P[i];
    }
    go(0, 1, 0, 0);
    
    cout << N-mincnt << '\n';
    return 0;
}