#include<bits/stdc++.h>
using namespace std;

int superSequence(char X[], char Y[] , int m ,int n )
{
     int matrix[m+1][n+1];
    for(int j=0;j<m;j++){
                cout<<X[j];

        }

        for(int j=0;j<n;j++){
                cout<<Y[j];

        }


    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(!i)
                matrix[i][j]=j;
            else if(!j)
                matrix[i][j]=i;

           else if (X[i-1]==Y[j-1]){

                matrix[i][j]=1+ matrix[i-1][j-1];
                }
           else
                matrix[i][j]=1+ min(matrix[i][j-1],matrix[i-1][j]);

        }
    }
    return matrix[m][n];

}



int main(){
    int m, n ;

cin>>m;
char X[m];
for(int i = 0 ;i<m;i++){
    cin>>X[i];
}
cin>>n;
char Y[n];

for(int i = 0 ;i<n;i++){
    cin>>Y[i];
}

cout<<superSequence(X,Y,m,n);
return 0;

}


