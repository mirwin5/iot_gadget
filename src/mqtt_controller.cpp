#include "mqtt_controller.h"
#include "sensor_readings.h"
#include "settings.h"

    int level1 = analogRead(A_LEVEL_PIN_IN);
    int level2 = digitalRead(H_LEVEL_PIN_IN);

void ledMessage(AdafruitIO_Data *data)
{

    DEBUGPRINT("received <- ");
    DEBUGPRINTLN(data->value());

    if ((level2 == LOW) || (level1 >= 500))
    {
        (!strcmp(data->value(), "off"));
    }

    if ((level2 == LOW) && (level1 >= 500))
    {
        (!strcmp(data->value(), "on"));
    }
}