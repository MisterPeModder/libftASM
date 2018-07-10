; Macro file for Linux - macOS ASM compatiblity ;

; Syscalls
%define SYSCALL_EXIT_ID			1
%define SYSCALL_WRITE_ID		4

%ifdef IS_MACH
	; Basic symbols
	%define PRG_START			start

	; Wrappers
	%define WRAP_SYSCALL(id)	0x02000000 | id
	%define FUNC(n)				_ %+ n
%else
	; Basic symbols
	%define PRG_START			_start

	%define WRAP_SYSCALL(id)	id
	%define FUNC(n)				n
%endif

%macro 	sys_exit	1
		mov			rax, WRAP_SYSCALL(SYSCALL_EXIT_ID)
		mov			rdi, %1
		syscall
%endmacro
