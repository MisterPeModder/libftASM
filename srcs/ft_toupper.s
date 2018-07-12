%include			"macros.s"

					global		FUNC(ft_toupper)

; int ft_toupper(int c);
					section		.text
FUNC(ft_toupper):	mov			eax, edi			; sets return value to 0
					is_inside	edi, 'a', 'z'
					ja			FUNC(ft_toupper_e)
					and			eax, 0xffffffdf		; Uppercases c by unsetting the 6th bit.
FUNC(ft_toupper_e):	ret
