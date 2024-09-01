#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int Meetings(int n, int a[], int b[])
{
    vector<pair<int,int>> v;

    for(int i=0; i<n; i++)
    {
        pair<int,int> p = make_pair(a[i],b[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(),  [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int cnt = 1;
    int ansEnd = v[0].second;

    for(int i=1; i<n; i++)
    {
        if(v[i].first > ansEnd)
        {
            cnt++;
            ansEnd = v[i].second;
        }
    }

    return cnt;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t)
    {
        int n;
        cin>>n;
        int a[n], b[n];
        
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }

        cout<<Meetings(n, a, b)<<endl;
        t--;
    }
    
    return 0;
}