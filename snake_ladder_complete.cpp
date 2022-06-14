#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define lld long long double
#define fi first
#define se second
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
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

vector<vll>adj(1e5);
vll level(1e5);
vll vis(1e5);

void bfs(ll x){
	
	
	level[x] = 0;
	queue<ll> q;
	// ll vis[n];
	// for(ll i=0; i<n; i++){
		// vis[i] = 0;
	// }
	
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
	
	ll n,m;
	cin>>n>>m;
	
	vector<vector<ll>>ladder(n+1, vector<ll>(3));
	for(ll i=1; i<n+1; i++){
		for(ll j=1; j<3; j++){
			cin>>ladder[i][j];
		}
	}

	vector<vector<ll>>snake(m+1, vector<ll>(3));
	for(ll i=1; i<m+1; i++){
		for(ll j=1; j<3; j++){
			cin>>snake[i][j];
		}
	}
	
	vll board(101);
	
	for(ll i=1; i<n+1; i++){
		ll s = ladder[i][1];
		ll e = ladder[i][2];
		board[s] = e -s;
	}
	
	for(ll i=1; i<m+1; i++){
		ll s = snake[i][1];
		ll e = snake[i][2];
		board[s] = e-s;
	}
	
	for(ll i=1; i<101; i++){
		for(ll dice = 1; dice <= 6; dice++){
			ll u = i;
			ll v = u + dice;
			v+=board[u+dice];
			if(v<101){
				adj[u].pb(v);
				// cout<<u<<" => "<<v<<en;
			}	
		}
	}
	
	bfs(1);
	
	cout<<level[100];
	
	
	
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
// 3 7
// 32 62 
// 42 68
// 12 98
// 95 13
// 97 25
// 93 37
// 79 27 
// 75 19 
// 49 47
// 67 17
// 
// 1 => 2
// 1 => 3
// 1 => 4
// 1 => 5
// 1 => 6
// 1 => 7
// 2 => 3
// 2 => 4
// 2 => 5
// 2 => 6
// 2 => 7
// 2 => 8
// 3 => 4
// 3 => 5
// 3 => 6
// 3 => 7
// 3 => 8
// 3 => 9
// 4 => 5
// 4 => 6
// 4 => 7
// 4 => 8
// 4 => 9
// 4 => 10
// 5 => 6
// 5 => 7
// 5 => 8
// 5 => 9
// 5 => 10
// 5 => 11
// 6 => 7
// 6 => 8
// 6 => 9
// 6 => 10
// 6 => 11
// 6 => 98
// 7 => 8
// 7 => 9
// 7 => 10
// 7 => 11
// 7 => 98
// 7 => 13
// 8 => 9
// 8 => 10
// 8 => 11
// 8 => 98
// 8 => 13
// 8 => 14
// 9 => 10
// 9 => 11
// 9 => 98
// 9 => 13
// 9 => 14
// 9 => 15
// 10 => 11
// 10 => 98
// 10 => 13
// 10 => 14
// 10 => 15
// 10 => 16
// 11 => 98
// 11 => 13
// 11 => 14
// 11 => 15
// 11 => 16
// 11 => 17
// 12 => 13
// 12 => 14
// 12 => 15
// 12 => 16
// 12 => 17
// 12 => 18
// 13 => 14
// 13 => 15
// 13 => 16
// 13 => 17
// 13 => 18
// 13 => 19
// 14 => 15
// 14 => 16
// 14 => 17
// 14 => 18
// 14 => 19
// 14 => 20
// 15 => 16
// 15 => 17
// 15 => 18
// 15 => 19
// 15 => 20
// 15 => 21
// 16 => 17
// 16 => 18
// 16 => 19
// 16 => 20
// 16 => 21
// 16 => 22
// 17 => 18
// 17 => 19
// 17 => 20
// 17 => 21
// 17 => 22
// 17 => 23
// 18 => 19
// 18 => 20
// 18 => 21
// 18 => 22
// 18 => 23
// 18 => 24
// 19 => 20
// 19 => 21
// 19 => 22
// 19 => 23
// 19 => 24
// 19 => 25
// 20 => 21
// 20 => 22
// 20 => 23
// 20 => 24
// 20 => 25
// 20 => 26
// 21 => 22
// 21 => 23
// 21 => 24
// 21 => 25
// 21 => 26
// 21 => 27
// 22 => 23
// 22 => 24
// 22 => 25
// 22 => 26
// 22 => 27
// 22 => 28
// 23 => 24
// 23 => 25
// 23 => 26
// 23 => 27
// 23 => 28
// 23 => 29
// 24 => 25
// 24 => 26
// 24 => 27
// 24 => 28
// 24 => 29
// 24 => 30
// 25 => 26
// 25 => 27
// 25 => 28
// 25 => 29
// 25 => 30
// 25 => 31
// 26 => 27
// 26 => 28
// 26 => 29
// 26 => 30
// 26 => 31
// 26 => 62
// 27 => 28
// 27 => 29
// 27 => 30
// 27 => 31
// 27 => 62
// 27 => 33
// 28 => 29
// 28 => 30
// 28 => 31
// 28 => 62
// 28 => 33
// 28 => 34
// 29 => 30
// 29 => 31
// 29 => 62
// 29 => 33
// 29 => 34
// 29 => 35
// 30 => 31
// 30 => 62
// 30 => 33
// 30 => 34
// 30 => 35
// 30 => 36
// 31 => 62
// 31 => 33
// 31 => 34
// 31 => 35
// 31 => 36
// 31 => 37
// 32 => 33
// 32 => 34
// 32 => 35
// 32 => 36
// 32 => 37
// 32 => 38
// 33 => 34
// 33 => 35
// 33 => 36
// 33 => 37
// 33 => 38
// 33 => 39
// 34 => 35
// 34 => 36
// 34 => 37
// 34 => 38
// 34 => 39
// 34 => 40
// 35 => 36
// 35 => 37
// 35 => 38
// 35 => 39
// 35 => 40
// 35 => 41
// 36 => 37
// 36 => 38
// 36 => 39
// 36 => 40
// 36 => 41
// 36 => 68
// 37 => 38
// 37 => 39
// 37 => 40
// 37 => 41
// 37 => 68
// 37 => 43
// 38 => 39
// 38 => 40
// 38 => 41
// 38 => 68
// 38 => 43
// 38 => 44
// 39 => 40
// 39 => 41
// 39 => 68
// 39 => 43
// 39 => 44
// 39 => 45
// 40 => 41
// 40 => 68
// 40 => 43
// 40 => 44
// 40 => 45
// 40 => 46
// 41 => 68
// 41 => 43
// 41 => 44
// 41 => 45
// 41 => 46
// 41 => 47
// 42 => 43
// 42 => 44
// 42 => 45
// 42 => 46
// 42 => 47
// 42 => 48
// 43 => 44
// 43 => 45
// 43 => 46
// 43 => 47
// 43 => 48
// 43 => 47
// 44 => 45
// 44 => 46
// 44 => 47
// 44 => 48
// 44 => 47
// 44 => 50
// 45 => 46
// 45 => 47
// 45 => 48
// 45 => 47
// 45 => 50
// 45 => 51
// 46 => 47
// 46 => 48
// 46 => 47
// 46 => 50
// 46 => 51
// 46 => 52
// 47 => 48
// 47 => 47
// 47 => 50
// 47 => 51
// 47 => 52
// 47 => 53
// 48 => 47
// 48 => 50
// 48 => 51
// 48 => 52
// 48 => 53
// 48 => 54
// 49 => 50
// 49 => 51
// 49 => 52
// 49 => 53
// 49 => 54
// 49 => 55
// 50 => 51
// 50 => 52
// 50 => 53
// 50 => 54
// 50 => 55
// 50 => 56
// 51 => 52
// 51 => 53
// 51 => 54
// 51 => 55
// 51 => 56
// 51 => 57
// 52 => 53
// 52 => 54
// 52 => 55
// 52 => 56
// 52 => 57
// 52 => 58
// 53 => 54
// 53 => 55
// 53 => 56
// 53 => 57
// 53 => 58
// 53 => 59
// 54 => 55
// 54 => 56
// 54 => 57
// 54 => 58
// 54 => 59
// 54 => 60
// 55 => 56
// 55 => 57
// 55 => 58
// 55 => 59
// 55 => 60
// 55 => 61
// 56 => 57
// 56 => 58
// 56 => 59
// 56 => 60
// 56 => 61
// 56 => 62
// 57 => 58
// 57 => 59
// 57 => 60
// 57 => 61
// 57 => 62
// 57 => 63
// 58 => 59
// 58 => 60
// 58 => 61
// 58 => 62
// 58 => 63
// 58 => 64
// 59 => 60
// 59 => 61
// 59 => 62
// 59 => 63
// 59 => 64
// 59 => 65
// 60 => 61
// 60 => 62
// 60 => 63
// 60 => 64
// 60 => 65
// 60 => 66
// 61 => 62
// 61 => 63
// 61 => 64
// 61 => 65
// 61 => 66
// 61 => 17
// 62 => 63
// 62 => 64
// 62 => 65
// 62 => 66
// 62 => 17
// 62 => 68
// 63 => 64
// 63 => 65
// 63 => 66
// 63 => 17
// 63 => 68
// 63 => 69
// 64 => 65
// 64 => 66
// 64 => 17
// 64 => 68
// 64 => 69
// 64 => 70
// 65 => 66
// 65 => 17
// 65 => 68
// 65 => 69
// 65 => 70
// 65 => 71
// 66 => 17
// 66 => 68
// 66 => 69
// 66 => 70
// 66 => 71
// 66 => 72
// 67 => 68
// 85 => 91
// 88 => 91
// 88 => 92
// 88 => 37
// 88 => 94
// 89 => 90
// 89 => 91
// 89 => 92
// 89 => 37
// 89 => 94
// 89 => 13
// 90 => 91
// 90 => 92
// 90 => 37
// 90 => 94
// 90 => 13
// 90 => 96
// 91 => 92
// 91 => 37
// 91 => 94
// 91 => 13
// 91 => 96
// 91 => 25
// 92 => 37
// 92 => 94
// 92 => 13
// 92 => 96
// 92 => 25
// 92 => 98
// 93 => 94
// 93 => 13
// 93 => 96
// 93 => 25
// 93 => 98
// 93 => 99
// 94 => 13
// 94 => 96
// 94 => 25
// 94 => 98
// 94 => 99
// 94 => 100
// 95 => 96
// 95 => 25
// 95 => 98
// 95 => 99
// 95 => 100
// 96 => 25
// 96 => 98
// 96 => 99
// 96 => 100
// 97 => 98
// 97 => 99
// 97 => 100
// 98 => 99
// 98 => 100
// 99 => 100
// 67 => 69
// 67 => 70
// 67 => 71
// 67 => 72
// 67 => 73
// 68 => 69
// 68 => 70
// 68 => 71
// 68 => 72
// 68 => 73
// 68 => 74
// 69 => 70
// 69 => 71
// 69 => 72
// 69 => 73
// 69 => 74
// 69 => 19
// 70 => 71
// 70 => 72
// 70 => 73
// 70 => 74
// 70 => 19
// 70 => 76
// 71 => 72
// 71 => 73
// 71 => 74
// 71 => 19
// 71 => 76
// 71 => 77
// 72 => 73
// 72 => 74
// 72 => 19
// 72 => 76
// 72 => 77
// 72 => 78
// 73 => 74
// 73 => 19
// 73 => 76
// 73 => 77
// 73 => 78
// 73 => 27
// 74 => 19
// 74 => 76
// 74 => 77
// 74 => 78
// 74 => 27
// 74 => 80
// 75 => 76
// 75 => 77
// 75 => 78
// 75 => 27
// 75 => 80
// 75 => 81
// 76 => 77
// 76 => 78
// 76 => 27
// 76 => 80
// 76 => 81
// 76 => 82
// 77 => 78
// 77 => 27
// 77 => 80
// 77 => 81
// 77 => 82
// 77 => 83
// 78 => 27
// 78 => 80
// 78 => 81
// 78 => 82
// 78 => 83
// 78 => 84
// 79 => 80
// 79 => 81
// 79 => 82
// 79 => 83
// 79 => 84
// 79 => 85
// 80 => 81
// 80 => 82
// 80 => 83
// 80 => 84
// 80 => 85
// 80 => 86
// 81 => 82
// 81 => 83
// 81 => 84
// 81 => 85
// 81 => 86
// 81 => 87
// 82 => 83
// 82 => 84
// 82 => 85
// 82 => 86
// 82 => 87
// 82 => 88
// 83 => 84
// 83 => 85
// 83 => 86
// 83 => 87
// 83 => 88
// 83 => 89
// 84 => 85
// 84 => 86
// 84 => 87
// 84 => 88
// 84 => 89
// 84 => 90
// 85 => 86
// 85 => 87
// 85 => 88
// 85 => 89
// 85 => 90
// 86 => 87
// 86 => 88
// 86 => 89
// 86 => 90
// 86 => 91
// 86 => 92
// 87 => 88
// 87 => 89
// 87 => 90
// 87 => 91
// 87 => 92
// 87 => 37
// 88 => 89
// 88 => 90

