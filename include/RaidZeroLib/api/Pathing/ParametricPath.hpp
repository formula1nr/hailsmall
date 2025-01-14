#pragma once
#include "RaidZeroLib/api/Pathing/DiscretePath.hpp"

namespace rz {
using namespace okapi;

class ParametricPath {
    public:
    virtual QLength getX(double t) const;

    virtual QLength getY(double t) const;

    virtual QLength getdX(double t) const;

    virtual QLength getdY(double t) const;

    virtual QLength getddX(double t) const;

    virtual QLength getddY(double t) const;

    virtual Point getPoint(double t) const = 0;

    virtual Point getVelocity(double t) const = 0;

    virtual Point getAcceleration(double t) const = 0;

    virtual Rotation getTheta(double t) const;

    virtual QCurvature getCurvature(double t) const;

    virtual QLength getLength(double tStart = 0, double tEnd = 1) const;

    virtual DiscretePath toDiscrete(int numSegments, bool end = true) const;

    virtual DiscretePath toDiscrete(QLength distance, bool end = true) const;

    virtual double stepT(double t, QLength distance) const;
};

} // namespace rz