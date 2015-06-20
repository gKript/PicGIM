/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		main.c
	Project :		<Insert here the name of your project>
	Author :		<Insert here your nick>

	START LICENSE	GPL V3.0

		<one line to give the program's name and a brief idea of what it does.>
 
	    Copyright (C) <year>  <name of author>

		This program is free software: you can redistribute it and/or modify
		it under the terms of the GNU General Public License as published by
		the Free Software Foundation, either version 3 of the License, or
		(at your option) any later version.

		This program is distributed in the hope that it will be useful,
		but WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
		GNU General Public License for more details.

		You should have received a copy of the GNU General Public License
		along with this program.  If not, see <http://www.gnu.org/licenses/>.

	END LICENSE
 */


#include "picgim_main.h"

#define MY_LED          L_B2
#define MY_LED_TRIS     T_B2


void main( void ) {
	
	_pg_Uint16	kappa = 0;

	pg_initialize();

	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , 0 , 0 , "00 Ok!" );
	pg_lcd_hd44780_write			 ( PG_CONTROLLER_0 , 0 , 7 , "%dV %dMHz" , (int)PG_USER_SUPPLY_VOLT , (int)PG_CLOCK );
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , 1 , 0 , "01 Ok!" );
	
    pg_pin_mode( MY_LED_TRIS , PG_OUT );
	pg_pin_clear( MY_LED );

	PG_LOOP( PG_FOREVER ) {
		pg_pin_toggle( MY_LED );
		pg_lcd_hd44780_write		 ( PG_CONTROLLER_0 , 1 , 7 , "%d" , kappa );
		kappa++;
		pg_delay_msec( 50 );
		//pg_delay( 500 , PG_MSEC );
	}
	PG_HALT;
}

/*
void main( void ) {
	pg_initialize();

	T_B2 = PG_OUT;
	PG_LOOP ( PG_FOREVER ) {

	//	I enable only one channel (AN0) as analog input.
	pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
	//	I turn on the ADC module.
	pg_adc_set( PG_ADC_MODULE , PG_ON );
	//	I perform the first analog conversion.
	pg_adc_start( PG_CH_0 );
	//	I enable the PWM setting the maximum frequency calculated by PicGIM based on the frequency of the oscillator used in the project.
	
	pg_pwm_set( 1 , PG_KHZ );
	//	I set the Duty Cycle of PWM passing the percentage of the analog signal converted.
	pg_pwm_dutycycle( PG_PWM_1 , pg_adc_get_perc() );
	//	I starting the PWM device
	pg_pwm_start( PG_PWM_1 );
	//	We enter into an infinite loop that will run our program.
	
	PG_LOOP ( PG_FOREVER ) {
		//	I perform an analog conversion.
		pg_adc_start( PG_CH_0 );
		//	I set the Duty Cycle of PWM passing the percentage of the analog signal converted.
		//  For example with a supply voltage of 5V an analog conversion of 2.5V match to 50%.
		pg_pwm_dutycycle( PG_PWM_1 , pg_adc_get_perc() );
	}
	PG_HALT;
}

*/

