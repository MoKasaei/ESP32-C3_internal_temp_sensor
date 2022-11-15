/*
https://docs.espressif.com/projects/esp-idf/zh_CN/v4.4/esp32c3/api-reference/peripherals/temp_sensor.html
https://github.com/espressif/esp-idf/tree/v4.4/examples/peripherals/temp_sensor

TSENS_DAC_L0    !< offset = -2, measure range: 50℃ ~ 125℃, error < 3℃.
TSENS_DAC_L1    !< offset = -1, measure range: 20℃ ~ 100℃, error < 2℃.
TSENS_DAC_L2    !< offset =  0, measure range:-10℃ ~  80℃, error < 1℃.
TSENS_DAC_L3    !< offset =  1, measure range:-30℃ ~  50℃, error < 2℃.
TSENS_DAC_L4    !< offset =  2, measure range:-40℃ ~  20℃, error < 3℃.
TSENS_DAC_MAX
TSENS_DAC_DEFAULT = TSENS_DAC_L2
*/

#include <driver/temp_sensor.h>

void setup() {
  Serial.begin(115200);
  temp_sensor_config_t temp_sensor = {
    .dac_offset = TSENS_DAC_L2,
    .clk_div = 6,
  };
  temp_sensor_set_config(temp_sensor);
  temp_sensor_start();
}

void loop() {
  float tsens_out;
  temp_sensor_read_celsius(&tsens_out);
  Serial.print(tsens_out);
  Serial.println(" ℃");
  delay(500);
}