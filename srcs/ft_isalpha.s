%include			"macros.s"

					global		FUNC(ft_isalpha)

; int ft_isalpha(int c);
					section		.text
FUNC(ft_isalpha):	and			edi, 0xffffffdf	; Uppercases c by unsetting the 6th bit.
					xor			eax, eax		; sets return value to 0
					is_inside	edi, 'A', 'Z'
					setbe		al				; sets eax if 'A' >= c && c <= 'Z'
					ret							
