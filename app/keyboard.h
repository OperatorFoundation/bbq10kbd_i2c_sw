#pragma once

#include <stdbool.h>
#include <stdint.h>

enum key_state
{
	KEY_STATE_IDLE = 0,
	KEY_STATE_PRESSED,
	KEY_STATE_HOLD,
	KEY_STATE_RELEASED,
};

#define KEY_UP '\x01'
#define KEY_DOWN	'\x02'
#define KEY_LEFT	'\x03'
#define KEY_RIGHT	'\x04'
#define KEY_CENTER	'\x05'
#define KEY_DELETE '\x08'
#define CARRIAGE_RETURN '\x0D'

#define KEY_JOY_UP		0x01
#define KEY_JOY_DOWN	0x02
#define KEY_JOY_LEFT	0x03
#define KEY_JOY_RIGHT	0x04
#define KEY_JOY_CENTER	0x05
#define KEY_BTN_LEFT1	0x06
#define KEY_BTN_RIGHT1	0x07
// 0x08 - BACKSPACE
// 0x09 - TAB
// 0x0A - NEW LINE
// 0x0D - CARRIAGE RETURN
#define KEY_BTN_LEFT2	0x11
#define KEY_BTN_RIGHT2	0x12

#define KEY_MOD_ALT		0x1A
#define KEY_MOD_SHL		0x1B
#define KEY_MOD_SHR		0x1C
#define KEY_MOD_SYM		0x1D
#define KEY_MOD_HN		0x1E

typedef void (*key_callback)(char, enum key_state);
typedef void (*lock_callback)(bool, bool);

void keyboard_process(void);
void keyboard_set_key_callback(key_callback callback);
void keyboard_set_lock_callback(lock_callback callback);
bool keyboard_get_capslock(void);
bool keyboard_get_numlock(void);
void keyboard_init(void);
