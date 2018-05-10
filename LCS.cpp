#include<bits/stdc++.h>
using namespace std;


int lcs(string x,string y,int m , int n){

int matrix[m+1][n+1];

for(int i=0;i<=m;i++)
    for(int j=0;j<=n; j++)
        matrix[i][j]=0;



for(int i=0;i<=m;i++){
    for(int j = 0 ; j<=n ; j++){
        if(i==0 || j==0){
            matrix[i][j]==0;
        }
        else if(x[i-1] == y[j-1]){
            matrix[i][j]= matrix[i-1][j-1]+1;
        }
        else{
            matrix[i][j]= max(matrix[i-1][j], matrix[i][j-1]);
        }
    }
}
return matrix[m][n];

}



int main(){

string str1, str2;
cout<<"enter string1";
cin>>str1;
cout<<"enter string2";
cin>>str2;
cout<<lcs(str1,str2,str1.size(),str2.size());
return 0;

}
