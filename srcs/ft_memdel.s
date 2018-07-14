%include			"macros.s"

					global		FUNC(ft_memdel)
					extern		FUNC(free)

					section		.text
; void ft_memdel(void **p);
FUNC(ft_memdel):	push		rbp
					mov			rbp, rsp
					push		rbx					; preserve calle-save register
					sub			rsp, 8
					test		rdi, rdi			; if (p == NULL) return ;
					jz			FUNC(ft_memdel_e)
					mov			rbx, rdi
					mov			rdi, qword [rbx]
					call		FUNC(free)
					mov			qword [rbx], 0		; *p = NULL
FUNC(ft_memdel_e):	add			rsp, 8
					pop			rbx
					pop			rbp
					ret
