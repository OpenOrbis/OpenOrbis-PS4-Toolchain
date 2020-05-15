SECTIONS
{
	/* Combine text, rodata, and eh_frame stuff */
	.text : ALIGN(0x4000) {
		. += 0x20;
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
}