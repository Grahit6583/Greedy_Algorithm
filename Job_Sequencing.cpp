#include<bits/stdc++.h>

using namespace std;

class Job
{
    public:
        int id;
        int profit;
        int dead;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> sequencing(int n, Job arr[])
{
    sort(arr, arr+n, cmp);

    int maxDeadline = INT_MIN;

    for(int i=0; i<n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> schedule(maxDeadline+1, -1);

    int count = 0;
    int maxprofit = 0;

    for(int i=0; i<n; i++)
    {
        int currid = arr[i].id;
        int currdead = arr[i].dead;
        int currprofit = arr[i].profit;

        for(int k=currdead; k>0; k--)
        {
            if(schedule[k] == -1)
            {
                count++;
                maxprofit += currprofit;
                schedule[k] = currdead;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxprofit);

    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t)
    {
        int n;
        cin>>n;

        Job arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].id>>arr[i].dead>>arr[i].profit;
        }

        vector<int> ans = sequencing(n, arr);
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        t--;
    }

    return 0;
}