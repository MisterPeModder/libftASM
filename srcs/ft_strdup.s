%include			"macros.s"

					global		FUNC(ft_strdup)
					extern		FUNC(ft_strlen)
					extern		FUNC(malloc)

					section		.text
FUNC(ft_strdup):	push		rbp					; function prologue
					mov			rbp, rsp
					push		rdi					; save string for later
					sub			rsp, 8				; space for string length
					call		FUNC(ft_strlen)		; get string's length
					mov			rdi, rax
					mov			qword [rsp], rax	; save rax
					call		FUNC(malloc)
					test		rax, rax			; if malloc failed,
					jz			FUNC(ft_strdup_e)	; jump to end (and return NULL)
					pop			rcx
					pop			rsi
					mov			rdi, rax
					rep			movsb				; copy the string
FUNC(ft_strdup_e):	mov			rsp, rbp			; function epilogue
					pop			rbp
					ret
