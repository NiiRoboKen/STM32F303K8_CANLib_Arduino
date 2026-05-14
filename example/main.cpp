#include "STM32F303K8_CAN.hpp"

STM32CAN can;

void setup(){
  Serial.begin(115200);
  if(can.begin(1000000, PA11_PA12)){
    Serial.println("CAN Initialized");
  } else {
    Serial.println("CAN Initialization Failed");
  }
}

void loop(){
  CAN_msg_t rx;
  if(can.receive(&rx)){
    Serial.println(rx.id, HEX);
  }

  /*
  CAN_msg_t msg;

  msg.id = 0x123;
  msg.format = STANDARD_FORMAT;
  msg.type = DATA_FRAME;
  msg.len = 1;
  msg.data[0] = 0x55;

  can.send(msg);
  delay(1000);
  Serial.println(CAN1->ESR, HEX);
  Serial.println(CAN1->TSR, HEX);
  delay(1000);
  */
}