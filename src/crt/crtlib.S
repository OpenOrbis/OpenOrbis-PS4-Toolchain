.intel_syntax noprefix
.section ".text"

# sce_module_param
.align 0x8
.section ".data.sce_module_param"
_sceModuleParam:
	.quad 	0x18		# Size
	.quad   0x13C13F4BF	# Magic
	.quad 	0x4508001 	# SDK version

# data globals
.align 0x8
.section ".data"

__dso_handle:
	.quad 	0

_sceLibc:
	.quad 	0
