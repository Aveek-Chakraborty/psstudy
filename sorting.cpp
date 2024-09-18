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

int partition(vector<int>& v, int s , int e){
    int c = 0;
    int pivot = v[s];

    for(int i = s+1 ; i <= e ; i++){
        if(v[i] < pivot){
            c++;
        }
    }

    int partition = s+c;
    swap(v[s] , v[partition]);

    int i =s ; int j=e;

    while(i<partition && j > partition){
        while(v[i] < v[partition]){
            i++;
        }

        while(v[partition]  < v[j]){
            j--;
        }

        if(i < partition && j>partition){
            swap(v[i] , v[j]);
        }
    }

    return partition;
}

void quicksort(vector<int>& v , int s , int e){
    if(s>=e){
        return;
    }

    int pivot = partition(v , s , e);

    quicksort(v, s , pivot-1);
    quicksort(v , pivot+1 , e);
}



int main(){

    vector<int> v={435,456,234,456,678,3452,234,456,7896,3452,4536,7896,2345};
    quicksort(v , 0 , v.size()-1);
    for(auto it : v){
        cout << it << " ";
    }
    return 0;
}