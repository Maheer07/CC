#include<bits/stdc++.h>
using namespace std;

long long int fac(long long n){
    if(n == 0)  return 1;
    else if (n == 1)    return 1;
    else return n*fac(n-1);
}

long long int c(long long n,long long m){
    return fac(n) / (fac(m)*fac(n-m));
}

int main(){
    long long int n,m;
    cin>>n>>m;
    for(long long int z = 0; z< m; z++){
        long long int a;
        cin>>a;
        long long int l;
        if(a%3 == 0){
            l = a/3; 
        }
        else    l = a/3 + 1;
        long long int res = 0;
        for(long long int i = l; i <=n; i++){
            res += c(3*i,a);
        }

    
        const unsigned int M = 1000000007;
 
        unsigned long long f = 1;
        for (int i = 1; i <= res; i++)
            f = (f*i) % M;
        cout<<f<<endl;




    }
    return 0;
}