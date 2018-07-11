%include			"macros.s"

					global		FUNC(ft_isdigit)

; int ft_isdigit(int c);
					section		.text
FUNC(ft_isdigit):	xor			eax, eax		; sets return value to 0
					is_inside	edi, '0', '9'
					setbe		al
					ret
