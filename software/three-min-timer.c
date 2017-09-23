/*
 * three-minutes-timer.c -- Three minutes timer firmware for AVR ATtiny85
 * Copyright (C) 2017 Hiroshi Takekawa
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ATTENTION: GPL version 2 only. You cannot apply any later version.
 * This situation may change in the future.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#define LED_PIN		8	/* PB0: 2-3 minutes */
#define LED2_PIN	9	/* PB1: 1-2 minutes */
#define LED3_PIN	10	/* PB2: 0-1 minutes */
/* You must change the PCMSK value to receive interrupt */
#define SW_PIN		11	/* PB3: SW Input */
#define SND_PIN		12	/* PB4: Sound IC Power */

static int set_direction(int pin, int d)
{
#if defined(DDRD)
	if (pin >= 0 && pin < 8) {
		if (d)
			DDRD |= (1 << pin);
		else
			DDRD &= ~(1 << pin);
	} else
#endif
	if (pin >= 8 && pin <= 13) {
		pin -= 8;
		if (d)
			DDRB |= (1 << pin);
		else
			DDRB &= ~(1 << pin);
	}
}

static int set_port(int pin, int d)
{
#if defined(DDRD)
	if (pin >= 0 && pin < 8) {
		if (d)
			PORTD |= (1 << pin);
		else
			PORTD &= ~(1 << pin);
	} else
#endif
	if (pin >= 8 && pin <= 13) {
		pin -= 8;
		if (d)
			PORTB |= (1 << pin);
		else
			PORTB &= ~(1 << pin);
	}
		
}

static int get_port(int pin)
{
#if defined(DDRD)
        if (pin >= 0 && pin < 8) {
                return (PIND & (1 << pin)) ? 1 : 0;
        } else
#endif
	if (pin >= 8 && pin <= 13) {
                pin -= 8;
                return (PINB & (1 << pin)) ? 1 : 0;
        }
        return -1;
}

static int _20ms;
static int timer_started;
static int elapsed_minutes;

/* Timer interrupt handler */
ISR(TIM0_COMPA_vect)
{
	if (!timer_started)
		return;
	_20ms++;
	if (_20ms >= 50 * 60) { /* 1 minute */
		elapsed_minutes++;
		switch (elapsed_minutes) {
		case 1:
			set_port(LED_PIN, 0);
			set_port(LED2_PIN, 1);
			break;
		case 2:
			set_port(LED2_PIN, 0);
			set_port(LED3_PIN, 1);
			break;
		case 3:
			set_port(LED3_PIN, 0);
			set_port(SND_PIN, 1);
			break;
		case 4:
			set_port(SND_PIN, 0);
			timer_started = 0;
			break;	
		default:
			break;
		}
		_20ms = 0;
	}
}

/* Port change interrupt handler for SW */
ISR(PCINT0_vect)
{
	int sw = get_port(SW_PIN);

	if (!sw)
		return;

	if (timer_started) {
		/* When pushed during timer running, reset */
		timer_started = 0;
		set_port(LED_PIN, 0);
		set_port(LED2_PIN, 0);
		set_port(LED3_PIN, 0);
		set_port(SND_PIN, 0);
	} else {
		/* Start timer and switch LED on */
		timer_started++;
		set_port(LED_PIN, 1);
	}
}

int main(int argc, char **argv)
{
	cli();
	OCR0A = 157;		/* 20ms@8MHz/1024, rounded up */
	TIMSK |= _BV(OCIE0A);	/* Compare Match Interrupt Enable */
	GIMSK |= _BV(PCIE);	/* PIN Change Interrupt Enable */
	PCMSK |= 0x08;		/* Enable PB3 PIN Change Interrupt */
	TCCR0A |= _BV(WGM01);	/* CTC: Clear Timer on Compare match mode */
	TCCR0B |= 5;		/* pre-scaler /1024 */
	TCNT0 = 0;
	set_direction(LED_PIN, 1);
	set_direction(LED2_PIN, 1);
	set_direction(LED3_PIN, 1);
	set_direction(SND_PIN, 1);
	set_direction(SW_PIN, 0);
	set_port(LED_PIN, 0);
	set_port(LED2_PIN, 0);
	set_port(LED3_PIN, 0);
	set_port(SND_PIN, 0);
	set_sleep_mode(SLEEP_MODE_IDLE);
	sei();

	/* Main loop, interrupt driven */
	for (;;)
		sleep_mode();

	return 0;
}
