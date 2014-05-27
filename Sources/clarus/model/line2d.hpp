#ifndef CLARUS_MODEL_LINE_HPP
#define CLARUS_MODEL_LINE_HPP

#include <clarus/core/list.hpp>
#include <clarus/model/point.hpp>

namespace clarus {
    class Line2D;
}

class clarus::Line2D {
    /* Slope of line. */
    double a;

    /* Y-intercept of line. */
    double b;

    /* Angle of line. */
    double t;

public:
    Line2D();

    /*
    Creates a new line passing through the given points. If the horizontal distance
    between the points is less than dx, the points are assumed to be over a vertical
    line.
    */
    Line2D(const Point &p0, const Point &p1, double dx = 1.0);

    /*
    Virtual destrcutor. Enforces polymorphism. Do not remove.
    */
    virtual ~Line2D();

    double operator () (double x) const;

    /*
    Fits this line to pass through the given points. If the horizontal distance
    between the points is less than dx, the points are assumed to be over a vertical
    line.
    */
    void fit(const Point &p0, const Point &p1, double dx = 1.0);

    double angle() const;

    double intercept() const;

    double slope() const;
};

namespace clarus {
    double distance(const Line2D &line, const Point &point);

    double distance(const Line2D &l0, const Line2D &l1);
}

#endif
