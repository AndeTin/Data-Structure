#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

int SelectionSort(vector<int>& a, const int n){
    int count = 0;
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            swap(a[i], a[min]);
            count++;
        }
    }
    return count;
}
int main(){
    for(int n=1; n<=100; n++){
        vector<int> a;
        for(int i=0; i<n; i++){
            a.push_back(i);
        }
        int x = rand() % n;
        auto start = chrono::steady_clock::now();
        SelectionSort(a, n);
        auto end = chrono::steady_clock::now();
        auto time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        cout << "NO." << n << '\t' << "Time cost:" << (double)(time)  << " nanoseconds" << endl;
    }
    return 0;
}