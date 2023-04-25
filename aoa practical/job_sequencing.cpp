#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b){
    return (a.profit > b.profit);
}

pair<int, int> jobSequencing(Job arr[], int n){
    sort(arr,arr+n,comparison);
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i].dead);
    }

    int slot[maxi+1];
    for(int i = 0; i <= maxi; i++){
        slot[i] = -1;
    }

    int countJobs = 0, jobProfit = 0;

    for(int i = 0; i < n; i++){
        for(int j = arr[i].dead; j >= 0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return make_pair(countJobs, jobProfit);
}


int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    Job arr[n];

    for(int i = 0; i < n; i++){
       cout << "Enter the deadline and profit for job " << i+1 << ": ";
       cin >> arr[i].dead >> arr[i].profit;
       arr[i].id = i+1;
    }

    pair<int, int> ans = jobSequencing(arr, n);
    cout << ans.first << " "<<ans.second;

    return 0;
}