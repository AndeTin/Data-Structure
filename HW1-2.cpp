#include<iostream>
#include<string>

using namespace std;

void Bubblesort(string** arr,int x){
    for(int i=0;i<x-1;i++){
        if(arr[i][0]>arr[i+1][0]){
            string temp = arr[i][0];
            arr[i][0] = arr[i+1][0];
            arr[i+1][0] = temp;
        }
    }
}

int main(){
       int x,y;
       string input;
       cout<<"Please input how many arrays and how many characters in each array:"<<endl;
       cin>>x>>y;
       string** arr = (string**)malloc(sizeof(string*) * x);
       for(int i=0;i<x;i++){
            arr[i] = new string[y+1];
       }
       for(int i=0;i<x;i++){
            cout<<"Please enter the "<<i+1<<" array:"<<endl;
            cin>>input;
            for(int j=0;j<y;j++){
                arr[i][j] = input[j];
            }

       }       
    Bubblesort(arr,x);
    cout<<"After sorting:"<<endl;
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<x;i++){
        free(arr[i]);
    }
    free(arr);
}