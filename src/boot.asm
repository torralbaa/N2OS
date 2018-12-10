/*
 * boot.asm
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

#include <multiboot.h>
#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_HEADER_FLAGS 0x00000003
#define STACK_SIZE 0x4000

.text
.globl _start
_start:
	jmp multiboot_entry
	.align 4
multiboot_header:
	.long 0x1BADB002
	.long 0x00000003
	.long -(0x1BADB002+0x00000003)
multiboot_entry:
	movl $(stack + 0x4000), %esp
	call kernel_main
loop: hlt
	jmp loop
.section ".bss"
	.comm stack, 0x4000
