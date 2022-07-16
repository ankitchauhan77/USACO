#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define fi(i,a,b) for(int i=a;i<b;i++)
#define srt(v) sort(v.begin(),v.end())
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define int long long
ll md = 1000000007;
int inf = 1e18;
#define X first
#define Y second
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b) {T c = 1, m = a;while(b) {if (b & 1) c=(c*m); m=(m*m); b/=2;} return c;}
template <typename T>
T ceel(T a, T b){if (a%b==0) return a/b; else return a/b + 1;}
template <typename T>
T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}
ll pwmd(ll a, ll b) {ll c = 1, m = a%md;while(b) {if (b & 1) c=(c*m)%md; m=(m*m)%md; b/=2;} return c;}
ll modinv(ll n){return pwmd(n, md - 2);}
//--------------------------------theartofwar-------------------------------------------//
signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t, a;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v;
        int s = 0, mn = inf;
        fi(i, 0, n) {
            cin >> a, v.pb(a);
            s += a;
            mn = min(mn, a);
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        if (n == 2) {
            if (v[0] == v[1]) cout << "0\n";
            else cout << "-1\n";
            continue;
        }
        bool flag = true;
        int ex = 0;
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1) {
                if (v[i] - ex < 0) flag = false;
                mn = min(mn, v[i] - ex);
                break;
            }
            if (v[i] - ex > v[i + 1] || v[i] < ex) {
                flag = false;
                break;
            }
            mn = min(mn, v[i] - ex);
            ex = v[i + 1] - (v[i] - ex);
        }
        if (!flag) cout << "-1\n";
        else cout << (s - mn * n) << "\n";
    }
}