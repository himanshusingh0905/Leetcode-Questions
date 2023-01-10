#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll;
#define mod 1000000007


vector<long long> nextGreater(vector<long long> arr)
{
    int size = arr.size();
    stack<long long> st;

    vector<long long> ans(size);
    //ans[size-1] = -1;
    st.push(arr[size-1]);  // initialilly
    ans[size-1] = -1;
    for(int i = size-2;i>=0;i--)
    {
        if(st.top()>arr[i])
        {   
            ans[i]=st.top();
            st.push(arr[i]);
            
        }
        else
        {
            while(!st.empty() && st.top()<=arr[i])
            {
               // cout<<"top = "<<st.top()<<endl;
                st.pop();
            }
            if(st.empty())
                {
                    ans[i]=-1;
                    st.push(arr[i]);
                }

            else{
             ans[i] = st.top();

            st.push(arr[i]);
             }
           
            
        }

    }
    return ans;
}

int main()
{
    fastIO;
    int n;cin>>n;
    vector<long long> arr(n);

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<ll> ans = nextGreater(arr);

    for(int ele: ans)
        cout<<ele<<endl;

    return 0;
}