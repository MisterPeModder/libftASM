%include			"macros.s"

					global		FUNC(ft_memset)	

; void ft_memset(void *str, int c, size_t n);
					section		.text
FUNC(ft_memset):	mov			rcx, rdx		; stores n into the counter
					mov			al, sil			; set fill byte to c
					cld							; set (positive) increment mode
					rep			stosb			; while (rcx--) {*str = 0; ++str}
					ret
