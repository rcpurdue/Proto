// proto.cpp, rcampbel@purdue.edu, 2023-03-08
// https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts

#include "Proto.h"
#include "NIOBRG__30pt7b.h"

#define START  46
#define OFFSET 51

void Proto::drawWatchFace(){
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&NIOBRG__30pt7b);

    int row = START;

    // 12-hour A/PM
    display.setCursor(1, row);
    int displayHour = ((currentTime.Hour+11)%12)+1;
    display.print(currentTime.Hour < 10 ? "   " : "  ");
    display.print(displayHour);
    display.print(" ");
    display.print(currentTime.Hour < 12 ? " AM" : "PM");

    // 24-hour:Minute
    row += OFFSET;
    display.setCursor(1, row); // +4
    display.print(currentTime.Hour);
    display.print(":");
    display.println(currentTime.Minute);

    // MonthNum/Year
    row += OFFSET;
    display.setCursor(1, row); // +8
    display.print(currentTime.Month < 10 ? " " : "");
    display.print(currentTime.Month);
    display.print("/");
    display.print(tmYearToCalendar(currentTime.Year));  // .Year in uint8_t as offset from 1970

    // ShortMonth. Day
    row += OFFSET;
    display.setCursor(1, row); // +12
    display.print(monthShortStr(currentTime.Month));
    display.print(". ");
    display.print(currentTime.Day);
}
