/*
 * color.h
 * 
 * Copyright 2018 Alvarito050506 <donfrutosgomez@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef COLOR_H
#define COLOR_H

typedef enum color_t {
	COLOR_BLACK = 0x00,
	COLOR_BLUE = 0x01,
	COLOR_GREEN = 0x02,
	COLOR_CYAN = 0x03,
	COLOR_RED = 0x04,
	COLOR_MAGENTA = 0x05,
	COLOR_BROWN = 0x06,
	COLOR_LIGHT_GREY = 0x07,
	COLOR_DARK_GREY = 0x08,
	COLOR_LIGHT_BLUE = 0x09,
	COLOR_LIGHT_GREEN = 0x0a,
	COLOR_LIGHT_CYAN = 0x0b,
	COLOR_LIGHT_RED = 0x0c,
	COLOR_LIGHT_MAGENTA = 0x0d,
	COLOR_LIGHT_BROWN = 0x0e,
	COLOR_WHITE = 0x0f
} color_t;
typedef enum ground_t {
	BACKGROUND = 0,
	FOREGROUND = 1
} ground_t;
#endif
