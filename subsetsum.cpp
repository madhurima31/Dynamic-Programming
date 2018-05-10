#include<bits/stdc++.h>
using namespace std;

bool issubset(int arr[],int sum,int n)
{
    bool setpart[n+1][sum+1];

    //if sum=0, true
    for(int i=0;i<=n;i++)
        setpart[i][0]=true;

    //if sum not zero and set is empty
    for(int j=1;j<=sum;j++)
        setpart[0][j]=false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
        if(j<arr[i-1])
            setpart[i][j]=setpart[i-1][j];

        if(j>=arr[i-1])
            setpart[i][j]=setpart[i-1][j] || setpart[i-1][j-arr[i-1]];
        }
    }
        return setpart[n][sum];
}

int main()
{
    int sum=7;
    int arr[]={1,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(issubset(arr,sum,n)){
        cout<<"found subset with given sum ";
    }
    else{
        cout<<"did not find subset with given sum ";
    }
}
