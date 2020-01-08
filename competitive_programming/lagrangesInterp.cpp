#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define readStr(t) scanf("%s\n", &t);
#define readInt(t) scanf("%d\n", &t);
#define printStr(s) printf("%s\n", s);
#define printInt(t) printf("%d\n", t);
#define ll long long
#define pb push_back
#define mod 1000000007

#define printList(i, n, a)      \
    for (int j = i; j < n; j++) \
        cout << (a[j]) << " ";
double data_points[100][100];

double L(double xi, double x, int i, int n)
{
    double res = 1;
    for (int j = 0; j < n; j++)
    {
        if (i != j)
        {
            res *= (x - data_points[j][0]) / (xi - data_points[j][0]);
        }
    }
    return res;
}
double getInterpolate(int x, int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        res += L(data_points[i][0], x, i, n) * data_points[i][1];
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> data_points[i][0];
        cin >> data_points[i][1];
    }

    double fnx = getInterpolate(x,n);
    cout <<"The value of f("<<x<<") = "<<fnx << "\n";
    return 0;
}
