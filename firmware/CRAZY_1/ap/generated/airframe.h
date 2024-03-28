/* This file has been generated from /home/gautier/dev/paparazzi/conf/airframes/test_boards/crazyflie_2.1.xml */
/* Version v7.0_unstable-15-g5c1c35e859-dirty */
/* Please DO NOT EDIT */

#ifndef AIRFRAME_H
#define AIRFRAME_H

#define AIRFRAME_NAME "CRAZY_1"
#define AC_ID 31
#define MD5SUM ((uint8_t*)"\264\116\017\070\116\327\042\314\277\306\341\004\115\156\235\204")

#define COMMAND_ROLL 0
#define COMMAND_PITCH 1
#define COMMAND_YAW 2
#define COMMAND_THRUST 3
#define COMMANDS_NB 4
#define COMMANDS_FAILSAFE {0,0,0,0}


#define SERVOS_PWM_NB 5
#include "modules/actuators/actuators_pwm.h"

#define SERVO_FRONT_LEFT_DRIVER_NO 4
#define SERVO_FRONT_LEFT_IDX 0
#define SERVO_FRONT_LEFT_NEUTRAL 20
#define SERVO_FRONT_LEFT_TRAVEL_UP 0.0244791666667
#define SERVO_FRONT_LEFT_TRAVEL_UP_NUM 47
#define SERVO_FRONT_LEFT_TRAVEL_UP_DEN 1920
#define SERVO_FRONT_LEFT_TRAVEL_DOWN 0.00208333333333
#define SERVO_FRONT_LEFT_TRAVEL_DOWN_NUM 1
#define SERVO_FRONT_LEFT_TRAVEL_DOWN_DEN 480
#define SERVO_FRONT_LEFT_MAX 255
#define SERVO_FRONT_LEFT_MIN 0

#define SERVO_FRONT_RIGHT_DRIVER_NO 1
#define SERVO_FRONT_RIGHT_IDX 1
#define SERVO_FRONT_RIGHT_NEUTRAL 20
#define SERVO_FRONT_RIGHT_TRAVEL_UP 0.0244791666667
#define SERVO_FRONT_RIGHT_TRAVEL_UP_NUM 47
#define SERVO_FRONT_RIGHT_TRAVEL_UP_DEN 1920
#define SERVO_FRONT_RIGHT_TRAVEL_DOWN 0.00208333333333
#define SERVO_FRONT_RIGHT_TRAVEL_DOWN_NUM 1
#define SERVO_FRONT_RIGHT_TRAVEL_DOWN_DEN 480
#define SERVO_FRONT_RIGHT_MAX 255
#define SERVO_FRONT_RIGHT_MIN 0

#define SERVO_BACK_RIGHT_DRIVER_NO 2
#define SERVO_BACK_RIGHT_IDX 2
#define SERVO_BACK_RIGHT_NEUTRAL 20
#define SERVO_BACK_RIGHT_TRAVEL_UP 0.0244791666667
#define SERVO_BACK_RIGHT_TRAVEL_UP_NUM 47
#define SERVO_BACK_RIGHT_TRAVEL_UP_DEN 1920
#define SERVO_BACK_RIGHT_TRAVEL_DOWN 0.00208333333333
#define SERVO_BACK_RIGHT_TRAVEL_DOWN_NUM 1
#define SERVO_BACK_RIGHT_TRAVEL_DOWN_DEN 480
#define SERVO_BACK_RIGHT_MAX 255
#define SERVO_BACK_RIGHT_MIN 0

#define SERVO_BACK_LEFT_DRIVER_NO 3
#define SERVO_BACK_LEFT_IDX 3
#define SERVO_BACK_LEFT_NEUTRAL 20
#define SERVO_BACK_LEFT_TRAVEL_UP 0.0244791666667
#define SERVO_BACK_LEFT_TRAVEL_UP_NUM 47
#define SERVO_BACK_LEFT_TRAVEL_UP_DEN 1920
#define SERVO_BACK_LEFT_TRAVEL_DOWN 0.00208333333333
#define SERVO_BACK_LEFT_TRAVEL_DOWN_NUM 1
#define SERVO_BACK_LEFT_TRAVEL_DOWN_DEN 480
#define SERVO_BACK_LEFT_MAX 255
#define SERVO_BACK_LEFT_MIN 0

static inline int get_servo_min_PWM(int _idx) {
  switch (_idx) {
    case SERVO_FRONT_LEFT_DRIVER_NO: return SERVO_FRONT_LEFT_MIN;
    case SERVO_FRONT_RIGHT_DRIVER_NO: return SERVO_FRONT_RIGHT_MIN;
    case SERVO_BACK_RIGHT_DRIVER_NO: return SERVO_BACK_RIGHT_MIN;
    case SERVO_BACK_LEFT_DRIVER_NO: return SERVO_BACK_LEFT_MIN;
    default: return 0;
  };
}

static inline int get_servo_max_PWM(int _idx) {
  switch (_idx) {
    case SERVO_FRONT_LEFT_DRIVER_NO: return SERVO_FRONT_LEFT_MAX;
    case SERVO_FRONT_RIGHT_DRIVER_NO: return SERVO_FRONT_RIGHT_MAX;
    case SERVO_BACK_RIGHT_DRIVER_NO: return SERVO_BACK_RIGHT_MAX;
    case SERVO_BACK_LEFT_DRIVER_NO: return SERVO_BACK_LEFT_MAX;
    default: return 0;
  };
}

static inline int get_servo_idx_PWM(int _idx) {
  switch (_idx) {
    case SERVO_FRONT_LEFT_DRIVER_NO: return SERVO_FRONT_LEFT_IDX;
    case SERVO_FRONT_RIGHT_DRIVER_NO: return SERVO_FRONT_RIGHT_IDX;
    case SERVO_BACK_RIGHT_DRIVER_NO: return SERVO_BACK_RIGHT_IDX;
    case SERVO_BACK_LEFT_DRIVER_NO: return SERVO_BACK_LEFT_IDX;
    default: return 0;
  };
}


#define SECTION_MIXING 1
#define MOTOR_MIXING_TYPE QUAD_X

#define Set_BACK_RIGHT_Servo(_v) { \
  actuators[SERVO_BACK_RIGHT_IDX] = Clip(_v, SERVO_BACK_RIGHT_MIN, SERVO_BACK_RIGHT_MAX); \
  ActuatorPwmSet(SERVO_BACK_RIGHT_DRIVER_NO, actuators[SERVO_BACK_RIGHT_IDX]); \
}

#define Set_FRONT_LEFT_Servo(_v) { \
  actuators[SERVO_FRONT_LEFT_IDX] = Clip(_v, SERVO_FRONT_LEFT_MIN, SERVO_FRONT_LEFT_MAX); \
  ActuatorPwmSet(SERVO_FRONT_LEFT_DRIVER_NO, actuators[SERVO_FRONT_LEFT_IDX]); \
}

#define Set_BACK_LEFT_Servo(_v) { \
  actuators[SERVO_BACK_LEFT_IDX] = Clip(_v, SERVO_BACK_LEFT_MIN, SERVO_BACK_LEFT_MAX); \
  ActuatorPwmSet(SERVO_BACK_LEFT_DRIVER_NO, actuators[SERVO_BACK_LEFT_IDX]); \
}

#define Set_FRONT_RIGHT_Servo(_v) { \
  actuators[SERVO_FRONT_RIGHT_IDX] = Clip(_v, SERVO_FRONT_RIGHT_MIN, SERVO_FRONT_RIGHT_MAX); \
  ActuatorPwmSet(SERVO_FRONT_RIGHT_DRIVER_NO, actuators[SERVO_FRONT_RIGHT_IDX]); \
}

#define ACTUATORS_NB 4

#define AllActuatorsInit() { \
  ActuatorsPwmInit();\
}

#define AllActuatorsCommit() { \
  ActuatorsPwmCommit();\
}

#define SetActuatorsFromCommands(values, AP_MODE) { \
  int32_t servo_value;\
  int32_t command_value;\
\
  motor_mixing_run(autopilot.motors_on,FALSE,values); \
\
  command_value = motor_mixing.commands[MOTOR_FRONT_LEFT]; \
  command_value *= command_value>0 ? SERVO_FRONT_LEFT_TRAVEL_UP_NUM : SERVO_FRONT_LEFT_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_FRONT_LEFT_TRAVEL_UP_DEN : SERVO_FRONT_LEFT_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_FRONT_LEFT_NEUTRAL + command_value; \
  Set_FRONT_LEFT_Servo(servo_value); \
\
  command_value = motor_mixing.commands[MOTOR_FRONT_RIGHT]; \
  command_value *= command_value>0 ? SERVO_FRONT_RIGHT_TRAVEL_UP_NUM : SERVO_FRONT_RIGHT_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_FRONT_RIGHT_TRAVEL_UP_DEN : SERVO_FRONT_RIGHT_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_FRONT_RIGHT_NEUTRAL + command_value; \
  Set_FRONT_RIGHT_Servo(servo_value); \
\
  command_value = motor_mixing.commands[MOTOR_BACK_RIGHT]; \
  command_value *= command_value>0 ? SERVO_BACK_RIGHT_TRAVEL_UP_NUM : SERVO_BACK_RIGHT_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_BACK_RIGHT_TRAVEL_UP_DEN : SERVO_BACK_RIGHT_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_BACK_RIGHT_NEUTRAL + command_value; \
  Set_BACK_RIGHT_Servo(servo_value); \
\
  command_value = motor_mixing.commands[MOTOR_BACK_LEFT]; \
  command_value *= command_value>0 ? SERVO_BACK_LEFT_TRAVEL_UP_NUM : SERVO_BACK_LEFT_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_BACK_LEFT_TRAVEL_UP_DEN : SERVO_BACK_LEFT_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_BACK_LEFT_NEUTRAL + command_value; \
  Set_BACK_LEFT_Servo(servo_value); \
\
  AllActuatorsCommit(); \
}

#define SECTION_IMU 1
#define IMU_ACCEL_X_NEUTRAL -19
#define IMU_ACCEL_Y_NEUTRAL -12
#define IMU_ACCEL_Z_NEUTRAL 58
#define IMU_ACCEL_X_SENS 1.83754430011
#define IMU_ACCEL_X_SENS_NUM 16073
#define IMU_ACCEL_X_SENS_DEN 8747
#define IMU_ACCEL_Y_SENS 1.8445793586
#define IMU_ACCEL_Y_SENS_NUM 10634
#define IMU_ACCEL_Y_SENS_DEN 5765
#define IMU_ACCEL_Z_SENS 1.84794644385
#define IMU_ACCEL_Z_SENS_NUM 65421
#define IMU_ACCEL_Z_SENS_DEN 35402
#define IMU_BODY_TO_IMU_PHI 0.
#define IMU_BODY_TO_IMU_THETA 0.
#define IMU_BODY_TO_IMU_PSI 0.

#define SECTION_AHRS 1
#define AHRS_H_X 0.3770441
#define AHRS_H_Y 0.0193986
#define AHRS_H_Z 0.9259921
#define AHRS_USE_GPS_HEADING 1
#define AHRS_HEADING_UPDATE_GPS_MIN_SPEED 0

#define SECTION_INS 1

#define SECTION_STABILIZATION_RATE 1
#define STABILIZATION_RATE_SP_MAX_P 10000
#define STABILIZATION_RATE_SP_MAX_Q 10000
#define STABILIZATION_RATE_SP_MAX_R 10000
#define STABILIZATION_RATE_DEADBAND_P 20
#define STABILIZATION_RATE_DEADBAND_Q 20
#define STABILIZATION_RATE_DEADBAND_R 200
#define STABILIZATION_RATE_REF_TAU 4
#define STABILIZATION_RATE_GAIN_P 400
#define STABILIZATION_RATE_GAIN_Q 400
#define STABILIZATION_RATE_GAIN_R 350
#define STABILIZATION_RATE_IGAIN_P 75
#define STABILIZATION_RATE_IGAIN_Q 75
#define STABILIZATION_RATE_IGAIN_R 50
#define STABILIZATION_RATE_DDGAIN_P 300
#define STABILIZATION_RATE_DDGAIN_Q 300
#define STABILIZATION_RATE_DDGAIN_R 300

#define SECTION_STABILIZATION_ATTITUDE 1
#define STABILIZATION_ATTITUDE_SP_MAX_PHI 0.7853981625
#define STABILIZATION_ATTITUDE_SP_MAX_THETA 0.7853981625
#define STABILIZATION_ATTITUDE_SP_MAX_R 1.570796325
#define STABILIZATION_ATTITUDE_DEADBAND_A 0
#define STABILIZATION_ATTITUDE_DEADBAND_E 0
#define STABILIZATION_ATTITUDE_DEADBAND_R 250
#define STABILIZATION_ATTITUDE_REF_OMEGA_P 6.981317
#define STABILIZATION_ATTITUDE_REF_ZETA_P 0.85
#define STABILIZATION_ATTITUDE_REF_MAX_P 6.981317
#define STABILIZATION_ATTITUDE_REF_MAX_PDOT RadOfDeg(8000.)
#define STABILIZATION_ATTITUDE_REF_OMEGA_Q 6.981317
#define STABILIZATION_ATTITUDE_REF_ZETA_Q 0.85
#define STABILIZATION_ATTITUDE_REF_MAX_Q 6.981317
#define STABILIZATION_ATTITUDE_REF_MAX_QDOT RadOfDeg(8000.)
#define STABILIZATION_ATTITUDE_REF_OMEGA_R 4.363323125
#define STABILIZATION_ATTITUDE_REF_ZETA_R 0.85
#define STABILIZATION_ATTITUDE_REF_MAX_R 3.14159265
#define STABILIZATION_ATTITUDE_REF_MAX_RDOT RadOfDeg(1800.)
#define STABILIZATION_ATTITUDE_PHI_PGAIN 300
#define STABILIZATION_ATTITUDE_PHI_DGAIN 200
#define STABILIZATION_ATTITUDE_PHI_IGAIN 100
#define STABILIZATION_ATTITUDE_THETA_PGAIN 300
#define STABILIZATION_ATTITUDE_THETA_DGAIN 200
#define STABILIZATION_ATTITUDE_THETA_IGAIN 100
#define STABILIZATION_ATTITUDE_PSI_PGAIN 400
#define STABILIZATION_ATTITUDE_PSI_DGAIN 200
#define STABILIZATION_ATTITUDE_PSI_IGAIN 10
#define STABILIZATION_ATTITUDE_PHI_DDGAIN 300
#define STABILIZATION_ATTITUDE_THETA_DDGAIN 300
#define STABILIZATION_ATTITUDE_PSI_DDGAIN 300

#define SECTION_STABILIZATION_ATTITUDE_INDI 1
#define STABILIZATION_INDI_G1_P 0.0034724f
#define STABILIZATION_INDI_G1_Q 0.0052575f
#define STABILIZATION_INDI_G1_R -0.0015942f
#define STABILIZATION_INDI_G2_R -0.11281f
#define STABILIZATION_INDI_REF_ERR_P 3.57f
#define STABILIZATION_INDI_REF_ERR_Q 3.57f
#define STABILIZATION_INDI_REF_ERR_R 3.57f
#define STABILIZATION_INDI_REF_RATE_P 14.0
#define STABILIZATION_INDI_REF_RATE_Q 14.0
#define STABILIZATION_INDI_REF_RATE_R 14.0
#define STABILIZATION_INDI_FILT_CUTOFF 8.0f
#define STABILIZATION_INDI_FILT_CUTOFF_RDOT 8.0f
#define STABILIZATION_INDI_ACT_FREQ_P 16.4
#define STABILIZATION_INDI_ACT_FREQ_Q 16.4
#define STABILIZATION_INDI_ACT_FREQ_R 16.4
#define STABILIZATION_INDI_USE_ADAPTIVE FALSE
#define STABILIZATION_INDI_ADAPTIVE_MU 0.0001

#define SECTION_GUIDANCE_V 1
#define GUIDANCE_V_HOVER_KP 150
#define GUIDANCE_V_HOVER_KD 80
#define GUIDANCE_V_HOVER_KI 20
#define GUIDANCE_V_NOMINAL_HOVER_THROTTLE 0.75

#define SECTION_GUIDANCE_H 1
#define GUIDANCE_H_MAX_BANK 0.34906585
#define GUIDANCE_H_PGAIN 50
#define GUIDANCE_H_DGAIN 100
#define GUIDANCE_H_AGAIN 70
#define GUIDANCE_H_IGAIN 20

#define SECTION_SIMULATOR 1
#define NPS_ACTUATOR_NAMES { "nw_motor" , "ne_motor" , "se_motor" , "sw_motor" }
#define NPS_JSBSIM_MODEL "simple_x_quad_ccw"

#define SECTION_AUTOPILOT 1
#define MODE_STARTUP AP_MODE_NAV
#define MODE_MANUAL AP_MODE_ATTITUDE_DIRECT
#define MODE_AUTO1 AP_MODE_ATTITUDE_Z_HOLD
#define MODE_AUTO2 AP_MODE_NAV

#define SECTION_BAT 1
#define CATASTROPHIC_BAT_LEVEL 3.1
#define CRITIC_BAT_LEVEL 3.3
#define LOW_BAT_LEVEL 3.6
#define MAX_BAT_LEVEL 4.2


#endif // AIRFRAME_H
