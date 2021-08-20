/*
 M 명 중 N 명./ 1~3등
 이름없으면 무효.

  내 방식 : 타임아웃.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
typedef struct  {
    int sabun;
    string name;
    int score;
} Person;
Person ph[10001];
Person ps[100001];

bool comp(Person& p1, Person& p2) {
    if(p1.score == p2.score) {
        return p1.sabun < p2.sabun;
    } else {
        return p1.score > p2.score;
    }
}
bool foundHubo(string name) {
    for(int i=0; i<N; i++) {
        if(name.compare(ph[i].name) == 0) {
            return true;
        };
    }
    return false;
}
int foundChamga(string name, int cur) {
    for(int i=0; i < cur; i++) {
        if(name.compare(ps[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        ph[i].sabun = i;
        cin >> ph[i].name;
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        string name;
        int score;
        cin >> name >> score;
        int found = foundChamga(name, i);
        if(found >=0) {
            //cout << "Debug " << name << " found : " << found << "fscore : " << ps[found].score << " score : " << score << '\n';
            ps[found].score += score;
        } else {
            ps[i].name = name; 
            ps[i].score = score;
        }
        //cout  << "[" << i <<  "] Debug " << ps[found].name << " score : " << ps[found].score << '\n';
    }
}

void solve() {
    sort(ps, ps+M, comp);
    
    int cnt = 0;
    for(int i=0; i<M; i++) {
        if(foundHubo(ps[i].name)) {
            cnt++;
            cout << ps[i].name << ' ' << ps[i].score << '\n';
            if(cnt==3) break;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}
