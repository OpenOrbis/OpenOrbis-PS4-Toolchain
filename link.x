SECTIONS
{
	# Combine text, rodata, and eh_frame stuff
	.text : ALIGN(0x4000) {
		# "/libexec/ld-elf.so.1"
		QUAD(0x6365786562696C2F);
		QUAD(0x2E666C652D646C2F);
		QUAD(0x00000000312E6F73);
		QUAD(0x0000000000000000);

		# original .text
		*(.text)
	}

	.rodata : ALIGN(0x10) {
		*(.rodata)
	}

	.eh_frame : {
		*(.eh_frame)
	}

	.eh_frame_hdr : {
		*(.eh_frame_hdr)
	}

	.data.rel.ro : ALIGN(0x4000) {
		*(.data.rel.ro)
	}

	.tls : ALIGN(0x4000) {
		*(.tdata);
		*(.tbss);
	}

	# Align .got to 0x4000 if .data.rel.ro doesn't exist
	. = (SIZEOF(.data.rel.ro) > 0 ? . : ALIGN(.,0x4000));
	.got : {
		*(.got)
	}

	# Align .got.plt to 0x4000 if .got doesn't exist
	. = (SIZEOF(.got) > 0 ? . : ALIGN(.,0x4000));
	.got.plt : {
		*(.got.plt)
	}

	.data.sce_process_param : ALIGN(0x4000) {
		*(.data.sce_process_param)
	}

	.data.sce_module_param : ALIGN(0x4000) {
		*(.data.sce_module_param)
	}

	.data : {
		*(.data)
	}

	.bss : {
		*(.bss)
	}

	# Force .got.plt to appear, because SPRX requires a valid .got.plt.
	/DISCARD/ : {
		QUAD(_GLOBAL_OFFSET_TABLE_)
	}
}
