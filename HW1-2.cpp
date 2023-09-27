#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void Bubblesort(char** arr,int x){                                                              //排列字串
    for(int i=0;i<x-1;i++){
        if(arr[i][0]<arr[i+1][0]){
            char* temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main(){
       int x,y;                                                                                 //宣告變數                               
       char input[100];                                                                         //宣告字串                        
       cout<<"Please input how many arrays and how many characters in each array:"<<endl;
       cin>>x>>y;                                                                               //輸入
       char** arr = (char**)malloc(sizeof(char*)*x);                                            //宣告二維陣列              
       for(int i=0;i<x;i++){
            arr[i] = (char*)malloc(sizeof(char)*(y+1));
       }
       for(int i=0;i<x;i++){
            cout<<"Please enter the "<<i+1<<" array:"<<endl;
            cin.ignore();                                                                        //忽略enter                        
            cin.get(input,100);                                                                  //輸入
            for(int j=0;j<y;j++){
                arr[i][j] = input[j];
            }
            arr[i][y] = '\0';                                                                    //字串結尾
       }       
    Bubblesort(arr,x);                                                                           //呼叫函式                           
    cout<<"After sorting:"<<endl<<endl;
    
    for(int i=0;i<x;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<x;i++){                                                                         //釋放記憶體                      
        delete [] arr[i];
    }
    delete [] arr;
    return 0;                                                                                     //結束程式
}
