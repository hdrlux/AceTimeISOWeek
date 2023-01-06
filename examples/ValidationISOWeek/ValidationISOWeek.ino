/* Generates CSV format for data validation purposes.
 * Capture output from COM to LOG file.
 *
 */


#include <AceTimeISOWeek.h>  // https://github.com/hdrlux/AceTimeISOWeek

// Startyear for validation
int16_t Year = 2021;
int32_t DateNumber = LocalDate::forComponents(Year, 1, 1).toEpochDays();

void setup() {           //do only once
  Serial.begin(115200);  // Set Serial Monitor to same speed
  Serial.println();      //clean-up buffer
  Serial.println("Validation CSV for ISO8601 Week Number");
  Serial.println("DayOfWeek, dd-mm-yyyy, EpochDay, ISOYear-ISOWeek-ISODayOfWeek, reverse-EpochDay, MaxISOWeek");
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
Validation CSV for ISO8601 Week Number
DayOfWeek, dd-mm-yyyy, EpochDay, ISOYear-ISOWeek-ISODayOfWeek, reverse-EpochDay, MaxISOWeek
5, 01-01-2021 , -10592, 2020-W53-5 , -10592, 53
6, 02-01-2021 , -10591, 2020-W53-6 , -10591, 53
7, 03-01-2021 , -10590, 2020-W53-7 , -10590, 53
1, 04-01-2021 , -10589, 2021-W01-1 , -10589, 52
2, 05-01-2021 , -10588, 2021-W01-2 , -10588, 52
3, 06-01-2021 , -10587, 2021-W01-3 , -10587, 52
4, 07-01-2021 , -10586, 2021-W01-4 , -10586, 52
5, 08-01-2021 , -10585, 2021-W01-5 , -10585, 52
6, 09-01-2021 , -10584, 2021-W01-6 , -10584, 52
7, 10-01-2021 , -10583, 2021-W01-7 , -10583, 52
*/
//End
