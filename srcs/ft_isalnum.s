%include			"macros.s"

					global		FUNC(ft_isalnum)

; int ft_isalnum(int c);
					section		.text
FUNC(ft_isalnum):	mov			r8d, edi
					mov			r9d, edi
					is_inside	edi, '0', '9'
					jbe			.done
					is_inside	r8d, 'a', 'z'
					jbe			.done
					is_inside	r9d, 'A', 'Z'
					jbe			.done
					ret_false
.done:				ret_true	
