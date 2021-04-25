#include "main.h"
#include "Math.hpp"

double Math::degToRad(double deg){
  return deg * M_PI / 180;
}

double Math::radToDeg(double rad){
  return rad * 180 / M_PI;
}

double Math::tickToInch(double tick){
  return tick * 2.75*M_PI / 360;
}

double Math::tickToInch(double tick, double rad, double ticksPerRotation){
  return tick * (rad * M_PI) / ticksPerRotation;
}


double Math::inchToTick(double inch){
  return (inch / (2.75*M_PI) * 360);
}

double Math::inchToTick(double inch, double rad, double ticksPerRotation){
  return inch / (rad * M_PI) * ticksPerRotation;
}

double Math::cubicControl(double power){
  return power * power * power / 16129;
}

Point2D Math::toPolar(Point2D cart){
  double mag = sqrt(cart.x * cart.x + cart.y * cart.y);
  double angle = atan2(cart.y, cart.y);

  return {mag, angle};
}

Point2D Math::toCart(Point2D polar){
  double mag = polar.x, angle = polar.y;
  return {mag * cos(angle), mag * sin(angle)};
}

double Math::wrapAngle360(double angle){
  return angle - 360.0 * (std::floor(angle * (1.0 / 360.0)));
}

double Math::wrapAngle180(double angle){
  return angle - 360.0 * std::floor((angle + 180.0) * (1.0 / 360.0));
}

double Math::wrapAngle90(double angle){
  angle = wrapAngle180(angle);
  return wrapAngle180(angle + (abs(angle) > 90) * 180);
}

double Math::linearVelToRPM(double linVel, double gearRatio, double radius){
  return (linVel / radius * 60 / (2*M_PI)) / gearRatio;
}

double Math::RPMToLinearVel(double rpm, double gearRatio, double radius){
  return (rpm * gearRatio) / 60 * 2 * M_PI * radius;
}

double Math::clamp(double val, double mn, double mx){
  val = fmax(mn, val);
  val = fmin(mx, val);

  return val;
}