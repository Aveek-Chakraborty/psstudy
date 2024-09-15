#include<bits/stdc++.h>
using namespace std;


void bubble(vector<int>& v){
    int n = v.size();
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0; j < n-i-1 ; j++){
            if(v[j] > v[j+1]){
                swap(v[j] , v[j+1]);
            }
        }
    }
}

void selection(vector<int> &v){
    int n = v.size();
    for(int i = 0 ; i < n ; i++){
        int mini=i;
        for(int j = i+1 ; j < n ; j++){
            if(v[mini] > v[j]){
                mini = j;
            }
        }
        swap(v[i] , v[mini]);
    }
}

void insertion(vector<int>& v){
    int n = v.size();
    for(int i = 1 ; i < n ; i++) {
        int key = v[i];
        int j=i-1;

        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
}

int main(){

    vector<int> v={435,456,234,456,678,3452,234,456,7896,3452,4536,7896,2345};
    insertion(v);
    for(auto it : v){
        cout << it << " ";
    }
    return 0;
}