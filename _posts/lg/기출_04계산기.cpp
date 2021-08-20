// 5 <= N <= 100,   2 <= B <= 36

#include <iostream>

using namespace std;

int BSD[101];
int SD[101];

int c2d_func(char c) {
    if(c <= '9')  return c - '0';
    else return c - 'A' + 10;
}
char d2c_func(int i) {
    if(i <= 9) return (char)('0'+i);
    else return (char)('A'+i-10);
}
int c2d[128];
char d2c[] = "0123456789ABCDEFGHIJKLKMOPQRSTUVWXYZ";
void makeC2D() {
    int i,j;
    for(i=0, j=0; i <='9'; i++, j++) {
        c2d[i] = j;
    }
    for(i='A'; i <='Z'; i++, j++) {
        c2d[i] = j;
    }

}
int main() {
    int src = 123, srclen = 0;
    int dst = 45, dstlen = 0;
    double dsrc = 0.0000000001 * src;
    double ddst = 0.0000000001 * src;
    int asrc[100];
    int adst[100];
    int ans[100];
    while(src > 0) {
        asrc[srclen++] = src%10;
        src /= 10;
    }
    while(dst > 0) {
        adst[dstlen++] = dst%10;
        dst /= 10;
    }
    int upper = 0;
    for(int i=0; i< dstlen; i++) {  //45
        for(int j=0; j< srclen; j++) { //123
            int tmp =  asrc[j] * adst[i]; // ->   3 * 5
            //ans[??] = tmp%10 // -> 5
            upper = tmp - (tmp%10);
        }
    }
    double a = 0.999999;
    double b = 0.999999;
    double c = (double)a * (double)b;
    double d = 0.8 * 0.7;

    cout.precision(15);

    cout << a << ' ' << b << ' ' <<  c << ' ' << d << '\n';

    long long la = 9999999999;
    long long lb = 9999999999;
    long long lc = la * lb;
    cout << la << ' ' << lb << ' ' <<  lc  << '\n';

    return 0;
}
/*
int main()
{
    int N = -1;
    //cin >> N;
    for(int i=0; i<N; i++) {
        int B,S,D;
        cin >> B >> S >> D;
    }
    int B,S,D;
    string SS, DD;
    cin >> B;
    if(B==16) {
        cin >> SS >> DD;
        int ss = stoi(SS, nullptr, 16);
        int dd = stoi(DD, nullptr, 16);
        BSD[0] = ss * dd;
        cout << std::hex << BSD[0] << '\n';
    } else {
        cin >> S >> D;
    }
    cout << S << '\n ';

    return 0;
}
*/