/*
 * MIT License
 * Copyright (c) 2023 No Name https://github.com/hdrlux/AceTimeISOWeek
 * v0.1 2023-01
 * output validated for Year 2020-2100, code could use some optimization
 */

#ifndef ACETIME_ISOWEEK_H
#define ACETIME_ISOWEEK_H

#include <Arduino.h>
#include <AceTime.h>  // https://github.com/bxparks/AceTime
using namespace ace_time;

uint8_t EpochTimeToISOWeek(acetime_t EpochSeconds_I);
uint8_t EpochDaysToISOWeek(int32_t EpochDays_I);
uint8_t EpochToISOWeekDay(int32_t EpochDays_I);
int16_t EpochToISOYear(int32_t EpochDays_I);
int32_t JanFour(int16_t ISOYear_I);
int16_t EpochToISOYearDay(int32_t EpochDays_I, int32_t JanFour_I);
uint8_t ISOYearDayToISOWeek(int16_t ISOYearDay_I);
int32_t ISODayToEpoch(int16_t ISOYear_I, uint8_t ISOWeek_I, uint8_t ISOWeekDay_I);
int16_t ISODayToISOYearDay(uint8_t ISOWeek_I, uint8_t ISOWeekday_I);
uint8_t MaxISOWeek(int16_t ISOYear_I);


#endif // ACETIME_ISOWEEK_H