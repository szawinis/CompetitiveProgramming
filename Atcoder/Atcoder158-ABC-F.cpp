/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <bits/stdc++.h>
using namespace std;

/* TYPES */
#define long int64_t
#define all(v) v.begin(), v.end()
#define fs first
#define sc second
typedef pair<int,int> pii;
typedef pair<int64_t,int> pli;
typedef pair<int64_t,int64_t> pll;
typedef vector<int> vi;
typedef vector<int64_t> vl; typedef vector<pair<int, int> > vpi;
typedef vector<pair<int64_t, int64_t> > vpl;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int64_t> > vvl;

/* CONSTANTS */
const long P1 = 31, P2 = 37, MOD1 = 1e9+7, MOD2 = 998244353, LINF = 1e18 + 1e16;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

/* FUNCTIONS */
template<typename T, typename U> inline void setMin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void setMax(T &x, U y) { if(x < y) x = y; }
template<typename T>
inline T gcd(T a, T b) {
    T c;
    while(b) c = b, b = a % b, a = c;
    return a;
}
template<typename T>
inline T square(T a) { return a*a; }
inline long modPow(long b, long e, long mod) {
    if (e == 0) return 1ll;
    if (e == 1) return b;
    return modPow(b * b % mod, e >> 1, mod) * modPow(b, e & 1, mod) % mod;
}

struct Fenwick {

    vector<int> f;

    void update(int i, int v) {
        ++i;
        while(i < f.size()) {
            setMax(f[i], v);
            i += i & -i;
        }
    }

    int query(int i) {
        ++i;
        int ret = 0;
        while(i > 0) {
            setMax(ret, f[i]);
            i -= i & -i;
        }
        return ret;
    }

    Fenwick(int n) {
        f = vector<int>(n + 1);
    }

};


class TaskF {
private:

    int n;
    vector<pair<int,int> > robots;
    Fenwick *f;

    int get_immediate_successor(int i) {
        int l = i, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(robots[i].fs + robots[i].sc > robots[mid].fs) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l + 1; // l is the highest index such that robot i still reaches it
    }

    vector<int> find_endpoints() {
        f = new Fenwick(n);
        vector<int> ret(n);
        for(int i = 0; i < n; i++) {
            f->update(i, i);
        }
        for(int i = n-1; i >= 0; i--) {
            int exclusive_upper = get_immediate_successor(i);
            assert(exclusive_upper >= i);

            int res = f->query(exclusive_upper - 1); // we want inclusive here
            f->update(i, res);
            ret[i] = res;
        }
        return ret;
    }

    int calc_dp(vector<int> endpoints) {
        vector<int> dp(n + 1);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + dp[endpoints[i] + 1];
            dp[i] %= MOD2;
        }
        return dp[0];
    }

public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 0, x, d; i < n; i++) {
            cin >> x >> d;
            robots.emplace_back(x, d);
        }
        sort(all(robots));
        cout << calc_dp(find_endpoints()) << endl;
    }
};


class Solver {
public:
    void solve(std::istream& in, std::ostream& out) {
        TaskF *obj = new TaskF();
        obj->solve(in, out);
        delete obj;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solver solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}