#include "Nextion.h"
#include "NexNumber.h"
#include <DmxMaster.h>
#include <Wire.h>

uint32_t max_dmx = 0;
uint32_t dmx_ch = 1;
int ch_val = 0 ;
uint32_t slider_val = 0;
uint32_t page3n0val = 0;
uint32_t placeHolder = 0;
uint32_t placeHolder2 = 0;
int myval = 0;


void b2popCallback(void *ptr);
void n0PopCallback(void *ptr);
void n1PopCallback(void *ptr);
void b3pushCallback(void *ptr);
void b4pushCallback(void *ptr);
void h0PopCallback(void *ptr);
void pg1b0pushCallback(void *ptr);
void pg1b1pushCallback(void *ptr);
void pg1b3pushCallback(void *ptr);
void pg1b2pushCallback(void *ptr);
void pg1b4pushCallback(void *ptr);
void pg1b6pushCallback(void *ptr);
void pg1b5pushCallback(void *ptr);
void n99PopCallback(void *ptr);
void pg3b11popCallback(void *ptr);
void pg2b11popCallback(void *ptr);
void pg2b13popCallback (void *ptr);
void pg0b5popCallback(void *ptr);
void pg0b2popCallback(void *ptr);


/*
   Declare a button object [page id:0,component id:3, component name: "b1"].
*/

NexButton b2 = NexButton(0, 12, "b2");
NexNumber n0 = NexNumber(0, 3, "n0");
NexNumber n1 = NexNumber(0, 9, "n1");
NexButton b3 = NexButton(0, 13, "b3");
NexButton b4 = NexButton(0, 14, "b4");
NexSlider h0 = NexSlider(0, 15, "h0");
NexButton pg1b0 = NexButton(1, 1, "b0");
NexButton pg1b1 = NexButton(1, 2, "b1");
NexButton pg1b3 = NexButton(1, 4, "b3");
NexButton pg1b2 = NexButton(1, 3, "b2");
NexButton pg1b4 = NexButton(1, 5, "b4");
NexButton pg1b6 = NexButton(1, 7, "b6");
NexButton pg1b5 = NexButton(1, 6, "b5");
NexNumber n099 = NexNumber(3, 16, "n1");
NexButton pg3b11 = NexButton(3, 12, "b11");
NexButton pg2b11 = NexButton(2, 12, "b11");
NexButton pg2b13 = NexButton(2, 15, "b13");
NexButton pg0b5 = NexButton(0, 16, "b5");


char buffer[1000] = {0};

/*
   Register object t0, b0, b1, to the touch event list.
*/
NexTouch *nex_listen_list[] =
{
  &b2,
  &n0,
  &n1,
  &b3,
  &b4,
  &h0,
  &pg1b0,
  &pg1b1,
  &pg1b3,
  &pg1b2,
  &pg1b4,
  &pg1b6,
  &pg1b5,
  &n099,
  &pg3b11,
  &pg2b11,
  &pg2b13,
  &pg0b5,

  
  NULL
};

/*void b2pushCallback(void *ptr){
//	delay(80);
	n0.getValue(&max_dmx);
	n1.getValue(&dmx_ch);
  
}*/
void n0PopCallback(void *ptr)
{
	delay(80);
  dbSerialPrintln("n0PopCallback");
  n0.getValue(&max_dmx);
  dbSerialPrintln();
}
void n1PopCallback(void *ptr)
{

  dbSerialPrintln("n0PopCallback");
  n1.getValue(&dmx_ch);
  dbSerialPrintln();
}
void b3pushCallback(void *ptr)
{
  ch_val = 0;
  dbSerialPrint("channel val is:");
  dbSerialPrintln(ch_val);


}
void b4pushCallback(void *ptr)
{
  ch_val = 255;
  dbSerialPrint("channel val is:");
  dbSerialPrintln(ch_val);


}
void h0PopCallback(void *ptr)
{



  //dbSerialPrintln("h0PopCallback");
  h0.getValue(&slider_val);
  dbSerialPrint("slider value is:");
  dbSerialPrintln(slider_val);
  ch_val = (slider_val);
  dbSerialPrintln(ch_val);

}
void pg1b0pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to Obey 3 - 3CH");
  max_dmx = 3;

}
void pg1b1pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to Obey 4 - 16CH");
  max_dmx = 16;

}
void pg1b3pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to Obey 6 - 36CH");
  max_dmx = 36;

}
void pg1b2pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to Obey 10 - 128CH");
  max_dmx = 128;

}
void pg1b4pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to Obey 40 - 192H");
  max_dmx = 192;

}
void pg1b6pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to Obey 70 - 384");
  max_dmx = 384;

}
void pg1b5pushCallback(void *ptr)
{

  dbSerialPrint("Set Max DMX to SD 50 - 48");
  max_dmx = 48;

}
void pg3b11popCallback(void *ptr)
{
  n1.getValue(&placeHolder);
  dbSerialPrintln("*******************");
  n0.getValue(&placeHolder);
  dmx_ch = placeHolder;
  dbSerialPrint("Channel to test:");
  dbSerialPrintln(dmx_ch);
  dbSerialPrint("Max DMX is:");
  dbSerialPrintln(max_dmx);

  if (dmx_ch >= max_dmx) {
    dmx_ch = max_dmx;
    dbSerialPrintln("MAX!! set dmx_ch to max_dmx");
    dbSerialPrintln(dmx_ch);
  }
  if (dmx_ch <= 1) {
    
    dbSerialPrintln("Set dmx_ch to 1");
    dbSerialPrintln(dmx_ch);
  }

}
void pg2b11popCallback(void *ptr)
{
	delay(80);
	dbSerialPrintln("Get Other Max DMX Channels");
	n0.getValue(&max_dmx);	
}
void pg2b13popCallback(void *ptr)
{
	delay(80);
	dbSerialPrintln("Max DMX is 512");
	n0.getValue(&max_dmx);
}
void b2popCallback(void *ptr){
	
	dbSerialPrintln("setting previus ch to 0");
	dbSerialPrintln("CH UP");
	n1.getValue(&dmx_ch);
	dbSerialPrintln(dmx_ch);
	
}
void pg0b5popCallback(void *ptr){
	
	dbSerialPrintln("CH Down");
	n1.getValue(&dmx_ch);
	dbSerialPrintln(dmx_ch);
}



void setup(void)
{
  dbSerialPrintln("setup Started");
  /* Set the baudrate which is for debug and communicate with Nextion screen. */
  nexInit();


  /* Register the pop event callback function of the current button0 component. */
  b2.attachPop(b2popCallback);
  b3.attachPush(b3pushCallback);
  b4.attachPush(b4pushCallback);
  h0.attachPop(h0PopCallback);
  pg1b0.attachPush(pg1b0pushCallback);
  pg1b1.attachPush(pg1b1pushCallback);
  pg1b3.attachPush(pg1b3pushCallback);
  pg1b2.attachPush(pg1b2pushCallback);
  pg1b4.attachPush(pg1b4pushCallback);
  pg1b6.attachPush(pg1b6pushCallback);
  pg1b5.attachPush(pg1b5pushCallback);
  pg3b11.attachPop(pg3b11popCallback);
  pg2b11.attachPop(pg2b11popCallback);
  pg2b13.attachPop(pg2b13popCallback);
  pg0b5.attachPop(pg0b5popCallback);
  dbSerialPrintln("setup done");
  //dbSerialPrintln(dmx_ch);
}



void loop(void)
{
  /*
     When a pop or push event occured every time,
     the corresponding component[right page id and component id] in touch event list will be asked.
  */

  DmxMaster.maxChannel(max_dmx);
  DmxMaster.write(dmx_ch, ch_val);
  nexLoop(nex_listen_list);
}




