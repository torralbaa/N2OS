/*
 * char.c
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

#include "char.h"

/*
 * 
 * name: isupper
 * params: @character
 * return: @0
 * description: Averigua si un carácter ASCII es una letra mayúscula.
 * 
 */
int isupper(char character)
{
	if (character >= 0x41 && character <= 0x5a)
	{
		return 0;
	} else
	{
		return 1;
	}
}

/*
 * 
 * name: islower
 * params: @character
 * return: @0
 * description: Averigua si un carácter ASCII es una letra minúscula.
 * 
 */
int islower(char character)
{
	if (character >= 0x61 && character <= 0x7a)
	{
		return 0;
	} else
	{
		return 1;
	}
}

/*
 * 
 * name: isdigit
 * params: @character
 * return: @0
 * description: Averigua si un carácter ASCII es la representación de algún dígito.
 * 
 */
int isdigit(char character)
{
	if (character >= 0x30 && character <= 0x39)
	{
		return 0;
	} else
	{
		return 1;
	}
}
