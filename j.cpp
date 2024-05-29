#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 500005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Point pair<double, double>
#define Vector pair<double, double>

int orientation(Point p1, Point p2, Point p3){
    Vector v1(p2.first - p1.first, p2.second - p1.second);
    Vector v2(p3.first - p2.first, p3.second - p2.second);
    double cross = v1.first * v2.second - v1.second * v2.first;
    if(cross > 0) return 1;
    else if(cross < 0) return -1;
    else return 0;
}


int32_t main(){ faster
    int n;
    double x, y;
    Point camera;
    vector<Point> polygon;
    cin >> n;
    polygon.reserve(n);
    for(int i=0;i<n;i++){
        cin >> x >> y;
        polygon.emplace_back(x, y);
    }
    cin >> x >> y;
    camera = Point(x, y);
    bool darkCorner = false;
    int orientacao = orientation(polygon[n - 1], polygon[0], camera);
    for(int i=0;i<n-1;i++){
        if(orientation(polygon[i], polygon[i + 1], camera) != orientacao){
            darkCorner = true;
            break;
        }
    }
    cout << (!darkCorner ? "S" : "N") << '\n';
}