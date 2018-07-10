%include			"macros.s"

					global		FUNC(ft_strcat)
					extern		FUNC(ft_strlen)

; char *ft_strcat(char *dst, const char *src);
					section		.text
FUNC(ft_strcat):	push		rdi				; store original dst pos
					mov			rcx, I64_MAX
					xor			al, al
					cld
					repne		scasb			; loops until rdi is at the end of string
					push		rdi				; saves strings into stack
					push		rsi
					mov			rdi, rsi
					call		FUNC(ft_strlen)
					mov			rcx, rax		; stores src's length to rcx
					pop			rsi
					pop			rdi
					dec			rdi				; set pointer one char back
					cld
					rep			movsb			; copies src at the end of dst
					pop			rax				; return dst
					ret
