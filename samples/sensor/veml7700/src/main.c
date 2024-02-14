/*
 * Copyright (c) 2024 GOLLA MANOJ KUMAR
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/sensor/veml7700.h>
#include <stdio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/sys/util.h>

static struct sensor_value fid, val;
#define PIN_CONFIG 0XB2 //0-15 BIT 0000000010110010 

static void fetching_device_details(const struct device *dev)
{
	int ret;
	static int count=0;
	static struct sensor_value get;
	
	ret = sensor_sample_fetch(dev);
	if (ret < 0) {
		printk("Sample Fetch Error %d\n", ret);
		return;
	}

	ret = sensor_channel_get(dev, SENSOR_CHAN_LIGHT, &val);
	if (ret < 0) {
		printk("Channel Get Error %d\n", ret);
		return;
	}
	printk("value of sensor_value:%.1f\n",sensor_value_to_double(&val.val1));

	fid.val1=0XB2;
	ret = sensor_attr_set(dev, SENSOR_CHAN_LIGHT, SENSOR_ATTR_UPPER_THRESH, &fid);

	if (ret == 0) {
		printk("successfully set the ambient light sensor data :%.1f\n", sensor_value_to_double(&fid.val1));
	}

	ret = sensor_attr_get(dev, SENSOR_CHAN_LIGHT, SENSOR_ATTR_UPPER_THRESH, &get);
	if (ret == 0) {
		printk("successfully get the ambient light sensor data :%.1f\n", sensor_value_to_double(&get.val1));
	}
	++count;
	printk("count:%d\n",count);
}

int main(void)
{
	int ret;

	struct device *i2c_dev = DEVICE_DT_GET_ONE(vishay_veml7700);
	if (!i2c_dev) {
		printk("sensor: device not ready.\n");
		return 0;
	}

	while(1){
		fetching_device_details(i2c_dev);
		k_sleep(K_MSEC(2000));
		}

	k_sleep(K_FOREVER);
	return 0;
}
