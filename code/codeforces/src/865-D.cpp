#include<bits/stdc++.h>
// https://codeforces.com/contest/865/problem/D
using namespace std;
int main()
{
    int n; cin >> n;
 
   vector <int> a(n);
   for(int i=0; i<n; ++i){
      cin >> a[i];
   }
 
 
   int ans=0;
   multiset <int> s;
   for(int i=0; i<n; ++i){
      s.insert(a[i]);
 
      ans+=a[i]-*s.begin();
      s.erase(s.begin());
      s.insert(a[i]);
   }
 
   cout <<ans <<endl;


}