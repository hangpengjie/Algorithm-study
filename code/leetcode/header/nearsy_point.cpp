#include<bits/stdc++.h>
using namespace std;
// START CUT
struct point
{
    double x,y;
}p[200010],temp[200010];
bool cmp_x(const point& a,const point & b){
    if(a.x == b.x)  return a.y < b.y;
    else    return a.x <b.x;
}
bool cmp_y(const point&a , const point&b){
    return a.y < b.y;
}
double distance(const point&a , const point&b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double merge(int left, int right){
    // max
    double dis = 2 << 20;
    if(left == right)   return dis;
    if(left + 1 == right)  return distance(p[left],p[right]);
    int mid = (left + right) >> 1;
    double d1 = merge(left, mid);
    double d2 = merge(mid+1,right);
    dis = min(d1,d2);
    int k = 0;
    for(int i=left; i<=right; ++i){
        if(fabs(p[i].x - p[mid].x) <= dis){
            temp[k++] = p[i];
        }
    }
    sort(temp,temp + k,cmp_y);
    for(int i=0;i<k;i++)
        for(int j=i+1; j<k && temp[j].y-temp[i].y<dis; j++)
            dis=min(dis,distance(temp[i],temp[j]));
    return dis;
}
// END CUT
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lf %lf",&p[i].x,&p[i].y);
    sort(p,p+n,cmp_x);
    printf("%.4lf\n",merge(0,n-1));
    return 0;
}

