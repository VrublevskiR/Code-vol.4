#include <iostream>
using namespace std;

int main()
{
    int n1; int n2;
    cin >> n1;
    cin >> n2;
    int a[n1][n2];
    for(int i=0;i<n1;i++)
    {
      for(int j=0;j<n2;j++)
      {
      cin >> a[i][j];
      }
    }
    cout<<endl;
    for(int j=0;j<n2;j++)
    {
      for(int i=0;i<n1;i++)
      {
      cout << a[i][j]<<" ";
      }
      cout <<endl;
    }
    return 0;
}