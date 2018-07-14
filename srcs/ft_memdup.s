%include			"macros.s"

					global		FUNC(ft_memdup)
					extern		FUNC(ft_strlen)
					extern		FUNC(malloc)

					section		.text
FUNC(ft_memdup):	push		rbp
					mov			rbp, rsp
					push		rdi
					push		rsi
					mov			rdi, rsi
					call		FUNC(malloc)
					test		rax, rax			; if malloc failed,
					jz			FUNC(ft_memdup_e)	; jump to end (and return NULL)
					pop			rcx
					pop			rsi
					mov			rdi, rax
					rep			movsb				; copy the string
FUNC(ft_memdup_e):	mov			rsp, rbp
					pop			rbp
					ret
