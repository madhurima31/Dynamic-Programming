#include<bits/stdc++.h>
using namespace std;

bool issubset(int arr[],int sum,int n)
{

    if(sum%2!=0 )
        return false;
    bool setpart[n+1][(sum/2)+1];

    //if sum=0, true
    for(int i=0;i<=n;i++)
        setpart[i][0]=true;
    for(int j=1;j<=sum/2;j++)
        setpart[0][j]=false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum/2;j++){
        if(j<arr[i-1])
            setpart[i][j]=setpart[i-1][j];

        if(j>=arr[i-1])
            setpart[i][j]=setpart[i-1][j] || setpart[i-1][j-arr[i-1]];


        }
    }
        return setpart[n][sum/2];

}



int main()
{
    int sum=0;
    int arr[]={3,1,1,2,2,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if(issubset(arr,sum,n)){
        cout<<"yes can be divided into subsets of equal sum ";
    }
    else{
        cout<<"cannot be divided into subsets of equal sum";
    }
}
