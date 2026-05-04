#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arrayCost(vector<int>arr, int n, int k){
    int count=0;
    vector<int>brr(n);
    int rem = arr[0]%k;
    for(int i=1; i<n; i++){
       if(arr[i]%k != rem){
           return -1;
       }
    }
    for(int i=0; i<n; i++){
        brr[i] = arr[i]/k;
    }
    sort(brr.begin(),brr.end());
    int median = brr[n/2];
    for(int i=0; i<n; i++){
        count += abs(brr[i]-median);
    }
    return count;
}
int main(){
     int n;
     cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<< arrayCost(arr,n,k);
    return 0;
}