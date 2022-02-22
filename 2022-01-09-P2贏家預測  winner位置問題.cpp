//2022-01-09-P2贏家預測  winner位置問題.cpp
//AC (4ms, 368KB)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> s(n+1), t(n+1);
    vector<int> id(n), n_lose(n+1);
    vector<int> winner, loser;  //放在  while(id.size()>1)下面  
    for(int i=1; i<=n; i++)       //每次重置winner, loser  就不用clear
        cin>>s[i];               
    for(int i=1; i<=n; i++)
        cin>>t[i];
    for(int i=0; i<n; i++)
        cin>>id[i];
    while(id.size()>1)           //
    {
        //  vector<int> winner, loser;  放這  不用clear  少1ms   AC (4ms, 376KB)
        for(int i=0; i+2<=id.size(); i+=2)  //也可用  i+1 < id.size()
        {
            int win=id[i], lose=id[i+1];
            if (s[win]*t[win] < s[lose]*t[lose])
                swap(win,lose);
            ll a=s[win], b=t[win], c=s[lose], d=t[lose];
            s[win] += c*d/(2*b);
            t[win] += c*d/(2*a);
            s[lose] += c/2;
            t[lose] += d/2;
            winner.push_back(win);
            if (++n_lose[lose] < m)
                loser.push_back(lose);
        }
        if (id.size() %2 ==1)
            winner.push_back( id[ id.size()-1 ] );  //改winner.push_back( id.back() )  
        id.swap(winner);                              //AC (3ms, 352KB)  快1ms
        id.insert( id.end(), loser.begin(), loser.end() );
        winner.clear();         // 每輪比完  重置winner, loser 
        loser.clear();         //  沒重置會TLE  或其他錯誤
    }
    cout << id[0] << endl;
    return 0;
}

/*
id.size()  = 2
id         = 0 1
id首標籤0
id尾標籤 = size-1 = 1

id.size()  = 3
id         = 0 1 2
id首標籤0
id尾標籤 = size-1 = 2

id.size()  = 4
id         = 0 1 2 3
id首標籤0
id尾標籤 = size-1 = 3

id.size()  = 5
id         = 0 1 2 3 4
id首標籤0
id尾標籤 = size-1 = 4
--------------------------

定義
id尾標籤 = id.size()-1
id.size() = id尾標籤 +1

當id標籤=尾標籤
是最後一人  不足兩人  無法比賽
所以id標籤 != id尾標籤
所以id標籤  < id尾標籤
         i  < id.size()-1

-----------------------------

i每次+2  每次兩人比賽
i的下一個標籤  i+1必須存在  才能兩人比賽
i+1標籤 <= id尾標籤
i+1標籤 <= id.size()-1　
    i+1 <= id.size()-1　

-----------------------------

最後至少5種寫法
i   <  id.size()-1
i+1 <  id.size()
i+1 <= id.size()-1
i+2 <= id.size()
i+2 <  id.size()+1

*/
