#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){

    int max_no = 0 ,i,j;
    int *lis;
    lis=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        lis[i]=1;
    }

    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }

    for(i=0;i<n;i++){
        if(max_no<lis[i]){
            max_no=lis[i];
        }
    }
return max_no;
}

int main()
{
    int arr[]= { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[1]);
    cout<< lis(arr,n);
    return 0;
}
