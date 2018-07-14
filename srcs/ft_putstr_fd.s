%include				"macros.s"

						global		FUNC(ft_putstr_fd)
						extern		FUNC(ft_strlen)

; void ft_putstr_fd(const char *str, int fd);
						section		.text
FUNC(ft_putstr_fd):		push		rbp									; save callee-save register
						mov			rbp, rsp
						push		rsi
						push		rdi
						call		FUNC(ft_strlen)
						mov			rdx, rax
						pop			rsi
						pop			rdi
						mov			rax, SYSCALL_WRITE_ID
						syscall
						pop			rbp
						ret
