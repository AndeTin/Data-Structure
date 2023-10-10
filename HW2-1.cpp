#include<iostream>
#include<time.h>

using namespace std;

int(BinarySearch(int*a, const int x, const int n)){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(x == a[middle]){
            return middle;
        }
        if(x > a[middle]){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    return -1;
}

int main(){
    int a[100];
    srand(time(NULL));
    int t = rand() % 100 + 1;
    for(int i = 0; i < 100; i++){
        a[i] = i + 1;
    }
    clock_t start = clock();
    cout << BinarySearch(a, t, 100) << endl;
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
    return 0;
}