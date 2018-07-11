%include			"macros.s"

					global		FUNC(ft_isprint)

; int ft_isprint(int c);
					section		.text
FUNC(ft_isprint):	xor			eax, eax		; sets return value to 0
					is_inside	edi, 32, 126
					setbe		al
					ret
