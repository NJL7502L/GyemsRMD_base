#include <GyemsRMD_base.h>

int GyemsRMD_base::canClassify(uint8_t data[8]) {
  switch (data[0]) {
  case 0x30:
  case 0x31:
  case 0x32:
    classifiedDatas.pid.position.kp = data[2];
    classifiedDatas.pid.position.ki = data[3];
    classifiedDatas.pid.speed.kp = data[4];
    classifiedDatas.pid.speed.ki = data[5];
    classifiedDatas.pid.torque.kp = data[6];
    classifiedDatas.pid.torque.ki = data[7];
    break;
  case 0x33:
    classifiedDatas.accel.current[0] = data[4];
    classifiedDatas.accel.current[1] = data[5];
    classifiedDatas.accel.current[2] = data[6];
    classifiedDatas.accel.current[3] = data[7];
    break;
  case 0x34:
    classifiedDatas.accel.target[0] = data[4];
    classifiedDatas.accel.target[1] = data[5];
    classifiedDatas.accel.target[2] = data[6];
    classifiedDatas.accel.target[3] = data[7];
    break;
  case 0x90:
    classifiedDatas.encoder.current[0] = data[2];
    classifiedDatas.encoder.current[1] = data[3];
    classifiedDatas.encoder.original[0] = data[4];
    classifiedDatas.encoder.original[1] = data[5];
    classifiedDatas.encoder.offset[0] = data[6];
    classifiedDatas.encoder.offset[1] = data[7];
    break;
  case 0x91:
  case 0x19:
    classifiedDatas.encoder.offset[0] = data[6];
    classifiedDatas.encoder.offset[1] = data[7];
    break;
  case 0x92:
    classifiedDatas.angle.multiTurn[0] = data[1];
    classifiedDatas.angle.multiTurn[1] = data[2];
    classifiedDatas.angle.multiTurn[2] = data[3];
    classifiedDatas.angle.multiTurn[3] = data[4];
    classifiedDatas.angle.multiTurn[4] = data[5];
    classifiedDatas.angle.multiTurn[5] = data[6];
    classifiedDatas.angle.multiTurn[6] = data[7];
    classifiedDatas.angle.multiTurn[7] = 0;
    break;
  case 0x94:
    classifiedDatas.angle.singleTurn[0] = data[6];
    classifiedDatas.angle.singleTurn[1] = data[7];
    break;
  case 0x9A:
    classifiedDatas.information.temperature = data[1];
    classifiedDatas.information.voltage[0] = data[3];
    classifiedDatas.information.voltage[1] = data[4];
    classifiedDatas.information.errorState = data[7];
    break;
  case 0x9C:
    classifiedDatas.information.temperature = data[1];
    classifiedDatas.current.iq[0] = data[2];
    classifiedDatas.current.iq[1] = data[3];
    classifiedDatas.speed.current[0] = data[4];
    classifiedDatas.speed.current[1] = data[5];
    classifiedDatas.encoder.current[0] = data[6];
    classifiedDatas.encoder.current[1] = data[7];
    break;
  case 0x9D:

    break;
  default:
    break;
  }
}

int GyemsRMD_base::format(){

};