#include<iostream>
#include<time.h>
#include<chrono>
#include<vector>

using namespace std;

int BinarySearch(vector<int>& a, const int x, const int n){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(x < a[middle]){
            right = middle - 1;
        }
        else if(x > a[middle]){
            left = middle + 1;
        }
        else{
            return middle;
        }
    }
    return -1;
}

int main(){
    for(int n=1; n<=100; n++){
        vector<int> a;
        for(int i=0; i<n; i++){
            a.push_back(i);
        }
        int x = rand() % n;
        auto start = chrono::steady_clock::now();
        BinarySearch(a, x, n);
        auto end = chrono::steady_clock::now();
        auto time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        cout << "NO." << n << '\t' << "Time cost:" << (double)(time)  << " nanoseconds" << endl;
    }
    return 0;
}
