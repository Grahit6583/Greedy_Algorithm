#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int s,n,m;

    while (cin>>s>>n>>m)
    {
        int sunday = s/7;
        int buyingdays = s-sunday;
        int ans = 0;
        int totalfood = s*m;
        int foodonsunday = (6*n)-(6*m);

        if(foodonsunday < m && sunday > 0)
        {
            cout<<"-1"<<endl;
            continue;
        }

        if(totalfood % n == 0)
        {
            ans = totalfood/n;
        }
        else
        {
            ans = totalfood/n + 1;
        }

        if(ans <= buyingdays)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    
}