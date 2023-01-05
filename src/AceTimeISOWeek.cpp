#include "AceTimeISOWeek.h"

// useful for displaying the ISO8601 WeekNumber on a clock that runs with EpochSeconds. 
// range EpochYear ± 50, depending on datelibrary settings in AceTime.
// Heavy calculation, do only once each new minute
uint8_t EpochTimeToISOWeek(acetime_t EpochSeconds_I) {                              // range [1..53]
  return EpochDaysToISOWeek(LocalDate::forEpochSeconds(EpochSeconds_I).toEpochDays());  //convert DateTime to Date, then ISOWeek
}


// useful for displaying the ISO8601 WeekNumber on a clock that runs with EpochDays.
uint8_t EpochDaysToISOWeek(int32_t EpochDays_I) {                                                          // range [1..53]
  return ISOYearDayToISOWeek(EpochToISOYearDay(EpochDays_I, (JanFour(EpochToISOYear(EpochDays_I)))));  //convert Date to ISOWeek
}


// This is the most important formula for a correct calculation, needs validation for each date library !!
// convert Date to ISO8601 WeekDay number, range [Mon=1]..[Sun=7].
uint8_t EpochToISOWeekDay(int32_t EpochDays_I) {
  uint8_t ISOWeekDay_I = (LocalDate::forEpochDays(EpochDays_I).dayOfWeek());
  // Correct the output, if needed for used date library, here  
  return ISOWeekDay_I;
}

// Year for closest Thursday
int16_t EpochToISOYear(int32_t EpochDays_I) {
  return (LocalDate::forEpochDays(EpochDays_I - EpochToISOWeekDay(EpochDays_I) + 4).year());
}

// Date for Jan-04, Internally only
int32_t JanFour(int16_t ISOYear_I) {  // Jan-04-ISOYear
  return (LocalDate::forComponents(ISOYear_I, 1, 4).toEpochDays());
}

// Day number in de ISOYear, Internally only, range [0..370]
int16_t EpochToISOYearDay(int32_t EpochDays_I, int32_t JanFour_I) {
  return (EpochDays_I - JanFour_I + EpochToISOWeekDay(JanFour_I) - 1);
}

// Convert Day number in de ISOYear to ISOWeek number, range [1..53]
uint8_t ISOYearDayToISOWeek(int16_t ISOYearDay_I) {
  return ((ISOYearDay_I / 7) + 1);
}

// reverse calculation, normally not used in a clock :)
// ISODay format 2023-W01-2
int32_t ISODayToEpoch(int16_t ISOYear_I, uint8_t ISOWeek_I, uint8_t ISOWeekDay_I) {
  return (ISODayToISOYearDay(ISOWeek_I, ISOWeekDay_I) + JanFour(ISOYear_I) - EpochToISOWeekDay(JanFour(ISOYear_I)) + 1);
}

// Day number in de ISOYear, reverse Internally only, range [0..370]
int16_t ISODayToISOYearDay(uint8_t ISOWeek_I, uint8_t ISOWeekday_I) {
  return (((ISOWeek_I - 1) * 7) + ISOWeekday_I - 1);
}

// return 52 or 53 for input validation, not implemented yet, Internally only
uint8_t MaxISOWeek(int16_t ISOYear_I) {  // 28-dec-ISOYear
  return EpochToISOWeek(LocalDate::forComponents(ISOYear_I, 12, 28).toEpochDays());
}

//End
