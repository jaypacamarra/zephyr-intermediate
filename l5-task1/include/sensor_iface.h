#ifndef INCLUDE_SENSOR_IFACE_H
#define INCLUDE_SENSOR_IFACE_H

#include <stdint.h>
#include <zephyr/zbus/zbus.h>

struct sensor_data {
        uint32_t timestamp_ms;
        int32_t encoder_pos;
};

ZBUS_CHAN_DECLARE(sensor_chan);

#endif /* INCLUDE_SENSOR_IFACE_H */
