#ifndef PID_HPP
#define PID_HPP 

/*
 * Example functions for getting and setting controller data, no need to implement
 */
double getHeight();
void setThrust(double);

/*
 * In real life, these constants can be tuned, but they don't need to for the purpose of this assignment
 * kp = proportional constant, ki = integral constant, kd = derivative constant
 */
static const double KP = 1.0;
static const double KI = 1.0;
static const double KD = 1.0;

#endif
