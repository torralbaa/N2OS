/*
 * vga.c
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

#include "color.h"
#include "ports.h"
#include "types.h"
#include "screen.h"

char* video = (char*)0xb8000;
byte forecolor = 0x0f;
byte backcolor = 0x00;
int x = 0, y = 0, i = 0;

/*
 * 
 * name: getcolor
 * params: @ground
 * return: @0
 * description: Averigua y devuelve el color de frente o fondo, según se especifique.
 * 
 */
color_t getcolor(ground_t ground)
{
	color_t ret;
	if (ground == BACKGROUND)
	{
		ret = backcolor;
	} else if (ground == FOREGROUND)
	{
		ret = forecolor;
	}
	return ret;
}

/*
 * 
 * name: setcolor
 * params: @ground, @color
 * return: @0
 * description: Establece el color de frente o fondo, según se especifique.
 * 
 */
int setcolor(ground_t ground, color_t color)
{
	if (ground == BACKGROUND)
	{
		backcolor == color;
	} else if (ground == FOREGROUND)
	{
		forecolor == color;
	}
	return 0;
}

/*
 * 
 * name: movcursor
 * params:
 * return: @0
 * description: Mueve el cursor a la posición x-y especificada.
 * 
 */
int movcursor()
{
	int location = y * 80 + x;
	outb(0x3d4, 0x0e);
	outb(0x3d5, location >> 8);
	outb(0x3d4, 0x0f);
	outb(0x3d5, location);
	return 0;
}

/*
 * 
 * name: scroll
 * params:
 * return: @0
 * description: Hace scroll en la pantalla si es necesario.
 * 
 */
int scroll()
{
	int i = 0;
	if (y >= 25)
	{
		while (i < 24 * 80)
		{
			video[i] = video[i+80];
			i++;
		}
		i = 24 * 80;
		while (i < 25 * 80)
		{
			video[i] = ' ';
			video[i] = 0x0f;
			i++;
		}
		y = 24;
	}
}

/*
 * 
 * name: clear
 * params:
 * return: @0
 * description: Limpia la pantalla llenándola de espacios.
 * 
 */
int clear()
{
	int i;
	while(i < 80 * 25 * 2)
	{
		video[i] = ' ';
		video[i+1] = 0x0f;
		i = i + 2;
	}
	return 0;
}

/*
 * 
 * name: putc
 * params: @character
 * return: @0
 * description: Imprime un carácter en pantalla.
 * 
 */
int putc(char character)
{
	if (character == 0x0a)
	{
		x = 0;
		y++;
	} else if (character >= 0x20)
	{
		video[i] = character;
		video[i+1] = forecolor + backcolor;
	}
	if (x >= 80)
	{
		x = 0;
		y++;	
	}
	x++;
	i = i + 2;
	movcursor();
	scroll();
	return 0;
}

/*
 * 
 * name: printf
 * params: @string
 * return: @0
 * description: Imprime una cadena de texto en pantalla.
 * 
 */
int printf(char* string)
{
	int i = 0;
	while(i < strlen(string)) {
		putc(string[i]);
		i++;
	}
	return 0;
}
