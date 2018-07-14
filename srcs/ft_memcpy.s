%include			"macros.s"

					global		FUNC(ft_memcpy)

					section		.text
FUNC(ft_memcpy):	mov			rcx, rdx
					cld
					rep			movsb	
					ret
