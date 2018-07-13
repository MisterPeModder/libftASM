%include			"macros.s"

					global		FUNC(ft_puts)
					extern		FUNC(ft_strlen)

; int ft_puts(const char *str);
					section		.text
FUNC(ft_puts):		push		rbp									; save callee-save register
					mov			rbp, rsp
					push		rdi
					call		FUNC(ft_strlen)
					mov			rdx, rax							; set write's size parameter
					pop			rsi									; write 'str'
					mov			rsp, rbp
					pop			rbp									; restore callee-save register
					mov			rdi, 1								; write to stdout
					mov			rax, SYSCALL_WRITE_ID				; set syscall to write
					syscall											; write(1, str, ft_strlen(str));
					cmp			rax, -4095
					jae			FUNC(ft_puts_err)
					mov			rdx, 1								; write 1 char
					lea			rsi, [rel newline]					; write end-of-line character
					mov			rax, SYSCALL_WRITE_ID				; set syscall to write
					syscall											; write(1, '\n', 1);
					cmp			rax, -4095
					jae			FUNC(ft_puts_err)
					xor			rax, rax
					ret												; return (0);
FUNC(ft_puts_err):	mov			rax, -1								; return EOF (-1) on error
					ret

					section		.data
newline:			db			10
