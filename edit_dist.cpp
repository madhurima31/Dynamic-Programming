#include<bits/stdc++.h>
using namespace std;

int min(int x,int y, int z){

return min(min(x,y),z);
}

int edit_dist(string str1,string str2,int m , int n)
{
    int dis[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j==0)
                dis[i][j]=j;
            else if(i==0)
                dis[i][j]=i;
            else if(str1[i-1]==str2[j-1])
                dis[i][j]= dis[i-1][j-1];
            else
                dis[i][j]=1+min(dis[i-1][j-1],dis[i][j-1],dis[i-1][j]);
        }
    }
    return dis[m][n];
}

int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;
    cout<<edit_dist(str1,str2,str1.length(),str2.length());
}
