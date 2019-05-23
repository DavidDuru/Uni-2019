	.file	"week5.c"
	.text
.Ltext0:
	.comm	func,8,8
	.globl	main
	.type	main, @function
main:
.LFB0:
	.file 1 "week5.c"
	.loc 1 36 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 37 0
	movl	$0, %eax
	call	q6
	movl	$0, %eax
	.loc 1 38 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"Hello World\n"
.LC1:
	.string	"%p\n"
.LC2:
	.string	"%d\n"
	.text
	.globl	q1
	.type	q1, @function
q1:
.LFB1:
	.loc 1 40 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 42 0
	leaq	.LC0(%rip), %rax
	movq	%rax, -16(%rbp)
	.loc 1 43 0
	movq	stdout(%rip), %rax
	movq	%rax, -8(%rbp)
	.loc 1 44 0
	movq	stdout(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 45 0
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 46 0
	movq	-16(%rbp), %rax
	movl	$12, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	.loc 1 48 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	q1, .-q1
	.section	.rodata
.LC3:
	.string	"Seconds slept for %d\n"
	.text
	.globl	q5
	.type	q5, @function
q5:
.LFB2:
	.loc 1 50 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 51 0
	movl	$1, %esi
	movl	$2, %edi
	call	__sysv_signal@PLT
.L5:
.LBB2:
	.loc 1 53 0 discriminator 1
	movl	$1, %edi
	call	sleep@PLT
	movl	%eax, -4(%rbp)
	.loc 1 54 0 discriminator 1
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.LBE2:
	.loc 1 52 0 discriminator 1
	jmp	.L5
	.cfi_endproc
.LFE2:
	.size	q5, .-q5
	.globl	q6
	.type	q6, @function
q6:
.LFB3:
	.loc 1 59 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	.loc 1 60 0
	leaq	quitProgramHandler(%rip), %rsi
	movl	$2, %edi
	call	__sysv_signal@PLT
	.loc 1 61 0
	leaq	timeHandler(%rip), %rsi
	movl	$10, %edi
	call	__sysv_signal@PLT
.L7:
	.loc 1 62 0 discriminator 1
	jmp	.L7
	.cfi_endproc
.LFE3:
	.size	q6, .-q6
	.section	.rodata
.LC4:
	.string	"%a %Y-%m %H:%M:%S %Z"
	.text
	.globl	timeHandler
	.type	timeHandler, @function
timeHandler:
.LFB4:
	.loc 1 68 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	%edi, -116(%rbp)
	.loc 1 68 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 72 0
	movl	$0, %edi
	call	time@PLT
	movq	%rax, -112(%rbp)
	.loc 1 73 0
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	localtime@PLT
	movq	%rax, -104(%rbp)
	.loc 1 74 0
	movq	-104(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rcx
	leaq	.LC4(%rip), %rdx
	movl	$80, %esi
	movq	%rax, %rdi
	call	strftime@PLT
	.loc 1 75 0
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	.loc 1 76 0
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	timeHandler, .-timeHandler
	.section	.rodata
.LC5:
	.string	"Goodbye"
	.text
	.globl	quitProgramHandler
	.type	quitProgramHandler, @function
quitProgramHandler:
.LFB5:
	.loc 1 78 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	.loc 1 79 0
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	.loc 1 80 0
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE5:
	.size	quitProgramHandler, .-quitProgramHandler
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/x86_64-linux-gnu/bits/libio.h"
	.file 5 "/usr/include/stdio.h"
	.file 6 "/usr/include/unistd.h"
	.file 7 "/usr/include/signal.h"
	.file 8 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h"
	.file 9 "/usr/include/x86_64-linux-gnu/bits/types/struct_tm.h"
	.file 10 "/usr/include/time.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x566
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF77
	.byte	0xc
	.long	.LASF78
	.long	.LASF79
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF7
	.byte	0x2
	.byte	0xd8
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.long	.LASF8
	.byte	0x3
	.byte	0x8c
	.long	0x69
	.uleb128 0x2
	.long	.LASF9
	.byte	0x3
	.byte	0x8d
	.long	0x69
	.uleb128 0x2
	.long	.LASF10
	.byte	0x3
	.byte	0x94
	.long	0x69
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0x99
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF11
	.uleb128 0x7
	.long	0x99
	.uleb128 0x8
	.long	.LASF41
	.byte	0xd8
	.byte	0x4
	.byte	0xf5
	.long	0x225
	.uleb128 0x9
	.long	.LASF12
	.byte	0x4
	.byte	0xf6
	.long	0x62
	.byte	0
	.uleb128 0x9
	.long	.LASF13
	.byte	0x4
	.byte	0xfb
	.long	0x93
	.byte	0x8
	.uleb128 0x9
	.long	.LASF14
	.byte	0x4
	.byte	0xfc
	.long	0x93
	.byte	0x10
	.uleb128 0x9
	.long	.LASF15
	.byte	0x4
	.byte	0xfd
	.long	0x93
	.byte	0x18
	.uleb128 0x9
	.long	.LASF16
	.byte	0x4
	.byte	0xfe
	.long	0x93
	.byte	0x20
	.uleb128 0x9
	.long	.LASF17
	.byte	0x4
	.byte	0xff
	.long	0x93
	.byte	0x28
	.uleb128 0xa
	.long	.LASF18
	.byte	0x4
	.value	0x100
	.long	0x93
	.byte	0x30
	.uleb128 0xa
	.long	.LASF19
	.byte	0x4
	.value	0x101
	.long	0x93
	.byte	0x38
	.uleb128 0xa
	.long	.LASF20
	.byte	0x4
	.value	0x102
	.long	0x93
	.byte	0x40
	.uleb128 0xa
	.long	.LASF21
	.byte	0x4
	.value	0x104
	.long	0x93
	.byte	0x48
	.uleb128 0xa
	.long	.LASF22
	.byte	0x4
	.value	0x105
	.long	0x93
	.byte	0x50
	.uleb128 0xa
	.long	.LASF23
	.byte	0x4
	.value	0x106
	.long	0x93
	.byte	0x58
	.uleb128 0xa
	.long	.LASF24
	.byte	0x4
	.value	0x108
	.long	0x25d
	.byte	0x60
	.uleb128 0xa
	.long	.LASF25
	.byte	0x4
	.value	0x10a
	.long	0x263
	.byte	0x68
	.uleb128 0xa
	.long	.LASF26
	.byte	0x4
	.value	0x10c
	.long	0x62
	.byte	0x70
	.uleb128 0xa
	.long	.LASF27
	.byte	0x4
	.value	0x110
	.long	0x62
	.byte	0x74
	.uleb128 0xa
	.long	.LASF28
	.byte	0x4
	.value	0x112
	.long	0x70
	.byte	0x78
	.uleb128 0xa
	.long	.LASF29
	.byte	0x4
	.value	0x116
	.long	0x46
	.byte	0x80
	.uleb128 0xa
	.long	.LASF30
	.byte	0x4
	.value	0x117
	.long	0x54
	.byte	0x82
	.uleb128 0xa
	.long	.LASF31
	.byte	0x4
	.value	0x118
	.long	0x269
	.byte	0x83
	.uleb128 0xa
	.long	.LASF32
	.byte	0x4
	.value	0x11c
	.long	0x279
	.byte	0x88
	.uleb128 0xa
	.long	.LASF33
	.byte	0x4
	.value	0x125
	.long	0x7b
	.byte	0x90
	.uleb128 0xa
	.long	.LASF34
	.byte	0x4
	.value	0x12d
	.long	0x91
	.byte	0x98
	.uleb128 0xa
	.long	.LASF35
	.byte	0x4
	.value	0x12e
	.long	0x91
	.byte	0xa0
	.uleb128 0xa
	.long	.LASF36
	.byte	0x4
	.value	0x12f
	.long	0x91
	.byte	0xa8
	.uleb128 0xa
	.long	.LASF37
	.byte	0x4
	.value	0x130
	.long	0x91
	.byte	0xb0
	.uleb128 0xa
	.long	.LASF38
	.byte	0x4
	.value	0x132
	.long	0x2d
	.byte	0xb8
	.uleb128 0xa
	.long	.LASF39
	.byte	0x4
	.value	0x133
	.long	0x62
	.byte	0xc0
	.uleb128 0xa
	.long	.LASF40
	.byte	0x4
	.value	0x135
	.long	0x27f
	.byte	0xc4
	.byte	0
	.uleb128 0xb
	.long	.LASF80
	.byte	0x4
	.byte	0x9a
	.uleb128 0x8
	.long	.LASF42
	.byte	0x18
	.byte	0x4
	.byte	0xa0
	.long	0x25d
	.uleb128 0x9
	.long	.LASF43
	.byte	0x4
	.byte	0xa1
	.long	0x25d
	.byte	0
	.uleb128 0x9
	.long	.LASF44
	.byte	0x4
	.byte	0xa2
	.long	0x263
	.byte	0x8
	.uleb128 0x9
	.long	.LASF45
	.byte	0x4
	.byte	0xa6
	.long	0x62
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x22c
	.uleb128 0x6
	.byte	0x8
	.long	0xa5
	.uleb128 0xc
	.long	0x99
	.long	0x279
	.uleb128 0xd
	.long	0x38
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x225
	.uleb128 0xc
	.long	0x99
	.long	0x28f
	.uleb128 0xd
	.long	0x38
	.byte	0x13
	.byte	0
	.uleb128 0xe
	.long	.LASF81
	.uleb128 0xf
	.long	.LASF46
	.byte	0x4
	.value	0x13f
	.long	0x28f
	.uleb128 0xf
	.long	.LASF47
	.byte	0x4
	.value	0x140
	.long	0x28f
	.uleb128 0xf
	.long	.LASF48
	.byte	0x4
	.value	0x141
	.long	0x28f
	.uleb128 0x6
	.byte	0x8
	.long	0xa0
	.uleb128 0x10
	.long	.LASF49
	.byte	0x5
	.byte	0x87
	.long	0x263
	.uleb128 0x10
	.long	.LASF50
	.byte	0x5
	.byte	0x88
	.long	0x263
	.uleb128 0x10
	.long	.LASF51
	.byte	0x5
	.byte	0x89
	.long	0x263
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF52
	.uleb128 0xf
	.long	.LASF53
	.byte	0x6
	.value	0x222
	.long	0x2f2
	.uleb128 0x6
	.byte	0x8
	.long	0x93
	.uleb128 0x2
	.long	.LASF54
	.byte	0x7
	.byte	0x48
	.long	0x303
	.uleb128 0x6
	.byte	0x8
	.long	0x309
	.uleb128 0x11
	.long	0x314
	.uleb128 0x12
	.long	0x62
	.byte	0
	.uleb128 0x2
	.long	.LASF55
	.byte	0x8
	.byte	0x7
	.long	0x86
	.uleb128 0x13
	.string	"tm"
	.byte	0x38
	.byte	0x9
	.byte	0x7
	.long	0x3af
	.uleb128 0x9
	.long	.LASF56
	.byte	0x9
	.byte	0x9
	.long	0x62
	.byte	0
	.uleb128 0x9
	.long	.LASF57
	.byte	0x9
	.byte	0xa
	.long	0x62
	.byte	0x4
	.uleb128 0x9
	.long	.LASF58
	.byte	0x9
	.byte	0xb
	.long	0x62
	.byte	0x8
	.uleb128 0x9
	.long	.LASF59
	.byte	0x9
	.byte	0xc
	.long	0x62
	.byte	0xc
	.uleb128 0x9
	.long	.LASF60
	.byte	0x9
	.byte	0xd
	.long	0x62
	.byte	0x10
	.uleb128 0x9
	.long	.LASF61
	.byte	0x9
	.byte	0xe
	.long	0x62
	.byte	0x14
	.uleb128 0x9
	.long	.LASF62
	.byte	0x9
	.byte	0xf
	.long	0x62
	.byte	0x18
	.uleb128 0x9
	.long	.LASF63
	.byte	0x9
	.byte	0x10
	.long	0x62
	.byte	0x1c
	.uleb128 0x9
	.long	.LASF64
	.byte	0x9
	.byte	0x11
	.long	0x62
	.byte	0x20
	.uleb128 0x9
	.long	.LASF65
	.byte	0x9
	.byte	0x17
	.long	0x69
	.byte	0x28
	.uleb128 0x9
	.long	.LASF66
	.byte	0x9
	.byte	0x18
	.long	0x2b8
	.byte	0x30
	.byte	0
	.uleb128 0xc
	.long	0x93
	.long	0x3bf
	.uleb128 0xd
	.long	0x38
	.byte	0x1
	.byte	0
	.uleb128 0x10
	.long	.LASF67
	.byte	0xa
	.byte	0x9f
	.long	0x3af
	.uleb128 0x10
	.long	.LASF68
	.byte	0xa
	.byte	0xa0
	.long	0x62
	.uleb128 0x10
	.long	.LASF69
	.byte	0xa
	.byte	0xa1
	.long	0x69
	.uleb128 0x14
	.long	0x3e7
	.uleb128 0x15
	.byte	0
	.uleb128 0x16
	.long	.LASF70
	.byte	0x1
	.byte	0x22
	.long	0x3fc
	.uleb128 0x9
	.byte	0x3
	.quad	func
	.uleb128 0x6
	.byte	0x8
	.long	0x3e0
	.uleb128 0x17
	.long	.LASF71
	.byte	0x1
	.byte	0x4e
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.long	0x42e
	.uleb128 0x18
	.string	"sig"
	.byte	0x1
	.byte	0x4e
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x17
	.long	.LASF72
	.byte	0x1
	.byte	0x44
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x487
	.uleb128 0x18
	.string	"sig"
	.byte	0x1
	.byte	0x44
	.long	0x62
	.uleb128 0x3
	.byte	0x91
	.sleb128 -132
	.uleb128 0x19
	.string	"now"
	.byte	0x1
	.byte	0x45
	.long	0x314
	.uleb128 0x3
	.byte	0x91
	.sleb128 -128
	.uleb128 0x19
	.string	"ts"
	.byte	0x1
	.byte	0x46
	.long	0x487
	.uleb128 0x3
	.byte	0x91
	.sleb128 -120
	.uleb128 0x19
	.string	"buf"
	.byte	0x1
	.byte	0x47
	.long	0x48d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x31f
	.uleb128 0xc
	.long	0x99
	.long	0x49d
	.uleb128 0xd
	.long	0x38
	.byte	0x4f
	.byte	0
	.uleb128 0x1a
	.string	"q6"
	.byte	0x1
	.byte	0x3b
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1b
	.string	"q5"
	.byte	0x1
	.byte	0x32
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x4f2
	.uleb128 0x1c
	.quad	.LBB2
	.quad	.LBE2-.LBB2
	.uleb128 0x1d
	.long	.LASF73
	.byte	0x1
	.byte	0x35
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.uleb128 0x1b
	.string	"q1"
	.byte	0x1
	.byte	0x28
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x529
	.uleb128 0x19
	.string	"str"
	.byte	0x1
	.byte	0x2a
	.long	0x93
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x19
	.string	"p"
	.byte	0x1
	.byte	0x2b
	.long	0x529
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x62
	.uleb128 0x1e
	.long	.LASF74
	.byte	0x1
	.byte	0x24
	.long	0x62
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1f
	.long	.LASF75
	.byte	0x1
	.byte	0x24
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1f
	.long	.LASF76
	.byte	0x1
	.byte	0x24
	.long	0x2f2
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF78:
	.string	"week5.c"
.LASF28:
	.string	"_old_offset"
.LASF72:
	.string	"timeHandler"
.LASF23:
	.string	"_IO_save_end"
.LASF5:
	.string	"short int"
.LASF7:
	.string	"size_t"
.LASF33:
	.string	"_offset"
.LASF67:
	.string	"__tzname"
.LASF17:
	.string	"_IO_write_ptr"
.LASF12:
	.string	"_flags"
.LASF47:
	.string	"_IO_2_1_stdout_"
.LASF53:
	.string	"__environ"
.LASF24:
	.string	"_markers"
.LASF14:
	.string	"_IO_read_end"
.LASF66:
	.string	"__tm_zone"
.LASF29:
	.string	"_cur_column"
.LASF55:
	.string	"time_t"
.LASF58:
	.string	"tm_hour"
.LASF51:
	.string	"stderr"
.LASF52:
	.string	"long long int"
.LASF79:
	.string	"/home/aidan/Uni/Uni - Sem 1 - 2019/COMP2017"
.LASF69:
	.string	"__timezone"
.LASF32:
	.string	"_lock"
.LASF68:
	.string	"__daylight"
.LASF6:
	.string	"long int"
.LASF77:
	.string	"GNU C11 7.3.0 -mtune=generic -march=x86-64 -g -std=c11 -fstack-protector-strong"
.LASF48:
	.string	"_IO_2_1_stderr_"
.LASF81:
	.string	"_IO_FILE_plus"
.LASF45:
	.string	"_pos"
.LASF65:
	.string	"__tm_gmtoff"
.LASF76:
	.string	"argv"
.LASF44:
	.string	"_sbuf"
.LASF71:
	.string	"quitProgramHandler"
.LASF1:
	.string	"unsigned char"
.LASF62:
	.string	"tm_wday"
.LASF9:
	.string	"__off64_t"
.LASF70:
	.string	"func"
.LASF75:
	.string	"argc"
.LASF54:
	.string	"__sighandler_t"
.LASF4:
	.string	"signed char"
.LASF60:
	.string	"tm_mon"
.LASF46:
	.string	"_IO_2_1_stdin_"
.LASF3:
	.string	"unsigned int"
.LASF42:
	.string	"_IO_marker"
.LASF31:
	.string	"_shortbuf"
.LASF59:
	.string	"tm_mday"
.LASF16:
	.string	"_IO_write_base"
.LASF36:
	.string	"__pad3"
.LASF20:
	.string	"_IO_buf_end"
.LASF61:
	.string	"tm_year"
.LASF73:
	.string	"seconds"
.LASF11:
	.string	"char"
.LASF41:
	.string	"_IO_FILE"
.LASF74:
	.string	"main"
.LASF63:
	.string	"tm_yday"
.LASF34:
	.string	"__pad1"
.LASF35:
	.string	"__pad2"
.LASF43:
	.string	"_next"
.LASF37:
	.string	"__pad4"
.LASF38:
	.string	"__pad5"
.LASF57:
	.string	"tm_min"
.LASF2:
	.string	"short unsigned int"
.LASF64:
	.string	"tm_isdst"
.LASF0:
	.string	"long unsigned int"
.LASF18:
	.string	"_IO_write_end"
.LASF10:
	.string	"__time_t"
.LASF25:
	.string	"_chain"
.LASF8:
	.string	"__off_t"
.LASF22:
	.string	"_IO_backup_base"
.LASF49:
	.string	"stdin"
.LASF19:
	.string	"_IO_buf_base"
.LASF27:
	.string	"_flags2"
.LASF39:
	.string	"_mode"
.LASF15:
	.string	"_IO_read_base"
.LASF30:
	.string	"_vtable_offset"
.LASF40:
	.string	"_unused2"
.LASF21:
	.string	"_IO_save_base"
.LASF56:
	.string	"tm_sec"
.LASF26:
	.string	"_fileno"
.LASF13:
	.string	"_IO_read_ptr"
.LASF50:
	.string	"stdout"
.LASF80:
	.string	"_IO_lock_t"
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
