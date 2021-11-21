#include "SPI.h"
#include "epd4in2/epd4in2.h"
#include "epd4in2/epdpaint.h"
#include "epd4in2/imagedata.h"

#define WHITE 0
#define BLACK 1

void setup() 
{
  // put your setup code here, to run once:
    Serial.begin(115200);

    Epd ePaperDisplay;

    ePaperDisplay.Init();
    ePaperDisplay.ClearFrame();

    
    unsigned char fBuffer[EPD_WIDTH * EPD_HEIGHT / 8];

    Paint ePaint(fBuffer,EPD_WIDTH,EPD_HEIGHT);

    // Fill Back Data at Frame Buffer
    ePaint.Clear(BLACK);
    // Sent Farame Buffer Data into SRAM in Display
    ePaperDisplay.SetPartialWindow(ePaint.GetImage(),0,0,ePaint.GetWidth(),ePaint.GetHeight());
    
    // This displays data on SRAM 
    ePaperDisplay.DisplayFrame();
}

void loop() 
{
  // put your main code here, to run repeatedly:

}\\