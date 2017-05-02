/**
 * @Date:   26-Apr-2017
 * @Email:  809810527@qq.com
 * @Filename: F_Signal Interference.cpp
 * @Last modified time: 27-Apr-2017
 * @Copyright: Copr. 2017 EndlessLethe. All rights reserved.
 * @Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <stack>
//#include <bits/stdc++.h>
using namespace::std;
#define MAXN 100010

//点类
const double EPS = 1e-8;
int dcmp(double k) {
	return k < -EPS? -1 : k > EPS ? 1 : 0;
}

const double PI = acos(-1.0);
inline double sqr(double x) {
	return x * x;
}
struct point {
	double x, y;
	point() {}
	point(double a, double b): x(a), y(b) {}
	void input() {
		scanf("%lf%lf", &x, &y);
	}
	friend point operator + (const point &a, const point &b) {
		return point(a.x+b.x, a.y+b.y);
	}
	friend point operator - (const point &a, const point &b) {
		return point(a.x-b.x, a.y-b.y);
	}
	friend bool operator == (const point &a, const point &b) {
		return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
	}
	friend point operator * (const point &a, const double &b) {
		return point(a.x*b, a.y*b);
	}
	friend point operator * (const double &a, const point &b) {
		return point(a*b.x, a*b.y);
	}
	friend point operator / (const point &a, const double &b) {
		return point(a.x/b, a.y/b);
	}
	double norm() {
		return sqrt(sqr(x) + sqr(y));
	}
};
double cross(const point &a, const point &b) {
	return a.x*b.y - a.y*b.x;
}
double dot(const point &a, const point &b) {
	return a.x*b.x + a.y*b.y;
}
double dist(const point &a, const point &b) {
	return (a-b).norm();
}
point rotate_point(const point &p, double A) {
	double tx = p.x, ty = p.y;
	return point(tx*cos(A)-ty*sin(A), tx*sin(A)+ty*cos(A));
}

//圆与直线交
double mysqrt(double n) {
	return sqrt(max(0.0, n));
}

void circle_cross_line(point a, point b, point o, double r, point ret[], int &num) {
	double x0 = o.x, y0 = o.y;
	double x1 = a.x, y1 = a.y;
	double x2 = b.x, y2 = b.y;
	double dx = x2 - x1, dy = y2 - y1;
	double A = dx*dx + dy*dy;
	double B = 2*dx*(x1-x0) + 2*dy*(y1-y0);
	double C = sqr(x1-x0) + sqr(y1-y0)-sqr(r);
	double delta = B*B - 4*A*C;
	num = 0;
	if (dcmp(delta) >= 0) {
		double t1 = (-B - mysqrt(delta)) / (2*A);
		double t2 = (-B + mysqrt(delta)) / (2*A);
		if (dcmp(t1-1) <= 0 && dcmp(t1) >= 0) {
			ret[num++] = point(x1 + t1*dx, y1 + t1*dy);
		}
		if (dcmp(t2-1) <= 0 && dcmp(t2) >= 0) {
			ret[num++] = point(x1 + t2*dx, y1 + t2*dy);
		}
	}
}
//

double abs(const point& o) {
	return sqrt(dot(o, o));
}

point crosspt(const point &a, const point &b, const point &p, const point &q) {
	double a1 = cross(b-a, p-a);
	double a2 = cross(b-a, q-a);
	return (p * a2 - q*a1) / (a2-a1);
}

point res[MAXN];
double r;
int n;
point o;

double sector_area(const point &a, const point &b){
	double theta = atan2(a.y, a.x) - atan2(b.y, b.x);
	while (theta <= 0) theta += 2*PI;
	while (theta > 2*PI) theta -= 2*PI;
	theta = min(theta, 2*PI - theta);
	return r*r*theta/2;
}

double calc(const point &a, const point &b) {
	point p[2];
	int num = 0;
	int ina = dcmp(abs(a)-r) < 0;
	int inb = dcmp(abs(b)-r) < 0;
	if (ina) {
		if (inb) {
			return fabs(cross(a, b)) / 2.0;
		}
		else {
			circle_cross_line(a, b, point(0, 0), r, p, num);
			return sector_area(b, p[0]) + fabs(cross(a, p[0])) / 2.0;
		}
	}
	else {
		if (inb) {
			circle_cross_line(a, b, point(0, 0), r, p, num);
			return sector_area(p[0], a) + fabs(cross(p[0], b)) / 2.0;
		}
		else {
			circle_cross_line(a, b, point(0, 0), r, p, num);
			if (num == 2) {
				return sector_area(a, p[0]) + sector_area(p[1], b)
				 + fabs(cross(p[0], p[1])) / 2.0;
			}
			else {
				return sector_area(a, b);
			}
		}
	}
}

double areaItersection() {
	double ret = 0;
	for (int i = 0; i < n; i++) {
		int sgn = dcmp(cross(res[i], res[i+1]));
		if (sgn != 0) {
			ret += sgn * calc(res[i], res[i+1]);
		}
	}
	return ret;
}

//多边形类
double area() {
	double sum = 0;
	for (int i = 0; i < n; i++) sum += cross(res[i+1], res[i]);
	return sum / 2.0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
        freopen("input_F_Signal Interference.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	double k;
	int T = 0;
	while (scanf("%d%lf", &n, &k) == 2) {
		T++;
		printf("Case %d: ", T);
		for (int i = 0; i < n; i++) res[i].input();
		res[n] = res[0];
		double ax,ay,bx,by;
        scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by);
        double mu= k*k-1;
		point a = point(ax, ay);
		point b = point(bx, by);
        o = point(-(bx-k*k*ax)/mu,-(by-k*k*ay)/mu);
		double L=(a-b).norm();
        r = L * k / (-mu);
		for (int i = 0; i <= n; i++) res[i] = res[i] - o;
		// printf("%lf %lf", (o-a).norm() - L / (k+1), L *k / (-mu));
		// r = (o-a).norm();
		// printf("%.9lf\n", area());
		printf("%.10lf\n", fabs(areaItersection()));
		// printf("%.9lf\n", fabs(areaItersection())/fabs(area()));
	}
	return 0;
}
