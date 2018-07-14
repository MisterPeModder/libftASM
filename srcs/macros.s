; Macro file for Linux - macOS ASM compatiblity ;

%ifdef IS_MACH
	; Basic symbols
	%define PRG_START			start

	; Function name wrapper
	%define FUNC(n)				_ %+ n

	; Syscalls
	%define SYSCALL_EXIT_ID		0x02000001
	%define SYSCALL_READ_ID		0x02000003
	%define SYSCALL_WRITE_ID	0x02000004
%else
	; Basic symbols
	%define PRG_START			_start

	; Function name wrapper
	%define FUNC(n)				n

	; Syscalls
	%define SYSCALL_EXIT_ID		60
	%define SYSCALL_READ_ID		0
	%define SYSCALL_WRITE_ID	1
%endif

; limits
%define I64_MAX 0xffffffffffffffff

; check if given varable %1 is >= %2 and <= %3
; you can use ja or jbe to jump if false of true respectively
%macro	is_inside	3
		sub			%1, %2
		cmp			%1, %3 - %2
%endmacro
