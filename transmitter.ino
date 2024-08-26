//transmitter

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver(2000, 4, 2, 5);

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(115200);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif
}

void loop()
{
    const char *msg = "IIT PATNA😎😎😊😊😊";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}