#include "main.h"
#include "lib4253/Controller/PurePursuit.hpp"

PurePursuitFollower::PurePursuitFollower(){

}

void PurePursuitFollower::generateVelocity(){
    std::vector<double> curvature = path.getCurvature();
    std::vector<Point2D> waypoint = path.getWaypoint();
    for(int i = 0; i < curvature.size(); i++){
        velocity.push_back(fmin(maxVelocity, kT / curvature[i]));
    }

    velocity[velocity.size()-1] = 0;

    for(int i = velocity.size()-2; i >= 0; i--){
        double dist = waypoint[i].distanceTo(waypoint[i+1]);
        velocity[i] = fmin(velocity[i], sqrt(velocity[i+1]*velocity[i+1] + 2 * maxAcceleration * dist));
    }

}

void PurePursuitFollower::initialize(){

}

void PurePursuitFollower::closestPoint(Point2D currentPos){
    std::vector<Point2D> waypoint = path.getWaypoint();

    double minDist = currentPos.distanceTo(waypoint[prevClosestPt]);
    double minIndex = prevClosestPt;

    for(int i = prevClosestPt; i < waypoint.size(); i++){
        double dist = currentPos.distanceTo(waypoint[i]);
        if(dist < minDist){
          minDist = dist;
          minIndex = i;
        }
    }

    closestPt = minIndex;
}

Point2D PurePursuitFollower::lookAhead(){
  Point2D start = path.getWaypoint(closestPt);
  Point2D end = path.getWaypoint(closestPt+1);
}

void PurePursuitFollower::followPath(SimplePath p){
    path = p;
    generateVelocity();
}

void PurePursuitFollower::setTurnGain(double k){
    kT = k;
}

void PurePursuitFollower::setKinematics(double v, double a){
    maxVelocity = v;
    maxAcceleration = a;
}

void PurePursuitFollower::setGain(double v, double a, double p){
    kV = v; kA = a; kP = p;
}
