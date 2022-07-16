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
int go(vi v) {
    int n = v.size(), ans = 0;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && v[s.top()] < v[i]) s.pop();
        if (!s.empty()) ans += (s.top() - i + 1);
        s.push(i);
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, a;
    cin >> n;
    vi v;
    fi(i, 0, n) cin >> a, v.pb(a);
    int ans = go(v);
    reverse(all(v));
    ans += go(v);
    cout << ans;
}