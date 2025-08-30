#include <iostream>
#include <string>
using namespace std;

int main(){
    int r;
    cout<<"enter number of categories: ";
    cin>>r;

    int **lib = new int*[r]; 
    for (int i = 0; i < r; i++) {
        int numBooks;
        cout<<"enter number of books in category "<<i+1<<": ";
        cin>>numBooks;

        lib[i]=new int[numBooks+1];
        lib[i][0]=numBooks;

        cout<<"enter book IDs for category "<<i+1<< ":\n";
        for (int j=1 ;j <= numBooks; j++) {
            cin>>lib[i][j];
        }
    }
    int id;
    cout<<"enter book ID to search: ";
    cin>>id;

    bool found = false;
    for (int i = 0; i < r; i++) {
        for (int j = 1; j <=lib[i][0]; j++){
            if (lib[i][j]==id){
                cout<<"book "<<id<<" found in category "<<i+1<<endl;
                found=true;
                break;
            }
        }
        if(found){ 
            break;
        }
    }

    if (!found){
        cout<<"book "<<id<<" not found in library\n";
    }

    for (int i = 0; i < r; i++) {
        delete[] lib[i];
    }
    delete[] lib;
    return 0;
}