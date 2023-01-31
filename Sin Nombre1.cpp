#include <iostream>
using namespace std;

int main() {
    
    int num=3;
    string palabras[num];
    string aux1;
    
    for(int i=0;i<num;i++){
    cout<<"Introduce una palabra: "<<endl;
    cin>>palabras[i];
    }

    cout << endl;

    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(palabras[i]>palabras[j]){ 

                aux1 = palabras[j]; 
                palabras[j] = palabras[i]; 
                palabras[i] = aux1; 
            }
        }
    }
    cout << endl;
    for(int i=0;i<num;i++){
        cout<<palabras[i]<<endl;
    }
    return 0;
}
