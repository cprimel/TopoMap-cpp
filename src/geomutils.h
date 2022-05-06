#ifndef GEOMUTILS_H
#define GEOMUTILS_H

#include <vector>
#include <complex>

struct Point {
    double x{},y{};

    Point()= default;
    Point(double x, double y):x(x),y(y){}
};

typedef std::vector<Point> Polygon;

struct Vertex {
    Point p;
    int id{};
};

struct Component {
    std::vector<int> vertices;
    Polygon hull;
};

// Translate by (tx,ty) and then rotate around origin
struct Transformation {
    double tx, ty;
    double cos, sin;
};

inline double len(const Point &p) {return std::sqrt(p.x * p.x + p.y * p.y);};
inline double distance2(const Point &p1,const Point &p2) {
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
};

std::vector<int> sortEdges(const std::vector<std::pair<int, int>> &edges, const std::vector<double> &weights);
void findAngle(const Point &p1, const Point &p2, Transformation &t);
void computeConvexHull(Polygon &pts, Polygon &chull);

#endif // GEOMUTILS_H
