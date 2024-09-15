#include<bits/stdc++.h>
using namespace std;


int solve(int n){
    string s="";
    for(int i =0 ; i< n ;i++){
        s+='A';
    }

    for(int i =0 ; i< n ;i++){
        s+='B';
    }
    int c = 0;

    do{
        int a = 0;
        int b=0;
        for(int i = 0 ; i<n ;i++){
            if(s[i]=='A') a++;
            if(s[i]=='B') b++;
        }

        if(a>b){
            c++;
        }
    }while(next_permutation(s.begin() , s.end()));

    return c;
}



int main(){
    cout<<solve(3);
    return 0;
}