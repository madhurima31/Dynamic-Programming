//n eggs , k floors , find min number of attempts

#include<bits/stdc++.h>
using namespace std;

int eggdrop(int n , int k )
{
    int res;
    int eggfloor[n+1][k+1];

    //if 0  floors then 0 attempts , if 1 floor , 1 attempt(obviously)
    for(int j=1;j<=n;j++){
        eggfloor[j][0]=0;
        eggfloor[j][1]=1;
    }

    //if 1 egg and k floors, k trials need to verify in which floor egg breaks
    for(int i=1;i<=k;i++){
        eggfloor[1][i]=i;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
                eggfloor[i][j]=INT_MAX;
        for(int x=1;x<=j;x++){
            res= 1+ max(eggfloor[i-1][x-1],eggfloor[i][j-x]);
            if(res<eggfloor[i][j]){
                eggfloor[i][j]=res;
            }
        }
        }
    }

    return eggfloor[n][k];
}

int main(){
int n, k ;
cin>>n;
cin>>k;
cout<<eggdrop(n,k);
return 0;
}
