/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

/* INCLUDES */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <random>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

/* TYPES */
#define long int64_t
#define all(v) v.begin(), v.end()
typedef pair<int,int> pii;
typedef pair<int64_t,int> pli;
typedef pair<int64_t,int64_t> pll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vpi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int64_t> > vvl;

/* CONSTANTS */
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
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
inline T square(T a, T b) { return a*b; }

class TaskB {

    string s;
    vpi segs;
    long ans;

public:
    void solve(istream &cin, ostream &cout) {
        cin >> s;
        for(int i = 0, last = 0; i < s.length() - 1; i++) {
            if(s[i] == 'B' && s[i+1] == 'C') {
                segs.emplace_back(last, i - 1);
                last = i + 2;
            }
        }
        auto getAs = [&] (int l, int r) -> int {
            int ret = 0;
            for(int i = r; i >= l && s[i] == 'A'; i--) {
                ++ret;
            }
            return ret;
        };
        reverse(all(segs));
        long furthest = 1;
        for(pii seg: segs) {
            long As = getAs(seg.first, seg.second);
//            cerr << seg.first << ' ' << seg.second << ' ' << As << ' ' << furthest << endl;
            ans += As * furthest;
            if(As != seg.second - seg.first + 1) furthest = 1;
            else ++furthest;
        }
        cout << ans << endl;
    }
};

class Solver {
public:
    void solve(std::istream& in, std::ostream& out) {
        TaskB *obj = new TaskB();
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