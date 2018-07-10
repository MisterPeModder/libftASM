%include			"macros.s"

					global		FUNC(ft_bzero)	

; void ft_bzero(void *str, size_t n);
					section		.text
FUNC(ft_bzero):		mov			rcx, rsi		; stores n into the counter
					xor			al, al			; set fill byte to '\0'
					cld							; set (positive) increment mode
					rep			stosb			; while (rcx--) {*str = 0; ++str}
					ret
