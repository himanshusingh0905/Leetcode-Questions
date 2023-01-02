//  TDKPRIME - Finding the Kth Prime
#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll;
#define mod 1000000007

// k [1,1e6]
const int N = 86028122;
bool sieve[N];

void makeSieve()
{
    for(int i = 2;i<=N;i++){
        sieve[i] = true;
    }
    for(int i=2; i*i<=N ;i++){
        if(sieve[i]){
            for(int j = i*i; j<=N; j+=i)
            {
                sieve[j] = false;
            }
        }
    }

}

int main()
{
    fastIO;
    makeSieve();

    vector<int> primes;
    for(int i = 2;i<=N;i++)
    {
        if(sieve[i])
            primes.push_back(i);
    }

    int q;
    cin>>q;

    while(q--)
    {
        int k;
        cin>>k;
        cout<<primes[k-1]<<endl;
    }

    return 0;
}