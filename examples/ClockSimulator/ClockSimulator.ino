/* Clock simulator
 * Prints time every second, and date every minute
 * 
 */

#include <Arduino.h>
#include <AceTimeISOWeek.h>  // https://github.com/hdrlux/AceTimeISOWeek

// Localized short string
#define dt_MAX_STRING_LEN 9
#define dt_SHORT_STR_LEN 3

static char buffer_m[dt_MAX_STRING_LEN + 1];
static char buffer_d[dt_MAX_STRING_LEN + 1];

//const char monthShortNames_P[] PROGMEM = "ErrJanFebMarAprMayJunJulAugSepOctNovDec";  //Translate to local Language
//const char dayShortNames_P[] PROGMEM = "ErrMonTueWedThuFriSatSun";                   //Translate to local Language
const char monthShortNames_P[] PROGMEM = "ErrJanFebMrtAprMeiJunJulAugSepOktNovDec";  //Dutch
const char dayShortNames_P[] PROGMEM = "ErrMa.Di.Wo.Do.Vr.Za.Zo.";                   //Dutch

char* monthShortStr(uint8_t month) {
  for (int i = 0; i < dt_SHORT_STR_LEN; i++)
    buffer_m[i] = pgm_read_byte(&(monthShortNames_P[i + (month * dt_SHORT_STR_LEN)]));
  buffer_m[dt_SHORT_STR_LEN] = 0;
  return buffer_m;
}

char* dayShortString(uint8_t day) {
  uint8_t index = day * dt_SHORT_STR_LEN;
  for (int i = 0; i < dt_SHORT_STR_LEN; i++)
    buffer_d[i] = pgm_read_byte(&(dayShortNames_P[index + i]));
  buffer_d[dt_SHORT_STR_LEN] = 0;
  return buffer_d;
}
//end Localized short string

// Starttime
acetime_t t = LocalDateTime::forComponents(2021, 1, 3, 23, 59, 45).toEpochSeconds();
byte last_min;

void setup() {           // do only once
  Serial.begin(115200);  // Set Serial Monitor to same speed
  Serial.println();      // clean-up buffer
  Serial.println("Clock simulation with ISO8601 Week Number");
  Serial.println();
}

void loop() {
  serialprint();
  t++;          // add 1 second
  delay(1000);  //usefull in simulator only
}

void serialprint() {
  LocalDateTime now = LocalDateTime::forEpochSeconds(t);
  char TimeBuf[15];  //time string buffer
  sprintf(TimeBuf, "%.2d:%.2d.%.2d",
          now.hour(), now.minute(), now.second());
  Serial.println(TimeBuf);

  if (last_min != now.minute()) {  // Check minute
    last_min = now.minute();
    char DateBuf[20];  //time string buffer
    sprintf(DateBuf, "W%.2d %s %.2d-%s-%d",
            EpochTimeToISOWeek(t), dayShortString(now.dayOfWeek()), now.day(), monthShortStr(now.month()), now.year());
    Serial.println(DateBuf);
    Serial.println();
  }
}

//End
