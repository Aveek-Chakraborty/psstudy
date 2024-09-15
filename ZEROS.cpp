#include<bits/stdc++.h>
using namespace std;

void sz(vector<int>&v){
    // int i = 0;
    // int j = v.size()-1;
    // while(i<j){
    //     while(v[i]!=0){
    //         i++;
    //     }
    //     while(v[j]==0){
    //         j--;
    //     }

    //     if(i<j){
    //         swap(v[i],v[j]);
    //         i++;
    //         j--;
    //     }
    // }

    int i = 0; // Pointer to place non-zero elements
    for (int j = 0; j < v.size(); j++) {
        if (v[j] != 0) {
            swap(v[i], v[j]); // Swap non-zero element with element at index i
            i++;
        }
    }
}



int main(){

    vector<int> v={54,0,67,3,0,0,56,4,0,67,0,6,0,0};
    sz(v);
    for(auto it : v){
        cout<< it << " ";
    }

    return 0;
}