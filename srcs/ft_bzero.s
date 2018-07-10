%include			"macros.s"

					global		FUNC(ft_bzero)	

; void ft_bzero(void *str, size_t n);
					section		.text
FUNC(ft_bzero):		cmp			rsi, 0			; check n if 0
					je			.done			; if so, return
.zero:				mov			byte [rdi], 0	; *str = 0;
					inc			rdi				; ++*str;
					dec			rsi				; --n;
					jnz			.zero			; repeat until n == 0
.done:				ret
