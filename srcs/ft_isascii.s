%include			"macros.s"

					global		FUNC(ft_isascii)

; int ft_isascii(int c);
					section		.text
FUNC(ft_isascii):	xor			eax, eax		; sets return value to 0
					is_inside	edi, 0, 127
					setbe		al
					ret
