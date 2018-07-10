%include			"macros.s"

					global		FUNC(ft_isprint)

; int ft_isprint(int c);
					section		.text
FUNC(ft_isprint):	is_inside	edi, 32, 126
					jbe			.done
					ret_false
.done:				ret_true	
