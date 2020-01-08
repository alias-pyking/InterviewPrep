#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int tmax = INT_MIN;
    int pmax= INT_MIN;
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i <= n -3; i++)
    {
        for(int j = 0; j <= m  - 3; j++)
        {
            int smax = 0;
            for(int k = j; k < j + 3; k++)
            {
                cout << arr[i][k] << " ";
                smax += arr[i][k];
            }
            cout << "\n";
            // cout << arr[i + 1][j + 1] << " ";
            smax += arr[i + 1][j + 1];
            cout << "\n";
            for(int k = j; k < j + 3; k++)
            {
                cout << arr[i + 2][k] << " ";
                smax += arr[i + 2][k];
            }
            // cout << "\n";
            // cout << "sum is : " << smax;
            // cout << "end here \n";
            pmax = max(smax, pmax);
            // tmax = max(smax,tmax);
            // pmax = max(tmax,pmax);
            // cout << pmax << "\n";
        }
    }
    return pmax;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
