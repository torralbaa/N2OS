#define MULTIBOOT_FLAG_MEM     0x001
#define MULTIBOOT_FLAG_DEVICE 0x002
#define MULTIBOOT_FLAG_CMDLINE 0x004
#define MULTIBOOT_FLAG_MODS 0x008
#define MULTIBOOT_FLAG_AOUT 0x010
#define MULTIBOOT_FLAG_ELF 0x020
#define MULTIBOOT_FLAG_MMAP 0x040
#define MULTIBOOT_FLAG_CONFIG 0x080
#define MULTIBOOT_FLAG_LOADER 0x100
#define MULTIBOOT_FLAG_APM 0x200
#define MULTIBOOT_FLAG_VBE 0x400

typedef struct multiboot_t
{
	int flags;
	int mem_lower;
	int mem_upper;
	int boot_device;
	int cmdline;
	int mods_count;
	int mods_addr;
	int num;
	int size;
	int addr;
	int shndx;
	int mmap_length;
	int mmap_addr;
	int drives_length;
	int drives_addr;
	int config_table;
	int boot_loader_name;
	int apm_table;
	int vbe_control_info;
	int vbe_mode_info;
	int vbe_mode;
	int vbe_interface_seg;
	int vbe_interface_off;
	int vbe_interface_len;
} multiboot_t;
