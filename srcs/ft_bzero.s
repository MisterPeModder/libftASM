%include			"macros.s"

					global		FUNC(ft_bzero)	; void ft_bzero(void *s, size_t n)

					section		.text
FUNC(ft_bzero):		mov			r8, rsi			; set r8 to n	
					cmp			r8, 0
					je			.done
.zero:				mov			byte [rdi], 0
					inc			rdi
					dec			r8
					jnz			.zero
.done:				ret
