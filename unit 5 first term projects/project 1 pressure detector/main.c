#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "alarm_driver.h"
#include "pressure.h"
#include "alarm_monitor.h"
#include "mainalgorithm.h"

void setup()
{
GPIO_INITIALIZATION();
pr_pointerstate = STATE(pressure_init);
main_pointer = STATE(MA_high_pressure_detected);
alarm_monitor_pointer_state = STATE(alarmoff_);
alarm_driver_pointer = STATE(alarm_d_init);


}


int main (){
	
	while (1)
	{
		pr_pointerstate();
		main_pointer();
		alarm_monitor_pointer_state();
		alarm_driver_pointer();
	}
return 0;
}
