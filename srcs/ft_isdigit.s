%include			"macros.s"

					global		FUNC(ft_isdigit)

; int ft_isdigit(int c);
					section		.text
FUNC(ft_isdigit):	is_inside	edi, '0', '9'
					jbe			.done
					ret_false
.done:				ret_true	
