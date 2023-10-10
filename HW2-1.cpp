#include<iostream>
#include<time.h>

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
    for(int n=1; n<=100; n++){
        int *a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = i;
        }
        //srand(time(NULL));
        int x = rand() % n;
        auto start = clock();
        int index = BinarySearch(a, x, n);
        auto end = clock();
        double t = static_cast<double>((end - start) /(double)CLOCKS_PER_SEC);
        if(index == -1){
            cout << "NO."<<n<<" Not found" << endl;
        }
        else{
            cout << "NO." << n << " index= "<< index << " time cost: "<< t << endl;
        }
        delete []a;


    }
    return 0;
}
