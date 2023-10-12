#include<iostream>
#include<time.h>
#include<chrono>

using namespace std;

int BinarySearch(int*a, const int x, const int n){
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
    for(int n=1; n<=10; n++){
        int *a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = i;
        }
        int x = rand() % n;
        double start = clock();
        int index = BinarySearch(a, x, n);
        double end = clock();
        if(index == -1){
            cout << "NO."<<n<<" Not found" << endl;
        }
        else{
            cout << "NO." << n <<'\t'<< "index= "<< index << '\t' << "time cost: "<< (end-start)/CLOCKS_PER_SEC<< endl;
        }
        delete []a;


    }
    return 0;
}
