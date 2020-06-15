.intel_syntax noprefix
.section ".text"

# Entry point
.align 0x10
.section ".text._start"
.global _start
_start:
	# Align the stack to 16-byte alignment for SSE
	sub rsp, 0x28

	# Back up important values to registers
	mov r8, rsi # ???
	mov r9d, dword ptr [rdi]   # argc = r9d
	lea r10, qword ptr [rdi+8] # argv = r10

	mov rdi, r8
	call atexit

	# Call main()
	xor edx, edx # envp
	mov edi, r9d # argc
	mov rsi, r10 # argv
	call main

	# Save main() return value for later calls
	mov r11d, eax

	mov edi, r11d
	call exit

# sceLibcParam
.align 0x8
.section ".data.rel.ro._sceLibcParam"
_sceLibcParam: 
	.quad   0x90 		# Size 
	.quad 	0x10000000C	# Unknown?
	.quad	sceLibcHeapSize
	.quad	0
	.quad	sceLibcHeapExtendedAlloc
	.quad	0
	.quad	sceLibcMallocReplace
	.quad 	sceLibcNewReplace
	.quad	0
	.quad	1 			# Need_sceLibc
	.quad	0
	.quad	0
	.quad	sceLibcMallocReplaceForTls
	.quad 	0
	.quad 	0
	.quad 	0
	.quad	0
	.quad 	0

# sceKernelMemParam
.align 0x8
.section ".data.rel.ro._sceKernelMemParam"
_sceKernelMemParam: 
	.quad   0x30		# Size
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0

# sceKernelFsParam
.align 0x8
.section ".data.rel.ro._sceKernelFsParam"
_sceKernelFsParam:
	.quad 	0x10 		# Size
	.quad 	0

# sceLibcMallocReplace
.align 0x8
.section ".data.rel.ro._sceLibcMallocReplace"
sceLibcMallocReplace:
	.quad 	0x70 		# Size
	.quad 	1
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0

# sceLibcNewReplace
.align 0x8
.section ".data.rel.ro._sceLibcNewReplace"
sceLibcNewReplace:
	.quad 	0x70 		# Size
	.quad 	2
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0

# sceLibcMallocReplaceForTls
.align 0x8
.section ".data.rel.ro._sceLibcMallocReplaceForTls"
sceLibcMallocReplaceForTls:
	.quad 	0x38		# Size
	.quad 	1
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0
	.quad 	0

# sce_process_param
.align 0x8
.section ".data.sce_process_param"
_sceProcessParam:
	.quad 	0x50		# Size
	.long   0x4942524F	# Magic "ORBI"
	.long 	0x3 		# Entry count
	.quad 	0x4508101 	# SDK version
	.quad 	0
	.quad 	0
	.quad	0
	.quad 	0
	.quad 	_sceLibcParam
	.quad 	_sceKernelMemParam
	.quad 	_sceKernelFsParam

# data globals
.align 0x8
.section ".data"

sceLibcHeapExtendedAlloc:
	.quad	1

sceLibcHeapSize:
	.quad	0xffffffffffffffff

sce_libc_heap_delayed_alloc:
	.long 	0

sce_libc_heap_extended_alloc:
	.long	0

__dso_handle:
	.quad 	0

_sceLibc:
	.quad 	0
