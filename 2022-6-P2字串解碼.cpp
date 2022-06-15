#include<bits/stdc++.h>
//2022-6 P2字串解碼  參考  https://0rz.tw/PZ9ty
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    vector<string> v(m);
    for(int i=0; i<m; i++)
        cin >> v[i];
    string cipher;
    cin >> cipher;
    deque<char> c(cipher.begin(),cipher.end() );
    deque<char> plain;  //不知哪有問題  只有60分
    for (int i=m-1; i>=0; i--)
    {
        int odd = 0;
        deque<char> p;

        for (int j=n-1; j>=0; j--)
        {
            if (v[i][j]=='1')
                odd++;
            if (v[i][j]=='0')
                p.push_front(c[j]);
            else
                p.push_back(c[j]);
        }
        if (odd%2)
            for (int j=0; j<n/2; j++)
                swap(p[j], p[n-n/2+j] );
        plain= p;  //用c=plain就100分
    }
    for(char i : plain)
        cout << i;
}
