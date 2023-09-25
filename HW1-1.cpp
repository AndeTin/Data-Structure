#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void Bubblesort(char** arr,int x){
    for(int i=0;i<x-1;i++){
        if(arr[i][0]<arr[i+1][0]){
            char temp = arr[i][0];
            arr[i][0] = arr[i+1][0];
            arr[i+1][0] = temp;
        }
    }
}

int main(){
       int x,y;
       char input[100];
       cout<<"Please input how many arrays and how many characters in each array:"<<endl;
       cin>>x>>y;
       char** arr = new char* [x];
       for(int i=0;i<x;i++){
            arr[i] = new char [y+1];
       }
       for(int i=0;i<x;i++){
            cout<<"Please enter the "<<i+1<<" array:"<<endl;
            cin.ignore();
            cin.get(input,100);
            for(int j=0;j<y;j++){
                arr[i][j] = input[j];
            }

       }       
    Bubblesort(arr,x);
    cout<<"After sorting:"<<endl<<endl;
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<x;i++){
        delete [] arr[i];
    }
    delete [] arr;
}
