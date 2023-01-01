AceTimeISOWeek v0.1<br>
ISOWeek add-on for the <a href="https://github.com/bxparks/AceTime">AceTime Library</a>

Wiki: <a href="https://en.wikipedia.org/wiki/ISO_week_date">ISO 8601 week date</a><br>
Wiki: <a href="https://en.wikipedia.org/wiki/Gregorian_calendar">Gregorian calendar</a>

The AceTimeISOWeek library assumes you are running a Arduino clock in AceTime, which in short is great in displaying datetime in different time zones with correct summer/winter time, called DST.

AceTimeISOWeek provides the transformation date<>ISOweek, and is Epoch independent. For the calculation it does not matter if you use UnixTime, Y2K, 2050, or Excel serial date. The only important requirement is that dayofweek(date) returns [Mon=1]..[Sun=7]. You can check this with (Sun 05-Jan-2020 = 7) and (Mon 06-jan-2020 = 1)

The ISOYear can be different from current year in the first or last week. We make use of the definition that ‘Monday is the first day of the week’. And we make use of the definition that ‘the first week is the week with 4 days’, which is 04-Jan and the first Thursday. If you need to do a range check for the input ISOWeek, 28-dec of a year is always in the last week, and tells if there are 52 or 53 weeks.
