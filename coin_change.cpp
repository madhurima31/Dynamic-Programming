#include<bits/stdc++.h>
using namespace std;

// n= total sum . m in array of coins

int countChange(int S[],int m, int n){

    int table[n+1];
    memset(table,0,sizeof(table));
    table[0]=1;

    for(int i=0;i<m;i++){
        for(int j=S[i];j<=n;j++){
            table[j]+=table[j-S[i]];
        }
    }
    return table[n];
}

int main()
{
    int n,m;
    cout<<"enter size of array";
    cin>>m;
    int S[m];
    cout<<"enter total money";
    cin>>n;
    for(int i = 0 ;i<m;i++){
       cin>>S[i];
    }

    //m=sizeof(S)/sizeof(S[0]);
    cout<<"number of ways sum can be obtained with coin change ="<<countChange(S,m,n);
    return 0;

}
