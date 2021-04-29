#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int i,j,k,l;
    long int max=numeric_limits<streamsize>::min(),sum;
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            sum=0;
            for(k=0;k<=2;k++){
                for(l=0;l<=2;l++){
                    if(k==1 && (l==0||l==2)){
                        continue;
                    }else{
                        sum+=arr[i+k][j+l];
                    }
                }
            }
            if(max<sum){
                max=sum;
            }
            cout<<"max = "<<max<<endl;
        }
    }
    return max;

}

int main()
{
    

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout<<"Running"<<endl;
    int result = hourglassSum(arr);
    cout<<result;
    return 0;
}
