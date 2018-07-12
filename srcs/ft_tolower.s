%include			"macros.s"

					global		FUNC(ft_tolower)

; int ft_tolower(int c);
					section		.text
FUNC(ft_tolower):	mov			eax, edi			; sets return value to 0
					is_inside	edi, 'A', 'Z'
					ja			FUNC(ft_tolower_e)
					or			eax, 0x20			; lowercases eax by setting 6th bit.
FUNC(ft_tolower_e):	ret
