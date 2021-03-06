/*
 * compute_hit.h
 */
#ifndef _COMPUTE_HIT_H
#define _COMPUTE_HIT_H

/*
 *  Local Structures
 */
struct sensor
{
  unsigned int index;   // Which sensor is this one.
  bool   is_valid;      // TRUE if the sensor contains a valid time
  double angle_A;       // Angle to be computed
  double diagonal;      // Diagonal angle to next sensor (45')
  double x;             // Sensor Location (X us)
  double y;             // Sensor Location (Y us)
  double count;         // Working timer value
  double a, b, c;       // Working dimensions
  double xs;            // Computed X shot value
  double ys;            // Computed Y shot value
};

typedef struct sensor sensor_t;

/*
 *  Public Funcitons
 */
void init_sensors(void);                                    // Initialize sensor structure
unsigned int compute_hit(unsigned int shot, history_t* h);  // Find the location of the shot
void send_score(history_t* h, double s_of_sound);           // Send the shot
void rotate_hit(unsigned int location, history_t* h);       // Rotate the shot back into the correct quadrant
void find_xy(sensor_t* s, double estimate);                 // Estimated position   

#endif

