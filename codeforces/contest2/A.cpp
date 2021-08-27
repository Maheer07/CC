#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    vector<double> ans;
    
    for(int x = 0; x < t; x++){

        int n;
        cin>>n;
        vector<float> v;
        int s = 0;
        for(int i = 0; i < n; i++){
            int z;
            cin>>z;
            s += z;
            v.push_back(z);
        }
        sort(v.begin(),v.end());
        
        int r = v[n-1];
        int l = s-r;
        float f1 = r /1.000000000;
        float f2 = l / (1.000000000 * (n-1));
        float res = f1 + f2;

        int i = n-1;
        int f = 1.0;
        while(true){
            i--;
            f++;
            r += v[i];
            l = s-r;
            f2 = l / (i*1.000000000);
            f1 = r/(f*1.000000000);
            if(f1 + f2 > res)   res = f1 + f2;
            else break;
        }
        ans.push_back(res);


    }

    for(int i = 0; i < t; i++){
        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        std::cout << ans[i]<<endl;

    }
    return 0;
}