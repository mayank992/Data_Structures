#include<bits/stdc++.h>
using namespace std;

#define ll       long long int
#define ull      unsigned long long int
#define pb       push_back
#define vpop     pop_back
#define mp       make_pair
#define ff       first
#define ss       second
#define clz(x)   __builtin_clz(x)       //count leading zeroes
#define ctz(x)   __builtin_ctz(x)       //count trailing zeroes
#define sbts(x)  __builtin_popcount(x) //count set bits
#define ps(x, y) fixed << setprecision(y) << x
#define all(v)   v.begin(), v.end()
const int MOD  =  1e9 + 7;
const ll INF   =  1e12;

class twoDimBIT {
    public:
        ll Table[100][100], N, M;
    twoDimBIT(int n, int m): N(n + 1), M(m + 1) {
        memset(Table, 0, sizeof(Table));
    }

    ll getSum(int X, int Y) { // Time complexity: O(log(N) + log(M)) => O(log(N*M))
        ll sum = 0;
        for(int x = X; x > 0; x -= (x & -x)) {
            for(int y = Y; y > 0; y -= (y & -y)) {
                sum += Table[x][y];
            }
        }
        return sum;
    }

    void update(int X, int Y, ll value) { // Time  complexity: O(log(N*M))
        for(int x = X ; x < N; x += (x & -x)) {
            for(int y = Y; y < M; y += (y & -y)) {
                Table[x][y] += value;
            }
        }
    }

    void constructBIT(int mat[100][100]) {    // Time Complexity: O(log(N*M)) * O(N*M) => O((N*M)*log(N*M))
        for(int x = 1; x <= N; x++) {
            for(int y = 1; y <= M; y++) {
                update(x, y, mat[x-1][y-1]);
            }
        }
    }

    ll query(int x1, int y1, int x2, int y2) {  // Time Complexity: O(Q * log(N * M))
        return getSum(x2, y2) - getSum(x2, y1 - 1) - getSum(x1 - 1, y2) + getSum(x1 - 1, y1 - 1);
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m, mat[100][100];
    cin >> n >> m;
    twoDimBIT BIT(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< m; j++) {
            cin >> mat[i][j];
        }
    }
    BIT.constructBIT(mat);
    int Q, x1, x2, y1, y2;
    cin >> Q;
    while(Q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << BIT.query(x1, y1, x2, y2) << "\n";
    }
    return 0;
}
// Time Complexity: O((N*M+Q).log(N*M))


