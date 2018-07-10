%include	"macros.s"

			global		PRG_START
			global		FUNC(main)

			section		.text
PRG_START:	call		FUNC(main)
			ret

FUNC(main):	sys_exit	133
			ret
