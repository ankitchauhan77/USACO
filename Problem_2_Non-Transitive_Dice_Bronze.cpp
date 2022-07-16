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
int go(vi v1, vi v2) {
    int score1 = 0, score2 = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) score1 += (v2[j] < v1[i]), score2 += (v1[j] < v2[i]);
    }
    if (score1 == score2) return 2;
    if (score1 > score2) return 0;
    return 1;
}
signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t, a;
    cin >> t;
    while (t--) {
        vi A, B;
        fi(i, 0, 4) cin >> a, A.pb(a);
        fi(i, 0, 4) cin >> a, B.pb(a);
        srt(A), srt(B);
        int ans = go(A, B);
        if (ans == 2) {
            cout << "no\n";
            continue;
        }
        bool flag = false;
        fi(n1, 1, 11) {
            fi(n2, n1, 11) {
                fi(n3, n2, 11) {
                    fi(n4, n3, 11) {
                        vi C = {n1, n2, n3, n4};
                        int x1 = go(C, A), x2 = go(C, B);
                        if (x1 == 2 || x2 == 2) continue;
                        if (x1 != x2 && x1 == ans) flag = true;
                    }
                }
            }
        }
        if (flag) cout << "yes\n";
        else cout << "no\n";
    }
}