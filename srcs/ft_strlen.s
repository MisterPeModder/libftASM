%include			"macros.s"

					global		FUNC(ft_strlen)

; size_t ft_strlen(const char *str);
					section		.text
FUNC(ft_strlen):	mov			rcx, I64_MAX	; set counter to max value
					xor			al, al			; set al to 0
					cld							; set operation left to right
					mov			rbx, rdi		; save original string address
					repne		scasb			; while (*rdi != 0) ++rdi;
					sub			rdi, rbx		; get string length
					mov			rax, rdi
					sub			rax, 1			; substract extra character from length
					ret
