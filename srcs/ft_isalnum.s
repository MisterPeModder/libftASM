%include			"macros.s"

					global		FUNC(ft_isalnum)

; int ft_isalnum(int c);
					section		.text
FUNC(ft_isalnum):	mov			ecx, edi
					xor			edx, edx
					is_inside	ecx, '0', '9'
					setbe		dl				; stores result of '0' >= c && c <= '9'
					and			edi, 0xffffffdf	; Uppercases c by unsetting the 6th bit.
					xor			eax, eax		; sets return value to 0
					is_inside	edi, 'A', 'Z'
					setbe		al				; sets eax if 'A' >= c && c <= 'Z'
					or			al, dl
					ret
