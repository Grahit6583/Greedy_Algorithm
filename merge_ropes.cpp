#include<bits/stdc++.h>

using namespace std;

long long merge_ropes(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;
    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();

        long long sec = pq.top();
        pq.pop();

        long long sum = first + sec;
        cost += sum;

        pq.push(sum);
    }
    return cost;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long n;
    
    while(cin>>n)
    {
        long long arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        cout<<merge_ropes(arr, n);
    }
    return 0;
}