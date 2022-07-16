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
    // freopen("time.in", "r", stdin);
	// freopen("time.out", "w", stdout);
    vector<string> v1, v2;
    string s;
    fi(i, 0, 3) cin >> s, v1.pb(s);
    fi(i, 0, 3) cin >> s, v2.pb(s);
    vi have(26), req(26);
    int green = 0, yellow = 0;
    fi(i, 0, 3) {
        fi(j, 0, 3) {
            if (v1[i][j] == v2[i][j]) green++;
            else {
                have[v1[i][j] - 'A']++;
                req[v2[i][j] - 'A']++;
            }
        }
    }
    fi(i, 0, 26) yellow += min(req[i], have[i]);
    cout << green << "\n" << yellow;
}