#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define lld long long double
#define fi first
#define se second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fl(i,a,b) for(ll i=a; i<b; i++)
#define fle(a,b) for(ll i=a; i<=b; i++)
#define pll pair<ll,ll>
#define vll vector<ll>
#define vld vector<ld>
#define vs vector<string>
#define vpll vector<pair<ll,ll>>
#define mll map<ll,ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define ceil(a,b) (a+b-1)/b
#define intake(a,n) ll n; cin>>n; vector<ll> a(n); for(ll i=0;i<n;i++) cin>>a[i]
#define intake2(a,n,k) ll n,k; cin>>n>>k; vector<ll> a(n); for(ll i=0;i<n;i++) cin>>a[i]
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pq priority_queue
#define loop(n) for(int i=0;i<n;i++)
#define out(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<"\n"
#define en "\n"
// #define sp <<" "
#define sorti(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.rbegin(),a.rend())
#define get_sum(a) accumulate(a.begin(),a.end(),0LL)
#define get_max(a) *max_element(a.begin(),a.end())
#define get_min(a) *min_element(a.begin(),a.end())
#define get_max_pos(v) max_element(v.begin(), v.end()) - v.begin()
#define unique(s) unique(s.begin(), s.end()) - s.begin() // retunrns the # of unique blocks elements
#define setbits(x) __builtin_popcountll(x)
#define ceil(a,b) (a+b-1)/b
const int mod = 1000000007;
const int dom = 998244353;
const ll inf = 2100000000;
const ld eps = 1e-6, pi = 3.14159265358979323846264338327950;
const long long INF = 4000000000000000000LL;
const ll MAX = 1e5+5;
bool even(ll n){
	return (!(n&1));
}

void precision(int a) {cout << setprecision(a) << fixed;}


ll pw(ll a, ll b, ll m){
	//O(log b)
	if(b==0){
		return a%m;
	}
	if(b%2==0){
		ll t = pw(a,b/2, m);
		return ((t*t)%m);
	}
	else{
		ll t = pw(a,(b-1)/2,m);
		return (a*t%m);
	}
}


ll binaryexp(ll a, ll b)
{
    ll ans = 0;
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else if (b % 2)
    {
        ans = (a * (binaryexp((a * a) % mod, b / 2) % mod)) % mod;
    }
    else
        ans = binaryexp((a * a) % mod, b / 2) % mod;
    return ans % mod;
}

// inverse of a number only if gcd(b,m) = 1 // O(log m)
ll inv(ll b, ll m){
	return pw(b,m-2,m);
}


// PRIME CHECK
bool prime(ll n){
	bool isPrime = true;
	fle(2,sqrt(n)){
		if(n%i==0){
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

// Converting decimal to binary string
string intToBinary(int n)
{
    string s = "";
    while (n > 0)
    {
        s =  ( (n % 2 ) == 0 ? "0" : "1") +s;
        n = n / 2;
    }
    return s;
}

// FINDING DIVISORS OF N
void divisors_of_n(ll n){
	vector<ll>divisors;
	fle(1,sqrt(n)){
		if(n%i == 0){
			divisors.push_back(i);
			if(i*i != n){
				divisors.push_back(n/i);
			}
		}
	}
	for(auto divisor : divisors){
		cout<<divisor<<" ";
	}
}

//PRIME FACTORIZATION
void prime_factors(ll n){
	vector<pair<int,int>> factorization;
	for(int i=2; i*i <= n; i++){
    	int count = 0;
    	while(n % i == 0){
        	count++;
        	n /= i;
    	}
    	if(count > 0){
        	factorization.push_back({i, count});
    	}
	}
	if(n != 1){
    	factorization.push_back({n, 1});
	}
	for(auto factor : factorization){
		cout<<factor.first<<" "<<factor.second<<'\n';
	}

}

// Sieve of Eratosthenes
void SOE(ll n){
	const ll lim = 1e7 + 10;
	vector<bool>isprime(lim, true);
	isprime[0] = isprime[1] = false;
	for(ll i=2; i*i<=n; i++){
		if(isprime[i]){
			for(ll j=i*i; j<=n; j+=i){
				isprime[j] = false;
			}
		}
		
	for(ll i=0; i<=n; i++){
		if(isprime[i]){
			cout<<i<<" ";
		}
	}
	} 	
}

//Smallest Prime Factor
void SPF(ll n){
	const ll lim = 1e7 + 10;
	vector<ll>spf(lim);
	for(ll i=0; i<lim; i++){
		spf[i]=i;
	}
	for(ll i=2; i*i<=n; i++){
		if(spf[i]==i){
			for(ll j=i*i; j<=n; j+=i){
				if(spf[j]==j){
					spf[j]=i;
				}
			}
		}
	} 
	cout<<spf[n];
}

ll nCr(ll n, ll r)
{
    if (n < r)
        return 0;
    if (r > n - r)
        r = n - r;
    ll ans = 1;
    ll i;
    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

ll nfac(ll n, ll mod){
	ll ans = 1;
	for(ll i=1; i<=n; i++){
		ans = (ans%mod * i%mod)%mod;
	}
	return ans;
}

ll IPOT(ll x){
	if(x&(x-1)){
		return 0;
	}
	return 1;
}

// x|(1<<k) : sets the kth bit
// x&~(1<<k): unsets the kth bit
// x^(1<<k) : inverts the kth bit

// IN BIT-MANIPULATION : THINK BITS ARE INDEPENDENT OF EACH OTHER. 
// FIRST THINK ALGO THEN IMPLEMENT 

//*****************solved below********************//
// DONT CODE RANDOMLY SOMETHING FOOLISH, YOU BITCH

// vector<vector<int>>arr(n,vector<int>(m));
//    fi(i,n)fi(j,m)cin>>arr[i][j];


ll n,m;
vector<vll> adj;
vll level;

void bfs(ll x){
	
	
	level[x] = 0;
	queue<ll> q;
	ll vis[n];
	for(ll i=0; i<n; i++){
		vis[i] = 0;
	}
	
	q.push(x);
	vis[x] = 1;
	
	while(!q.empty()){
		ll s = q.front();
		
		q.pop();
		
		for(ll i=0; i<adj[s].size(); i++){
			ll ch = adj[s][i];
			if(vis[ch] == 0){
				q.push(ch);
				vis[ch] = 1;
				level[ch] = level[s] + 1;
				
			}
		}
		
	}
	
}

void solve(){

	cin>>n>>m;
	adj.resize(n);
	level.resize(n);
	for(ll i=0; i<m; i++){
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bfs(0);
	
	// PRINTING LEVEL OF EACH NODE
	for(ll i=0; i<n; i++){
		cout<<i<<":"<<level[i]<<" "<<en;
	}
	
	// PRINT THE ADJENCENCY LIST
	// for(ll i=0; i<n; i++){
		// cout<<i<<":";
		// for(auto &x : adj[i]){
			// cout<<"-> "<<x;
		// }
		// cout<<en;
	// }
	
}
	
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll q;
    cin>>q;
	
	while(q--){
		solve();
		cout<<en;
	}
	return 0;
}


// 1
// 8 8
// 0 1
// 0 2
// 0 3
// 1 4 
// 1 5
// 2 6
// 2 7
// 3 7
// 