	.file	"a.c"
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"in.txt"
.LC2:
	.string	"%d "
.LC3:
	.string	"--EOF--"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -8(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc@PLT
	movb	%al, -9(%rbp)
	movsbl	-9(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpb	$-1, -9(%rbp)
	jne	.L2
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
.L2:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	feof@PLT
	testl	%eax, %eax
	je	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
