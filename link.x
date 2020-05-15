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

	.got : {
		*(.got)
	}

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
