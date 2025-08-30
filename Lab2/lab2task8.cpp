#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,m;
    cout<<"days: ";
    cin>>n;
    cout<<"times: "; 
    cin>>m;

    float **t = new float*[n];
    for (int i = 0; i < n; i++) {
        t[i] = new float[m];
    }

    for (int i = 0; i < n; i++) 
    {
        cout<<"day "<<i+1<<":\n";
        for (int j = 0; j < m; j++) {
            cout<<"temp "<<j+1<<": ";
            cin>>t[i][j];
        }
    }

    float maxAvg=-1,minAvg=1;
    int hot=-1,cold =1;

    cout<<"averages:\n";
    for (int i = 0; i < n; i++) {
        float sum=0;
        for (int j=0; j < m; j++) {
            sum+=t[i][j];
        }
        float avg=sum/m;
        cout<<"Day "<<i+1<<": "<<avg<<endl;
        if (avg>maxAvg) {
            maxAvg=avg;
            hot=i+1;
        }
        if (avg<minAvg) {
            minAvg=avg; 
            cold=i+1;
        }
    }

    cout<<"hottest Day: "<<hot<<" ("<<maxAvg<<")\n";
    cout<<"coldest Day: "<<cold<<" ("<<minAvg<<")\n";

    for (int i = 0; i < n; i++) {
        delete[] t[i];
    }
    delete[] t;
    return 0;
}