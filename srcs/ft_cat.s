%include			"macros.s"
%define				BUFF_SIZE	512						; buffer size (in bits), must be a multiple of 16.

					global		FUNC(ft_cat)

					section		.text
; void ft_cat(int fd);
FUNC(ft_cat):		push		rbp						; Function prologue
					mov			rbp, rsp
					sub			rsp, BUFF_SIZE			; reserve space for buffer
					push		rdi						; save file descriptor
					lea			rsi, [rsp + 8]			; set rsi to buffer address
FUNC(ft_cat_rdbuf):	mov			rdx, BUFF_SIZE
					mov			rdi, qword [rsp]
					mov			rax, SYSCALL_READ_ID	; read(fd, buff, 512);
					syscall
					cmp			rax, -4095
					jae			FUNC(ft_cat_end)		; if read() failed, return
					mov			rdx, rax
					mov			rax, SYSCALL_WRITE_ID	; write(1, buff, read_size);
					mov			rdi, 1
					syscall
					cmp			rax, -4095
					jae			FUNC(ft_cat_end)		; if write() failed, return
					cmp			rax, BUFF_SIZE
					je			FUNC(ft_cat_rdbuf)
FUNC(ft_cat_end):	mov			rsp, rbp				; Function epilogue
					pop			rbp
					ret
