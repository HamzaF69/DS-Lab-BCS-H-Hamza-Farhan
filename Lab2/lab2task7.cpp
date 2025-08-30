#include <iostream>
using namespace std;

int main() {
    int d;
    cout<<"enter number of departments: ";
    cin>>d;

    int **dept=new int*[d]; 
    for (int i = 0; i < d; i++) {
        int n;
        cout<<"enter number of employees in department "<<i+1<<": ";
        cin>>n;

        dept[i]=new int[n+1];
        dept[i][0]=n;
        cout<<"enter salaries of "<<n<<" employees:\n";
        for(int j = 1; j <= n; j++){
            cin>>dept[i][j];
        }
    }

    cout<<"highest salary in each department:\n";
    for (int i = 0; i < d; i++) 
    {
        int highest=dept[i][1];
        for (int j = 2; j <= dept[i][0]; j++) 
        {
            if (dept[i][j]>highest){
                highest=dept[i][j];
            }
        }
        cout<<"department "<<i+1<<": "<<highest<<endl;
    }

    int bestDept=0;
    double maxAvg=-1;

    for (int i = 0; i < d; i++) {
        int sum=0;
        for(int j = 1; j <= dept[i][0]; j++) {
            sum+=dept[i][j];
        }
        double avg=sum/dept[i][0];
        if (avg>maxAvg) {
            maxAvg=avg;
            bestDept=i;
        }
    }
    cout<<"\ndepartment "<<bestDept+1<<" has the highest average salary: "<<maxAvg<<endl;
    for (int i = 0; i < d; i++) {
        delete[] dept[i];
    }
    return 0;
}