#include<iostream>
#include<string>
using namespace std;
 
int main() {
    int r;
    cout<<"enter number of students: ";
    cin>>r;
    int **std= new int*[r];
    for (int i = 0; i < r; i++)
    {
        int c;
        cout<<"enter number of subjects for student "<<i+1<<" : ";
        cin>>c;
        std[i]=new int[c+1];
        std[i][0]=c; 
    }

    for (int i = 0; i < r; i++)
    {
        cout<<"enter marks for student: "<<i+1<<" :\n";
        int subs= std[i][0];
        for(int j =1; j<subs+1;j++){
            cout<<"subject: "<<j<<": ";
            cin>>std[i][j];
        }
    }
    
    cout<<"marks of students:\n";
    for (int i = 0; i < r; i++) {
        cout << "student "<<i+1<<": ";
        int c = std[i][0]; 

        float total=0;
        for (int j = 1; j <= c; j++) {
            total+=std[i][j];
        }
        float avg;
        avg=total/c;
        cout<<"average grade: "<<avg<<endl;
        cout << endl;
    }
    
    return 0;
}