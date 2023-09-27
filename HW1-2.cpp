#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void Bubblesort(char** arr,int x){
    for(int i=0;i<x-1;i++){
        if(arr[i][0]<arr[i+1][0]){
            char* temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main(){
       int x,y;
       char input[100];
       cout<<"Please input how many arrays and how many characters in each array:"<<endl;
       cin>>x>>y;
       char** arr = (char**)malloc(sizeof(char*)*x);
       for(int i=0;i<x;i++){
            arr[i] = (char*)malloc(sizeof(char)*(y+1));
       }
       for(int i=0;i<x;i++){
            cout<<"Please enter the "<<i+1<<" array:"<<endl;
            cin.ignore();
            cin.get(input,100);
            for(int j=0;j<y;j++){
                arr[i][j] = input[j];
            }
            arr[i][y] = '\0'; 
       }       
    Bubblesort(arr,x);
    cout<<"After sorting:"<<endl<<endl;
    
    for(int i=0;i<x;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<x;i++){
        delete [] arr[i];
    }
    delete [] arr;
}
