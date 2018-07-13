; Macro file for Linux - macOS ASM compatiblity ;

%ifdef IS_MACH
	; Basic symbols
	%define PRG_START			start

	; Function name wrapper
	%define FUNC(n)				_ %+ n

	; Syscalls
	%define SYSCALL_EXIT_ID		0x02000001
	%define SYSCALL_WRITE_ID	0x02000004
%else
	; Basic symbols
	%define PRG_START			_start

	; Function name wrapper
	%define FUNC(n)				n

	; Syscalls
	%define SYSCALL_EXIT_ID		60
	%define SYSCALL_WRITE_ID	1
%endif


; Generic syscall macro, takes the syscall id as the first parameters.
; note: to stay compatible with linux, sys_generic cannot take more than 7 params.
%macro	sys_generic	1-*
		mov			rax, %1
	%if %0 >= 2
		mov			rdi, %2
	%endif
	%if %0 >= 3
		mov			rsi, %3
	%endif
	%if %0 >= 4
		mov			rdx, %4
	%endif
	%if %0 >= 5
		mov			rcx, %5
	%endif
	%if %0 >= 6
		mov			r8, %6
	%endif
	%if %0 = 7
		mov			r9, %7
	%endif
	%if %0 > 7
		%error "sys_generic can't take more than 7 arguments"
	%endif
		syscall
%endmacro

; More useful syscalls
%macro 	sys_exit	1
		sys_generic SYSCALL_EXIT_ID, %1
%endmacro

%macro	sys_write	3
		sys_generic	SYSCALL_WRITE_ID, %1, %2, %3
%endmacro

; limits
%define I64_MAX 0xffffffffffffffff

; check if given varable %1 is >= %2 and <= %3
; you can use ja or jbe to jump if false of true respectively
%macro	is_inside	3
		sub			%1, %2
		cmp			%1, %3 - %2
%endmacro
