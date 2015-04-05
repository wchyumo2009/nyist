/***********************************************************************
 * Author: C.H Wong
 * Filename: nyist_298.cpp
 * Create Time: 2015/4/5 14:23
 * Description:
 *    首字符如果是M,则表示平移操作，该行后面将跟两个数x,y，表示把所有点按向量(x,y)平移;
 *    首字符如果是X，则表示把所有点相对于X轴进行上下翻转;
 *    首字符如果是Y，则表示把所有点相对于Y轴进行左右翻转;
 *    首字符如果是S，则随后将跟一个数P,表示坐标放大P倍;
 *    首字符如果是R，则随后将跟一个数A,表示所有点相对坐标原点逆时针旋转一定的角度A(单位是度)
 ***********************************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const double Pi = acos(-1.0);

class PointPosition
{
    double x;
    double y;
public:
    PointPosition(const double& _x, const double& _y):x(_x), y(_y){}
    PointPosition():x(0), y(0){}
    double getDSquare(const PointPosition& p)//
    {
        return (p.x-x)*(p.x-x)+(p.y-y)*(p.y-y);
    }
    double getDistance(const PointPosition& p)//
    {
        return sqrt(this->getDSquare(p));
    }

    double getX()//
    {
        return x;
    }
    double getY()//
    {
        return y;
    }

    void setOY()//
    {
        y = -y;
    }
    void setOX()//
    {
        x = -x;
    }
    void transM(const double &_x, const double &_y)//
    {
        x += _x, y += _y;
    }
    void magnify(const double &_p)//
    {
        x *= _p;
        y *= _p;
    }
    //绕原点逆时针旋转r弧度
    void rotateO(const double &r)//
    {
        double nr = sqrt(x*x+y*y);
        if (nr != 0){
            double r1 = acos(x/nr);
            if (y < 0)r1 = -r1;
            x = nr*cos(r+r1);
            y = nr*sin(r+r1);
        }
    }
};

typedef PointPosition VECTOR;
//
void rotateX(vector <PointPosition > &points)
{
    for (std::size_t i = 0; i < points.size(); ++i){
        points[i].setOY();
    }
}
//
void rotateY(vector <PointPosition > &points)
{
    for (std::size_t i = 0; i < points.size(); ++i){
        points[i].setOX();
    }
}
//
void transM(vector <PointPosition > &points, const double &_x, const double &_y)
{
    for (std::size_t i = 0; i < points.size(); ++i){
        points[i].transM(_x, _y);
    }
}
//
void magnifyP(vector <PointPosition > &points, const double &_p)
{
    for (std::size_t i = 0; i < points.size(); ++i){
        points[i].magnify(_p);
    }
}
//
void rotateO(vector <PointPosition > &points, const double &_p)
{
    double r = _p/180*Pi;
    for (std::size_t i = 0; i < points.size(); ++i){
        points[i].rotateO(r);
    }
}

int main()
{
    vector <PointPosition > bpoint;
    PointPosition opoint;
    vector <double > ds[3];
    for (int i = 0; i < 3; ++i){
        if (!ds[i].empty())ds[i].clear();
    }
    if (!bpoint.empty())bpoint.clear();
    int n, m;
    double x, y;
    char type;

    bpoint.push_back(PointPosition(0, 0));
    bpoint.push_back(PointPosition(1, 0));
    bpoint.push_back(PointPosition(0, 1));
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf ("%lf%lf", &x, &y);
        opoint = PointPosition(x, y);
        for (size_t j = 0; j < bpoint.size(); ++j){
            ds[j].push_back(bpoint[j].getDSquare(opoint));
        }
    }
    for (int i = 0; i < m; ++i){
        getchar();
        scanf ("%c", &type);
        if (type == 'X'){
            rotateX(bpoint);
        }
        else if (type == 'Y'){
            rotateY(bpoint);
        }
        else if (type == 'M'){
            scanf ("%lf%lf", &x, &y);
            transM(bpoint, x, y);
        }
        else if (type == 'S'){
            scanf ("%lf", &x);
            magnifyP(bpoint, x);
        }
        else if (type == 'R'){
            scanf ("%lf", &y);
            rotateO(bpoint, y);
        }
    }

    //printf ("ans start=======>\n");
    // hard to understand
    double x1, x2, y1, y2, c1, c2, d, p, q;
    x1 = 2*(bpoint[0].getX()-bpoint[1].getX());
    x2 = 2*(bpoint[0].getX()-bpoint[2].getX());
    y1 = 2*(bpoint[0].getY()-bpoint[1].getY());
    y2 = 2*(bpoint[0].getY()-bpoint[2].getY());
    c1 = bpoint[0].getX()*bpoint[0].getX()-bpoint[1].getX()*bpoint[1].getX()+bpoint[0].getY()*bpoint[0].getY()-bpoint[1].getY()*bpoint[1].getY();
    c2 = bpoint[0].getX()*bpoint[0].getX()-bpoint[2].getX()*bpoint[2].getX()+bpoint[0].getY()*bpoint[0].getY()-bpoint[2].getY()*bpoint[2].getY();

    d = bpoint[1].getDSquare(bpoint[0]);

    x = x1+x2;
    y = x2*y1-x1*y2;

    double ansX, ansY;
    for (int i = 0; i < n; ++i){
        p = (ds[1][i]-ds[0][i])*d+c1, q = (ds[2][i]-ds[0][i])*d+c2;
        ansY = (x2*p-x1*q)/y;
        ansX = (p+q-(y1+y2)*ansY)/x;
        printf ("%.1f %.1f\n", ansX, ansY);
    }
    return 0;
}


/* //good solution
/////////////////////////////////////////////////////////////////////////
//平移操作
//   -     -     - -     -   -
//  | 1 0 p |   | x |   | x+p |
//  | 0 1 q | . | y | = | y+q |
//  | 0 0 1 |   | 1 |   |  1  |
//   -     -     - -     -   -
//
//缩放操作
//   -     -     - -     -   -
//  | L 0 0 |   | x |   | x*L |
//  | 0 L 0 | . | y | = | y*L |
//  | 0 0 1 |   | 1 |   |  1  |
//   -     -     - -     -   -
//
//上下翻转
//   -      -     - -     -  -
//  | 1  0 0 |   | x |   |  x |
//  | 0 -1 0 | . | y | = | -y |
//  | 0  0 1 |   | 1 |   |  1 |
//   -      -     - -     -  -
//
//左右翻转
//   -      -     - -     -  -
//  | -1 0 0 |   | x |   | -x |
//  |  0 1 0 | . | y | = |  y |
//  |  0 0 1 |   | 1 |   |  1 |
//   -      -     - -     -  -
//
//绕原点旋转
//   -                -     - -     -                 -
//  | cos(a) -sin(a) 0 |   | x |   | cos(a)*x-sin(a)*y |
//  | sin(a)  cos(a) 0 | . | y | = | sin(a)*x+cos(a)*y |
//  |     0       0  1 |   | 1 |   |         1         |
//   -                -     - -     -                 -
/////////////////////////////////////////////////////////////////////////
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#define PI acos(-1.0)

struct Matrix {
    double mat[3][3];
    Matrix() {
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < 3; i++)
            mat[i][i] = 1;
    }

    Matrix Multi(Matrix A, Matrix B) {
        Matrix res;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                res.mat[i][j] = 0;
                for(int k = 0; k < 3; k++) {
                    res.mat[i][j] = res.mat[i][j] + A.mat[i][k] * B.mat[k][j];
                }
            }
        }
        return res;
    }

    Matrix Translation(Matrix A, double p, double q) { //向上平移p个单位，向右平移q个单位
        Matrix res;
        res.mat[0][2] = p;
        res.mat[1][2] = q;
        return Multi(res, A);
    }

    Matrix Scale(Matrix A, double p) { //缩放p倍
        Matrix res;
        res.mat[0][0] = res.mat[1][1]  = p;
        return Multi(res, A);
    }

    Matrix Turn_UD(Matrix A) { //坐标轴上下翻转
        Matrix res;
        res.mat[1][1] = -1;
        return Multi(res, A);
    }

    Matrix Turn_LR(Matrix A) { //坐标轴左右翻转
        Matrix res;
        res.mat[0][0] = -1;
        return Multi(res, A);
    }

    Matrix Rotate(Matrix A, double angle) { //绕原点逆时针旋转angle角度
        double rad = angle / 180.0 * PI;
        Matrix res;
        res.mat[0][0] = cos(rad); res.mat[0][1] = -sin(rad);
        res.mat[1][0] = sin(rad); res.mat[1][1] = cos(rad);
        return Multi(res, A);
    }
};

struct Point {
    double x, y;
} P[10005];

int main() {
    int n, m;
    char op[5];
    double x, y;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%lf%lf", &P[i].x, &P[i].y);
    Matrix A;
    for(int i = 0; i < m; i++) {
        scanf("%s", op);
        if(op[0] == 'X') A = A.Turn_UD(A);
        else if(op[0] == 'Y') A = A.Turn_LR(A);
        else if(op[0] == 'M') {
            scanf("%lf%lf", &x, &y);
            A = A.Translation(A, x, y);
        }
        else if(op[0] == 'S') {
            scanf("%lf", &x);
            A = A.Scale(A, x);
        }
        else if(op[0] == 'R') {
            scanf("%lf", &x);
            A = A.Rotate(A, x);
        }
    }
    for(int i = 0; i < n; i++) {
        double xx = A.mat[0][0] * P[i].x + A.mat[0][1] * P[i].y + A.mat[0][2];
        double yy = A.mat[1][0] * P[i].x + A.mat[1][1] * P[i].y + A.mat[1][2];
        printf("%.1lf %.1lf\n", xx, yy);
    }
    return 0;
}
