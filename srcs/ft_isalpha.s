%include			"macros.s"

					global		FUNC(ft_isalpha)

; int ft_isalpha(int c);
					section		.text
FUNC(ft_isalpha):	mov			r8d, edi
					is_inside	edi, 'a', 'z'
					jbe			.done
					is_inside	r8d, 'A', 'Z'
					jbe			.done
					ret_false
.done:				ret_true	
