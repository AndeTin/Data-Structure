#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void namearrangge(int count,string* arr,int x){
    size_t t=0;
    size_t found;
    t = arr[count].find(" ",0);
    for(int i=0;i<x;i++){
        found = arr[i].find(" ",0);
        while(found != string::npos && t>found){  
            arr[i] = " " + arr[i];
            found = arr[i].find(" ",found+1); // update found after adding a space
        }
    }
}
int main(){
    int x,maxlen=0,count=0;
    string name;
    cout << "Please enter how much names you want to arrange:"<<endl;
    cin >> x;
    if(x<=0){
        cout << "Error! Please enter a positive number!"<<endl;
        return 0;
    }
    string *arr = new string[x];
    cin.ignore();
    for(int i=0;i<x;i++){
        cout << "Please enter the "<<i+1<<" name:"<<endl;
        getline(cin, name);
        if(name.length()>maxlen){
            maxlen=name.length();
            count=i;

        }
        arr[i]=name;
    }

    namearrangge(count,arr,x);

    cout << "After arranging:"<<endl;
    
    for(int i=0;i<x;i++){
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}

