AceTimeISOWeek v0.1<br>
ISOWeek add-on for the <a href="https://github.com/bxparks/AceTime">AceTime Library</a>

Wiki: <a href="https://en.wikipedia.org/wiki/ISO_week_date">ISO 8601 week date</a><br>
Wiki: <a href="https://en.wikipedia.org/wiki/Gregorian_calendar">Gregorian calendar</a>

The AceTimeISOWeek library assumes you are running a Arduino based clock in AceTime [using acetime_t EpochSeconds], which in short is great in displaying datetime in different time zones with correct summer/winter time, called DST.

AceTimeISOWeek provides the transformation EpochDay<>ISOweek, and is Epoch independent. For the calculation it does not matter if you use UnixTime, Y2K, 2050, or Excel serial date. The only important requirement is that dayofweek(date) returns [Mon=1]..[Sun=7], according to ISO8601. You can check this with (Sun 05-Jan-2020 = 7) and (Mon 06-jan-2020 = 1). The transformation GregorianDate<>EpochDay is provided by the DateTime library AceTime, but the logic could be used with any other library. 

The ISOYear can be different from current year in the first or last week. We make use of the definition that ‘Monday is the first day of the week’. And we make use of the definition that ‘the first week is the week with 4 days’, which is 04-Jan and the first Thursday. If you need to do a range check for the input ISOWeek, 28-dec of a year is always in the last week, and tells if there are 52 or 53 weeks. Internally, the conversion uses the daynumber of the ISOYear, with range [0..370] for a year with 53 weeks.

The ClockSimulator example shows how to display the datestring including ISO Week number. 
The ValidationISOWeek example just creates a CSV output, that can be validated with Excel or any other software you like.

Easy to adapt to any other DateTime library of your choice.

Tested on Arduino Nano v3.0 ATmega328 5V
