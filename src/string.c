/*
 * string.c
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

#include "string.h"

/*
 * 
 * name: strlen
 * params: @string
 * return: @i
 * description: Mide y devuelve la longitud de una cadena.
 * 
 */
int strlen(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

/*
 * 
 * name: strcmp
 * params: @stringa, @stringb
 * return: @0
 * description: Compara dos cadenas de texto.
 * 
 */
int strcmp(char* stringa, char* stringb)
{
	int i = 0;
	while (stringa[i] != '\0' && stringb[i] != '\0')
	{
		if (stringa[i] != stringb[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

/*
 * 
 * name: strcpy
 * params: @stringa, @stringb
 * return: @0
 * description: Copia el contenido de una cadena de texto a otra.
 * 
 */
int strcpy(char* stringa, char* stringb)
{
	int i = 0;
	while (strcmp(stringa, stringb) != 0)
	{
		stringa[i] = stringb[i];
		i++;
	}
	return 0;
}
