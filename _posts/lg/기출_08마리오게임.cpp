/*
버섯 개수    1 <= N <= 150000
버섯 숫자  1 <= P <= 500

(1) 버섯 먹는 경우
(2) 먹지 않는 경우

(A) 홀수 버섯  P 만큼 키 커짐
(B) 짝수 버섯  P 만큼 키 작아짐

0번은 무조건 먹음, 0번을 홀수로 먹었으므로 그 다음은 짝수가 됨.

버섯개수가 15만개라 dfs, bfs로 풀수 없을것임.. DP로 사고전환
현재 인덱스의 값이 이전 인덱스보다 클 때만    합 = 합 - 이전값 + 현재값  으로 연산하자.
*/

#include <iostream>
#include <stack>

using namespace std;

int N;
int P[150001];
int maxp = 0;
int sum = 0;

void dfs(int order, int index) {

    stack<int> s;
    //s.push(p);

    if(order == 0 || order%2 !=0) { //홀
        sum += P[index];
    } else {
        sum -= P[index];
    }

    if(maxp < sum) maxp = sum;

    dfs(order+1, index+1);
    dfs(order+1, index+2);
    
}

void dp() {
    sum += P[0];
    for(int i=1; i<N; i++) {
        if(P[i-1] < P[i]) {
            sum  = sum - P[i-1] + P[i];
        }
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> P[i];
    }
    dp();
    cout << sum << '\n';
    return 0;
}