#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
#define readStr(t) scanf("%s\n", &t);
#define readInt(t) scanf("%d\n", &t);
#define printStr(s) printf("%s\n", s);
#define printInt(t) printf("%d\n", t);
#define ll long long
#define pb push_back

#define printList(i, n, a)      \
    for (int j = i; j < n; j++) \
        cout << (a[j]) << " ";

int KmpStringComparison(string dictionary, string pattern)
{
    int len = pattern.length();
    string tempPattern = pattern;
    reverse(pattern.begin(), pattern.end());
    pattern = tempPattern + pattern;
    int n = pattern.length();
    printInt(n);
    int m = dictionary.length();
    int prefix_suffix_array[n];
    prefix_suffix_array[0] = 0;
    int j = 0;
    int i = 1;
    for (; i < n;)
    {
        if (pattern[i] == pattern[j])
        {
            prefix_suffix_array[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix_suffix_array[j - 1];
            }
            else
            {
                prefix_suffix_array[i] = 0;
                i++;
            }
        }
    }
    int minimum_insertions = 0;
    printList(0, n, prefix_suffix_array);
    minimum_insertions = len - prefix_suffix_array[n - 1];
    return minimum_insertions;
}
int main()
{
    string dictionary = "abxabcabcby";
    string pattern = "AACECAAAA";
    cout << "\n"
         << KmpStringComparison(dictionary, pattern) << "\n";
    return 0;
}