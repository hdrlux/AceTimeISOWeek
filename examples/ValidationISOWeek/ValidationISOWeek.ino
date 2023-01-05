/* Generates CSV format for data validation purposes.
 * Capture output from COM to LOG file.
 *
 */


#include <AceTimeISOWeek.h>  // https://github.com/hdrlux/AceTimeISOWeek

// Startyear for validation
int16_t Year = 2020;
int32_t DateNumber = LocalDate::forComponents(Year, 1, 1).toEpochDays();

void setup() {           //do only once
  Serial.begin(115200);  // Set Serial Monitor to same speed
  Serial.println();      //clean-up buffer
  Serial.println("Validation CSV for ISO8601 Week Number");
}

void loop() {
  serialprint(DateNumber);
  DateNumber++;
}


void serialprint(int32_t EpochDayI) {
  LocalDate now = LocalDate::forEpochDays(EpochDayI);
  char DateBuf[30];  //date string buffer
  sprintf(DateBuf, "%d, %.2d-%.2d-%d ",
          now.dayOfWeek(), now.day(), now.month(), now.year());
  Serial.print(DateBuf);
  Serial.print(", ");
  Serial.print(DateNumber);
  Serial.print(", ");
  char ISOBuf[30];  //date string buffer
  sprintf(ISOBuf, "%d-W%.2d-%d ",
          EpochToISOYear(DateNumber), EpochDaysToISOWeek(DateNumber), EpochToISOWeekDay(DateNumber));
  Serial.print(ISOBuf);
  Serial.print(", ");
  // example below uses output as input in a circulair way
  Serial.print(ISODayToEpoch(EpochToISOYear(DateNumber), EpochDaysToISOWeek(DateNumber), EpochToISOWeekDay(DateNumber)));
  Serial.print(", ");
  Serial.print(MaxISOWeek(EpochToISOYear(DateNumber)));
  Serial.println();
}
/* LOG example

*/
//End