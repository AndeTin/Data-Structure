#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void namearrangge(int count,string* arr,int x){                                             //排列字串
    size_t t=0;
    size_t found;
    t = arr[count].find(" ",0);
    for(int i=0;i<x;i++){
        found = arr[i].find(" ",0);
        while(found != string::npos && t>found){  
            arr[i] = " " + arr[i];
            found = arr[i].find(" ",found+1);                                               //找到新的空白以便於重新判斷
        }
    }
}

int main(){
    int x,maxlen=0,count=0;                                                                 //宣告變數                   
    string name;                                                                            //宣告字串              
    cout << "Please enter how much names you want to arrange:"<<endl;
    cin >> x;
    if(x<=0){                                                                               //判斷輸入是否為正整數
        cout << "Error! Please enter a positive number!"<<endl;
        return 0;
    }
    string *arr = new string[x];                                                            //宣告陣列                      
    cin.ignore();                                                                           //忽略enter                
    for(int i=0;i<x;i++){
        cout << "Please enter the "<<i+1<<" name:"<<endl;
        getline(cin, name);                                                                                  
        if(name.find(" ")!=string::npos && name.find(" ")>maxlen){                          //找到空白且空白位置大於maxlen
            maxlen=name.find(" ");
            count=i;                                                                        //記錄最長的字串位置                
        }
        arr[i]=name;                                                                                    
    }

    namearrangge(count,arr,x);                                                              //呼叫函式                        

    cout << "After arranging:"<<endl;
    
    for(int i=0;i<x;i++){                                                                   //輸出         
        cout << arr[i] << endl;
    }

    delete[] arr;                                                                           //釋放記憶體
    return 0;
}

