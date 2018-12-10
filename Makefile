CC := gcc
AS := as
LD := ld
RM := rm -rf
CFLAGS := -m32 -Isrc/include -nostdlib -std=c99 -c
ASFLAGS := --32
LDFLAGS := -Tsrc/link.ld -e _start
OBJ := obj/boot.ko obj/char.ko obj/ports.ko obj/screen.ko obj/string.ko obj/kernel_main.ko
ELF := n2os.elf

all: clean
	@echo "Compilando objetivo n2os.elf..."
	@mkdir obj/
	@echo "Ensamblando boot.asm..."
	@${AS} src/boot.asm -o obj/boot.ko
	@echo -e "Compilando char.c..."
	@${CC} ${CFLAGS} src/char.c -o obj/char.ko
	@echo -e "Compilando ports.c..."
	@${CC} ${CFLAGS} src/ports.c -o obj/ports.ko
	@echo "Compilando screen.c..."
	@${CC} ${CFLAGS} src/screen.c -o obj/screen.ko
	@echo -e "Compilando string.c..."
	@${CC} ${CFLAGS} src/string.c -o obj/string.ko
	@echo "Compilando kernel_main.c..."
	@${CC} ${CFLAGS} src/kernel_main.c -o obj/kernel_main.ko
	@echo "Enlazando ejecutable n2os.elf..."
	@${LD} ${LDFLAGS} ${OBJ} -o ${ELF}
clean:
	@rm -rf obj/ iso/sys/*.* *.elf *.iso
grub-iso: all
	@mkdir iso/ iso/sys
	@mv boot iso/boot
	@mv n2os.elf iso/sys/n2os.elf
	@grub-mkrescue --product-name=N2OS --product-version=0.1.0 -o n2os.iso iso
test: grub-iso
	@qemu-system-i386 -hda n2os.iso -serial stdio