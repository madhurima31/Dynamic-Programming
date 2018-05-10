#include<bits/stdc++.h>
using namespace std;
int knap_sack(int W, int val[],int wt[],int n);
int main(){
    int W =50;
    int val[]= {60,100,120};
    int wt[]={10,20,30};
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knap_sack(W,val,wt,n);
    return 0;
}

int knap_sack(int W, int val[], int wt[], int n ){

int k[n+1][W+1];
int i , w;
int a,b;
for (i=0;i<=n;i++){
    for (w=0;w<=W;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if (wt[i-1]<=w){

                k[i][w]= max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w] );
            }
            else{
                k[i][w]=k[i-1][w];
            }
    }
}
return k[n][W];
}
