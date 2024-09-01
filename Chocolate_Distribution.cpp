#include<bits/stdc++.h>

using namespace std;

long long MinDiff(long long n, vector<long long> vec, long long m)
{
    sort(vec.begin(), vec.end());
    long long i=0;
    long long j=m-1;
    
    int mini = 1e9;
    while(j < n)
    {
        int diff = vec[j]-vec[i];
        mini = min(mini,diff);
        i++;
        j++;
    }
    
    return mini;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    long long n;
    
    while(cin>> n)
    {
        vector<long long> vec(n);
        for(int i=0; i<n; i++)
        {
            cin>>vec[i];
        }
        
        long long m;
        cin>>m;
        
        cout<<MinDiff(n, vec, m)<<endl;
    }
    return 0;
}