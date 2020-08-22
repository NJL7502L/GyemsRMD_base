#ifndef GyemsRMD_base_h
#define GyemsRMD_base_h

#include <Arduino.h>
#include <MyMath.h>

class GyemsRMD_base {
  MyMath myMath;

  struct ClassifiedDatas {
    struct {
      struct {
        uint8_t kp, ki;
      } position, speed, torque;
    } pid;
    struct {
      uint8_t current[4], target[4];
    } accel;
    struct {
      uint8_t current[2], original[2], offset[2];
    } encoder;
    struct {
      uint8_t multiTurn[8];
      uint8_t singleTurn[2];
    } angle;
    struct {
      uint8_t temperature;
      uint8_t voltage[2];
      uint8_t errorState;
    } information;
    struct {
      uint8_t iq[2];
    } current;
    struct {
      uint8_t current[2];
    } speed;
  } classifiedDatas;

  int canClassify(uint8_t data[8]);
  int format();

public:
  struct RMDreplies {
    struct {
      struct {
        uint8_t kp, ki;
      } position, speed, torque;
    } pid;
    struct {
      int32_t current, target; // 1 dps/s
    } accel;
    struct {
      double current, original, offset;
      double multiTurn; // deg
    } angle;
    struct {
      uint8_t temperature;
      uint8_t voltage[2];
      uint8_t errorState;
    } information;
    struct {
      uint8_t iq[2];
    } current;
    struct {
      uint8_t current[2];
    } speed;
  } replies;
  int canEncode(uint8_t data[8]) {
    canClassify(data);
    format();
  };
};

#endif
