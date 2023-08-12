
cortex_m4_lab4.elf:     file format elf32-littlearm


Disassembly of section .text:

00000000 <g_p_fn_vectors>:
   0:	20000404 	andcs	r0, r0, r4, lsl #8
   4:	00000149 	andeq	r0, r0, r9, asr #2
   8:	0000013d 	andeq	r0, r0, sp, lsr r1
   c:	0000013d 	andeq	r0, r0, sp, lsr r1
  10:	0000013d 	andeq	r0, r0, sp, lsr r1
  14:	0000013d 	andeq	r0, r0, sp, lsr r1
  18:	0000013d 	andeq	r0, r0, sp, lsr r1

0000001c <main>:
  1c:	b480      	push	{r7}
  1e:	af00      	add	r7, sp, #0
  20:	f24e 1308 	movw	r3, #57608	; 0xe108
  24:	f2c4 030f 	movt	r3, #16399	; 0x400f
  28:	f04f 0220 	mov.w	r2, #32
  2c:	601a      	str	r2, [r3, #0]
  2e:	f240 0300 	movw	r3, #0
  32:	f2c2 0300 	movt	r3, #8192	; 0x2000
  36:	f04f 0200 	mov.w	r2, #0
  3a:	601a      	str	r2, [r3, #0]
  3c:	e00b      	b.n	56 <main+0x3a>
  3e:	f240 0300 	movw	r3, #0
  42:	f2c2 0300 	movt	r3, #8192	; 0x2000
  46:	681b      	ldr	r3, [r3, #0]
  48:	f103 0201 	add.w	r2, r3, #1
  4c:	f240 0300 	movw	r3, #0
  50:	f2c2 0300 	movt	r3, #8192	; 0x2000
  54:	601a      	str	r2, [r3, #0]
  56:	f240 0300 	movw	r3, #0
  5a:	f2c2 0300 	movt	r3, #8192	; 0x2000
  5e:	681b      	ldr	r3, [r3, #0]
  60:	2bc7      	cmp	r3, #199	; 0xc7
  62:	d9ec      	bls.n	3e <main+0x22>
  64:	f44f 43a8 	mov.w	r3, #21504	; 0x5400
  68:	f2c4 0302 	movt	r3, #16386	; 0x4002
  6c:	f44f 42a8 	mov.w	r2, #21504	; 0x5400
  70:	f2c4 0202 	movt	r2, #16386	; 0x4002
  74:	6812      	ldr	r2, [r2, #0]
  76:	f042 0208 	orr.w	r2, r2, #8
  7a:	601a      	str	r2, [r3, #0]
  7c:	f245 531c 	movw	r3, #21788	; 0x551c
  80:	f2c4 0302 	movt	r3, #16386	; 0x4002
  84:	f245 521c 	movw	r2, #21788	; 0x551c
  88:	f2c4 0202 	movt	r2, #16386	; 0x4002
  8c:	6812      	ldr	r2, [r2, #0]
  8e:	f042 0208 	orr.w	r2, r2, #8
  92:	601a      	str	r2, [r3, #0]
  94:	f245 33fc 	movw	r3, #21500	; 0x53fc
  98:	f2c4 0302 	movt	r3, #16386	; 0x4002
  9c:	f245 32fc 	movw	r2, #21500	; 0x53fc
  a0:	f2c4 0202 	movt	r2, #16386	; 0x4002
  a4:	6812      	ldr	r2, [r2, #0]
  a6:	f042 0208 	orr.w	r2, r2, #8
  aa:	601a      	str	r2, [r3, #0]
  ac:	f240 0300 	movw	r3, #0
  b0:	f2c2 0300 	movt	r3, #8192	; 0x2000
  b4:	f04f 0200 	mov.w	r2, #0
  b8:	601a      	str	r2, [r3, #0]
  ba:	e00b      	b.n	d4 <main+0xb8>
  bc:	f240 0300 	movw	r3, #0
  c0:	f2c2 0300 	movt	r3, #8192	; 0x2000
  c4:	681b      	ldr	r3, [r3, #0]
  c6:	f103 0201 	add.w	r2, r3, #1
  ca:	f240 0300 	movw	r3, #0
  ce:	f2c2 0300 	movt	r3, #8192	; 0x2000
  d2:	601a      	str	r2, [r3, #0]
  d4:	f240 0300 	movw	r3, #0
  d8:	f2c2 0300 	movt	r3, #8192	; 0x2000
  dc:	681a      	ldr	r2, [r3, #0]
  de:	f644 631f 	movw	r3, #19999	; 0x4e1f
  e2:	429a      	cmp	r2, r3
  e4:	d9ea      	bls.n	bc <main+0xa0>
  e6:	f245 33fc 	movw	r3, #21500	; 0x53fc
  ea:	f2c4 0302 	movt	r3, #16386	; 0x4002
  ee:	f245 32fc 	movw	r2, #21500	; 0x53fc
  f2:	f2c4 0202 	movt	r2, #16386	; 0x4002
  f6:	6812      	ldr	r2, [r2, #0]
  f8:	f022 0208 	bic.w	r2, r2, #8
  fc:	601a      	str	r2, [r3, #0]
  fe:	f240 0300 	movw	r3, #0
 102:	f2c2 0300 	movt	r3, #8192	; 0x2000
 106:	f04f 0200 	mov.w	r2, #0
 10a:	601a      	str	r2, [r3, #0]
 10c:	e00b      	b.n	126 <main+0x10a>
 10e:	f240 0300 	movw	r3, #0
 112:	f2c2 0300 	movt	r3, #8192	; 0x2000
 116:	681b      	ldr	r3, [r3, #0]
 118:	f103 0201 	add.w	r2, r3, #1
 11c:	f240 0300 	movw	r3, #0
 120:	f2c2 0300 	movt	r3, #8192	; 0x2000
 124:	601a      	str	r2, [r3, #0]
 126:	f240 0300 	movw	r3, #0
 12a:	f2c2 0300 	movt	r3, #8192	; 0x2000
 12e:	681a      	ldr	r2, [r3, #0]
 130:	f247 532f 	movw	r3, #29999	; 0x752f
 134:	429a      	cmp	r2, r3
 136:	d9ea      	bls.n	10e <main+0xf2>
 138:	e7ac      	b.n	94 <main+0x78>
 13a:	bf00      	nop

0000013c <Default_Hundler>:
 13c:	b580      	push	{r7, lr}
 13e:	af00      	add	r7, sp, #0
 140:	f000 f802 	bl	148 <Reset_Hundler>
 144:	bd80      	pop	{r7, pc}
 146:	bf00      	nop

00000148 <Reset_Hundler>:
 148:	b580      	push	{r7, lr}
 14a:	b086      	sub	sp, #24
 14c:	af00      	add	r7, sp, #0
 14e:	f240 0200 	movw	r2, #0
 152:	f2c2 0200 	movt	r2, #8192	; 0x2000
 156:	f240 0300 	movw	r3, #0
 15a:	f2c2 0300 	movt	r3, #8192	; 0x2000
 15e:	1ad3      	subs	r3, r2, r3
 160:	60bb      	str	r3, [r7, #8]
 162:	f240 13f8 	movw	r3, #504	; 0x1f8
 166:	f2c0 0300 	movt	r3, #0
 16a:	617b      	str	r3, [r7, #20]
 16c:	f240 0300 	movw	r3, #0
 170:	f2c2 0300 	movt	r3, #8192	; 0x2000
 174:	613b      	str	r3, [r7, #16]
 176:	f04f 0300 	mov.w	r3, #0
 17a:	60fb      	str	r3, [r7, #12]
 17c:	e00f      	b.n	19e <Reset_Hundler+0x56>
 17e:	697b      	ldr	r3, [r7, #20]
 180:	781a      	ldrb	r2, [r3, #0]
 182:	693b      	ldr	r3, [r7, #16]
 184:	701a      	strb	r2, [r3, #0]
 186:	693b      	ldr	r3, [r7, #16]
 188:	f103 0301 	add.w	r3, r3, #1
 18c:	613b      	str	r3, [r7, #16]
 18e:	697b      	ldr	r3, [r7, #20]
 190:	f103 0301 	add.w	r3, r3, #1
 194:	617b      	str	r3, [r7, #20]
 196:	68fb      	ldr	r3, [r7, #12]
 198:	f103 0301 	add.w	r3, r3, #1
 19c:	60fb      	str	r3, [r7, #12]
 19e:	68fa      	ldr	r2, [r7, #12]
 1a0:	68bb      	ldr	r3, [r7, #8]
 1a2:	429a      	cmp	r2, r3
 1a4:	d3eb      	bcc.n	17e <Reset_Hundler+0x36>
 1a6:	f240 4204 	movw	r2, #1028	; 0x404
 1aa:	f2c2 0200 	movt	r2, #8192	; 0x2000
 1ae:	f240 0300 	movw	r3, #0
 1b2:	f2c2 0300 	movt	r3, #8192	; 0x2000
 1b6:	1ad3      	subs	r3, r2, r3
 1b8:	607b      	str	r3, [r7, #4]
 1ba:	f240 0300 	movw	r3, #0
 1be:	f2c2 0300 	movt	r3, #8192	; 0x2000
 1c2:	613b      	str	r3, [r7, #16]
 1c4:	f04f 0300 	mov.w	r3, #0
 1c8:	60fb      	str	r3, [r7, #12]
 1ca:	e00b      	b.n	1e4 <Reset_Hundler+0x9c>
 1cc:	693b      	ldr	r3, [r7, #16]
 1ce:	f04f 0200 	mov.w	r2, #0
 1d2:	701a      	strb	r2, [r3, #0]
 1d4:	693b      	ldr	r3, [r7, #16]
 1d6:	f103 0301 	add.w	r3, r3, #1
 1da:	613b      	str	r3, [r7, #16]
 1dc:	68fb      	ldr	r3, [r7, #12]
 1de:	f103 0301 	add.w	r3, r3, #1
 1e2:	60fb      	str	r3, [r7, #12]
 1e4:	68fa      	ldr	r2, [r7, #12]
 1e6:	687b      	ldr	r3, [r7, #4]
 1e8:	429a      	cmp	r2, r3
 1ea:	d3ef      	bcc.n	1cc <Reset_Hundler+0x84>
 1ec:	f7ff ff16 	bl	1c <main>
 1f0:	f107 0718 	add.w	r7, r7, #24
 1f4:	46bd      	mov	sp, r7
 1f6:	bd80      	pop	{r7, pc}

Disassembly of section .bss:

20000000 <_S_BSS>:
20000000:	00000000 	andeq	r0, r0, r0

20000004 <Stack_Top>:
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000a8 	andeq	r0, r0, r8, lsr #1
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000001a 	andeq	r0, r0, sl, lsl r0
  10:	00000e01 	andeq	r0, r0, r1, lsl #28
  14:	00002600 	andeq	r2, r0, r0, lsl #12
  18:	00001c00 	andeq	r1, r0, r0, lsl #24
  1c:	00013a00 	andeq	r3, r1, r0, lsl #20
  20:	00000000 	andeq	r0, r0, r0
  24:	07040200 	streq	r0, [r4, -r0, lsl #4]
  28:	0000005d 	andeq	r0, r0, sp, asr r0
  2c:	6c060102 	stfvss	f0, [r6], {2}
  30:	02000000 	andeq	r0, r0, #0
  34:	006a0801 	rsbeq	r0, sl, r1, lsl #16
  38:	02020000 	andeq	r0, r2, #0
  3c:	00008b05 	andeq	r8, r0, r5, lsl #22
  40:	07020200 	streq	r0, [r2, -r0, lsl #4]
  44:	00000078 	andeq	r0, r0, r8, ror r0
  48:	69050403 	stmdbvs	r5, {r0, r1, sl}
  4c:	0200746e 	andeq	r7, r0, #1845493760	; 0x6e000000
  50:	00000508 	andeq	r0, r0, r8, lsl #10
  54:	08020000 	stmdaeq	r2, {}	; <UNPREDICTABLE>
  58:	00005307 	andeq	r5, r0, r7, lsl #6
  5c:	05040200 	streq	r0, [r4, #-512]	; 0x200
  60:	00000005 	andeq	r0, r0, r5
  64:	95070402 	strls	r0, [r7, #-1026]	; 0x402
  68:	02000000 	andeq	r0, r0, #0
  6c:	00580704 	subseq	r0, r8, r4, lsl #14
  70:	01020000 	mrseq	r0, (UNDEF: 2)
  74:	00007308 	andeq	r7, r0, r8, lsl #6
  78:	15010400 	strne	r0, [r1, #-1024]	; 0x400
  7c:	01000000 	mrseq	r0, (UNDEF: 0)
  80:	0000480a 	andeq	r4, r0, sl, lsl #16
  84:	00001c00 	andeq	r1, r0, r0, lsl #24
  88:	00013a00 	andeq	r3, r1, r0, lsl #20
  8c:	00000000 	andeq	r0, r0, r0
  90:	00a60100 	adceq	r0, r6, r0, lsl #2
  94:	69050000 	stmdbvs	r5, {}	; <UNPREDICTABLE>
  98:	a60e0100 	strge	r0, [lr], -r0, lsl #2
  9c:	05000000 	streq	r0, [r0, #-0]
  a0:	00000003 	andeq	r0, r0, r3
  a4:	6b060020 	blvs	18012c <_E_TEXT+0x17ff34>
  a8:	00000000 	andeq	r0, r0, r0
  ac:	0000014e 	andeq	r0, r0, lr, asr #2
  b0:	005a0002 	subseq	r0, sl, r2
  b4:	01040000 	mrseq	r0, (UNDEF: 4)
  b8:	0000001a 	andeq	r0, r0, sl, lsl r0
  bc:	0000cc01 	andeq	ip, r0, r1, lsl #24
  c0:	00002600 	andeq	r2, r0, r0, lsl #12
  c4:	00013c00 	andeq	r3, r1, r0, lsl #24
  c8:	0001f800 	andeq	pc, r1, r0, lsl #16
  cc:	00006300 	andeq	r6, r0, r0, lsl #6
  d0:	bc010200 	sfmlt	f0, 4, [r1], {-0}
  d4:	01000000 	mrseq	r0, (UNDEF: 0)
  d8:	00013c07 	andeq	r3, r1, r7, lsl #24
  dc:	00014600 	andeq	r4, r1, r0, lsl #12
  e0:	00002c00 	andeq	r2, r0, r0, lsl #24
  e4:	01030100 	mrseq	r0, (UNDEF: 19)
  e8:	0000010f 	andeq	r0, r0, pc, lsl #2
  ec:	48012701 	stmdami	r1, {r0, r8, r9, sl, sp}
  f0:	f8000001 			; <UNDEFINED> instruction: 0xf8000001
  f4:	58000001 	stmdapl	r0, {r0}
  f8:	01000000 	mrseq	r0, (UNDEF: 0)
  fc:	00000099 	muleq	r0, r9, r0
 100:	0000e504 	andeq	lr, r0, r4, lsl #10
 104:	992a0100 	stmdbls	sl!, {r8}
 108:	02000000 	andeq	r0, r0, #0
 10c:	d6046891 			; <UNDEFINED> instruction: 0xd6046891
 110:	01000000 	mrseq	r0, (UNDEF: 0)
 114:	0000a02b 	andeq	sl, r0, fp, lsr #32
 118:	74910200 	ldrvc	r0, [r1], #512	; 0x200
 11c:	0000b604 	andeq	fp, r0, r4, lsl #12
 120:	a02c0100 	eorge	r0, ip, r0, lsl #2
 124:	02000000 	andeq	r0, r0, #0
 128:	69057091 	stmdbvs	r5, {r0, r4, r7, ip, sp, lr}
 12c:	ad2d0100 	stfges	f0, [sp, #-0]
 130:	02000000 	andeq	r0, r0, #0
 134:	dc046c91 	stcle	12, cr6, [r4], {145}	; 0x91
 138:	01000000 	mrseq	r0, (UNDEF: 0)
 13c:	00009934 	andeq	r9, r0, r4, lsr r9
 140:	64910200 	ldrvs	r0, [r1], #512	; 0x200
 144:	07040600 	streq	r0, [r4, -r0, lsl #12]
 148:	0000005d 	andeq	r0, r0, sp, asr r0
 14c:	00a60407 	adceq	r0, r6, r7, lsl #8
 150:	01060000 	mrseq	r0, (UNDEF: 6)
 154:	00006a08 	andeq	r6, r0, r8, lsl #20
 158:	05040800 	streq	r0, [r4, #-2048]	; 0x800
 15c:	00746e69 	rsbseq	r6, r4, r9, ror #28
 160:	00009909 	andeq	r9, r0, r9, lsl #18
 164:	0000c400 	andeq	ip, r0, r0, lsl #8
 168:	00c40a00 	sbceq	r0, r4, r0, lsl #20
 16c:	00ff0000 	rscseq	r0, pc, r0
 170:	95070406 	strls	r0, [r7, #-1030]	; 0x406
 174:	04000000 	streq	r0, [r0], #-0
 178:	000000ef 	andeq	r0, r0, pc, ror #1
 17c:	00b41201 	adcseq	r1, r4, r1, lsl #4
 180:	03050000 	movweq	r0, #20480	; 0x5000
 184:	20000004 	andcs	r0, r0, r4
 188:	0000f309 	andeq	pc, r0, r9, lsl #6
 18c:	0000ec00 	andeq	lr, r0, r0, lsl #24
 190:	00c40a00 	sbceq	r0, r4, r0, lsl #20
 194:	00060000 	andeq	r0, r6, r0
 198:	0000f30b 	andeq	pc, r0, fp, lsl #6
 19c:	07000c00 	streq	r0, [r0, -r0, lsl #24]
 1a0:	0000ec04 	andeq	lr, r0, r4, lsl #24
 1a4:	01000d00 	tsteq	r0, r0, lsl #26
 1a8:	15010000 	strne	r0, [r1, #-0]
 1ac:	0000010b 	andeq	r0, r0, fp, lsl #2
 1b0:	00030501 	andeq	r0, r3, r1, lsl #10
 1b4:	0e000000 	cdpeq	0, 0, cr0, cr0, cr0, {0}
 1b8:	000000dc 	ldrdeq	r0, [r0], -ip
 1bc:	00009e0f 	andeq	r9, r0, pc, lsl #28
 1c0:	99210100 	stmdbls	r1!, {r8}
 1c4:	01000000 	mrseq	r0, (UNDEF: 0)
 1c8:	00ae0f01 	adceq	r0, lr, r1, lsl #30
 1cc:	22010000 	andcs	r0, r1, #0
 1d0:	00000099 	muleq	r0, r9, r0
 1d4:	a60f0101 	strge	r0, [pc], -r1, lsl #2
 1d8:	01000000 	mrseq	r0, (UNDEF: 0)
 1dc:	00009923 	andeq	r9, r0, r3, lsr #18
 1e0:	0f010100 	svceq	0x00010100
 1e4:	0000011d 	andeq	r0, r0, sp, lsl r1
 1e8:	00992401 	addseq	r2, r9, r1, lsl #8
 1ec:	01010000 	mrseq	r0, (UNDEF: 1)
 1f0:	0000f90f 	andeq	pc, r0, pc, lsl #18
 1f4:	99250100 	stmdbls	r5!, {r8}
 1f8:	01000000 	mrseq	r0, (UNDEF: 0)
 1fc:	Address 0x000001fc is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0b0b0024 	bleq	2c00ac <_E_TEXT+0x2bfeb4>
  18:	0e030b3e 	vmoveq.16	d3[0], r0
  1c:	24030000 	strcs	r0, [r3], #-0
  20:	3e0b0b00 	vmlacc.f64	d0, d11, d0
  24:	0008030b 	andeq	r0, r8, fp, lsl #6
  28:	012e0400 	teqeq	lr, r0, lsl #8
  2c:	0e030c3f 	mcreq	12, 0, r0, cr3, cr15, {1}
  30:	0b3b0b3a 	bleq	ec2d20 <_E_TEXT+0xec2b28>
  34:	01111349 	tsteq	r1, r9, asr #6
  38:	06400112 			; <UNDEFINED> instruction: 0x06400112
  3c:	010c4297 			; <UNDEFINED> instruction: 0x010c4297
  40:	05000013 	streq	r0, [r0, #-19]
  44:	08030034 	stmdaeq	r3, {r2, r4, r5}
  48:	0b3b0b3a 	bleq	ec2d38 <_E_TEXT+0xec2b40>
  4c:	0a021349 	beq	84d78 <_E_TEXT+0x84b80>
  50:	35060000 	strcc	r0, [r6, #-0]
  54:	00134900 	andseq	r4, r3, r0, lsl #18
  58:	11010000 	mrsne	r0, (UNDEF: 1)
  5c:	130e2501 	movwne	r2, #58625	; 0xe501
  60:	1b0e030b 	blne	380c94 <_E_TEXT+0x380a9c>
  64:	1201110e 	andne	r1, r1, #-2147483645	; 0x80000003
  68:	00061001 	andeq	r1, r6, r1
  6c:	002e0200 	eoreq	r0, lr, r0, lsl #4
  70:	0e030c3f 	mcreq	12, 0, r0, cr3, cr15, {1}
  74:	0b3b0b3a 	bleq	ec2d64 <_E_TEXT+0xec2b6c>
  78:	01120111 	tsteq	r2, r1, lsl r1
  7c:	42960640 	addsmi	r0, r6, #64, 12	; 0x4000000
  80:	0300000c 	movweq	r0, #12
  84:	0c3f012e 	ldfeqs	f0, [pc], #-184	; ffffffd4 <_E_BSS+0xdffffbd0>
  88:	0b3a0e03 	bleq	e8389c <_E_TEXT+0xe836a4>
  8c:	0c270b3b 	stceq	11, cr0, [r7], #-236	; 0xffffff14
  90:	01120111 	tsteq	r2, r1, lsl r1
  94:	42960640 	addsmi	r0, r6, #64, 12	; 0x4000000
  98:	0013010c 	andseq	r0, r3, ip, lsl #2
  9c:	00340400 	eorseq	r0, r4, r0, lsl #8
  a0:	0b3a0e03 	bleq	e838b4 <_E_TEXT+0xe836bc>
  a4:	13490b3b 	movtne	r0, #39739	; 0x9b3b
  a8:	00000a02 	andeq	r0, r0, r2, lsl #20
  ac:	03003405 	movweq	r3, #1029	; 0x405
  b0:	3b0b3a08 	blcc	2ce8d8 <_E_TEXT+0x2ce6e0>
  b4:	0213490b 	andseq	r4, r3, #180224	; 0x2c000
  b8:	0600000a 	streq	r0, [r0], -sl
  bc:	0b0b0024 	bleq	2c0154 <_E_TEXT+0x2bff5c>
  c0:	0e030b3e 	vmoveq.16	d3[0], r0
  c4:	0f070000 	svceq	0x00070000
  c8:	490b0b00 	stmdbmi	fp, {r8, r9, fp}
  cc:	08000013 	stmdaeq	r0, {r0, r1, r4}
  d0:	0b0b0024 	bleq	2c0168 <_E_TEXT+0x2bff70>
  d4:	08030b3e 	stmdaeq	r3, {r1, r2, r3, r4, r5, r8, r9, fp}
  d8:	01090000 	mrseq	r0, (UNDEF: 9)
  dc:	01134901 	tsteq	r3, r1, lsl #18
  e0:	0a000013 	beq	134 <main+0x118>
  e4:	13490021 	movtne	r0, #36897	; 0x9021
  e8:	00000b2f 	andeq	r0, r0, pc, lsr #22
  ec:	0101150b 	tsteq	r1, fp, lsl #10
  f0:	0c000013 	stceq	0, cr0, [r0], {19}
  f4:	00000018 	andeq	r0, r0, r8, lsl r0
  f8:	0300340d 	movweq	r3, #1037	; 0x40d
  fc:	3b0b3a0e 	blcc	2ce93c <_E_TEXT+0x2ce744>
 100:	3f13490b 	svccc	0x0013490b
 104:	000a020c 	andeq	r0, sl, ip, lsl #4
 108:	00260e00 	eoreq	r0, r6, r0, lsl #28
 10c:	00001349 	andeq	r1, r0, r9, asr #6
 110:	0300340f 	movweq	r3, #1039	; 0x40f
 114:	3b0b3a0e 	blcc	2ce954 <_E_TEXT+0x2ce75c>
 118:	3f13490b 	svccc	0x0013490b
 11c:	000c3c0c 	andeq	r3, ip, ip, lsl #24
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000002 	andeq	r0, r0, r2
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000002 	andeq	r0, r0, r2
  10:	00000004 	andeq	r0, r0, r4
  14:	047d0002 	ldrbteq	r0, [sp], #-2
  18:	00000004 	andeq	r0, r0, r4
  1c:	0000011e 	andeq	r0, r0, lr, lsl r1
  20:	04770002 	ldrbteq	r0, [r7], #-2
	...
  30:	00000002 	andeq	r0, r0, r2
  34:	007d0002 	rsbseq	r0, sp, r2
  38:	00000002 	andeq	r0, r0, r2
  3c:	00000004 	andeq	r0, r0, r4
  40:	087d0002 	ldmdaeq	sp!, {r1}^
  44:	00000004 	andeq	r0, r0, r4
  48:	0000000a 	andeq	r0, r0, sl
  4c:	08770002 	ldmdaeq	r7!, {r1}^
	...
  58:	0000000c 	andeq	r0, r0, ip
  5c:	0000000e 	andeq	r0, r0, lr
  60:	007d0002 	rsbseq	r0, sp, r2
  64:	0000000e 	andeq	r0, r0, lr
  68:	00000010 	andeq	r0, r0, r0, lsl r0
  6c:	087d0002 	ldmdaeq	sp!, {r1}^
  70:	00000010 	andeq	r0, r0, r0, lsl r0
  74:	00000012 	andeq	r0, r0, r2, lsl r0
  78:	207d0002 	rsbscs	r0, sp, r2
  7c:	00000012 	andeq	r0, r0, r2, lsl r0
  80:	000000bc 	strheq	r0, [r0], -ip
  84:	20770002 	rsbscs	r0, r7, r2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
   c:	00000000 	andeq	r0, r0, r0
  10:	0000001c 	andeq	r0, r0, ip, lsl r0
  14:	0000011e 	andeq	r0, r0, lr, lsl r1
	...
  20:	0000001c 	andeq	r0, r0, ip, lsl r0
  24:	00ac0002 	adceq	r0, ip, r2
  28:	00040000 	andeq	r0, r4, r0
  2c:	00000000 	andeq	r0, r0, r0
  30:	0000013c 	andeq	r0, r0, ip, lsr r1
  34:	000000bc 	strheq	r0, [r0], -ip
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000005f 	andeq	r0, r0, pc, asr r0
   4:	001d0002 	andseq	r0, sp, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	6e69616d 	powvsez	f6, f1, #5.0
  20:	0000632e 	andeq	r6, r0, lr, lsr #6
  24:	00000000 	andeq	r0, r0, r0
  28:	001c0205 	andseq	r0, ip, r5, lsl #4
  2c:	0a030000 	beq	c0034 <_E_TEXT+0xbfe3c>
  30:	00782f01 	rsbseq	r2, r8, r1, lsl #30
  34:	06020402 	streq	r0, [r2], -r2, lsl #8
  38:	04020082 	streq	r0, [r2], #-130	; 0x82
  3c:	7606ba01 	strvc	fp, [r6], -r1, lsl #20
  40:	00bbbebb 	ldrhteq	fp, [fp], fp
  44:	06020402 	streq	r0, [r2], -r2, lsl #8
  48:	04020082 	streq	r0, [r2], #-130	; 0x82
  4c:	9106ba01 	tstls	r6, r1, lsl #20
  50:	040200bb 	streq	r0, [r2], #-187	; 0xbb
  54:	00820602 	addeq	r0, r2, r2, lsl #12
  58:	ba010402 	blt	41068 <_E_TEXT+0x40e70>
  5c:	01029106 	tsteq	r2, r6, lsl #2
  60:	63010100 	movwvs	r0, #4352	; 0x1100
  64:	02000000 	andeq	r0, r0, #0
  68:	00002000 	andeq	r2, r0, r0
  6c:	fb010200 	blx	40876 <_E_TEXT+0x4067e>
  70:	01000d0e 	tsteq	r0, lr, lsl #26
  74:	00010101 	andeq	r0, r1, r1, lsl #2
  78:	00010000 	andeq	r0, r1, r0
  7c:	73000100 	movwvc	r0, #256	; 0x100
  80:	74726174 	ldrbtvc	r6, [r2], #-372	; 0x174
  84:	632e7075 	teqvs	lr, #117	; 0x75
  88:	00000000 	andeq	r0, r0, r0
  8c:	02050000 	andeq	r0, r5, #0
  90:	0000013c 	andeq	r0, r0, ip, lsr r1
  94:	032f2f19 	teqeq	pc, #25, 30	; 0x64
  98:	9f3e2e1e 	svcls	0x003e2e1e
  9c:	02005a59 	andeq	r5, r0, #364544	; 0x59000
  a0:	004c0204 	subeq	r0, ip, r4, lsl #4
  a4:	b8020402 	stmdalt	r2, {r1, sl}
  a8:	01040200 	mrseq	r0, R12_usr
  ac:	50064a06 	andpl	r4, r6, r6, lsl #20
  b0:	02005a9f 	andeq	r5, r0, #651264	; 0x9f000
  b4:	004c0204 	subeq	r0, ip, r4, lsl #4
  b8:	80020402 	andhi	r0, r2, r2, lsl #8
  bc:	01040200 	mrseq	r0, R12_usr
  c0:	4f064a06 	svcmi	0x00064a06
  c4:	0004022f 	andeq	r0, r4, pc, lsr #4
  c8:	Address 0x000000c8 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
   4:	6e6f6c20 	cdpvs	12, 6, cr6, cr15, cr0, {1}
   8:	6e692067 	cdpvs	0, 6, cr2, cr9, cr7, {3}
   c:	616d0074 	smcvs	53252	; 0xd004
  10:	632e6e69 	teqvs	lr, #1680	; 0x690
  14:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
  18:	4e47006e 	cdpmi	0, 4, cr0, cr7, cr14, {3}
  1c:	20432055 	subcs	r2, r3, r5, asr r0
  20:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  24:	3a440032 	bcc	11000f4 <_E_TEXT+0x10ffefc>
  28:	20736b5c 	rsbscs	r6, r3, ip, asr fp
  2c:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xd65
  30:	64656464 	strbtvs	r6, [r5], #-1124	; 0x464
  34:	73797320 	cmnvc	r9, #32, 6	; 0x80000000
  38:	206d6574 	rsbcs	r6, sp, r4, ror r5
  3c:	5c737361 	ldclpl	3, cr7, [r3], #-388	; 0xfffffe7c
  40:	74696e75 	strbtvc	r6, [r9], #-3701	; 0xe75
  44:	6d655c33 	stclvs	12, cr5, [r5, #-204]!	; 0xffffff34
  48:	64646562 	strbtvs	r6, [r4], #-1378	; 0x562
  4c:	63206465 	teqvs	r0, #1694498816	; 0x65000000
  50:	6c003420 	cfstrsvs	mvf3, [r0], {32}
  54:	20676e6f 	rsbcs	r6, r7, pc, ror #28
  58:	676e6f6c 	strbvs	r6, [lr, -ip, ror #30]!
  5c:	736e7520 	cmnvc	lr, #32, 10	; 0x8000000
  60:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  64:	6e692064 	cdpvs	0, 6, cr2, cr9, cr4, {3}
  68:	6e750074 	mrcvs	0, 3, r0, cr5, cr4, {3}
  6c:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  70:	63206465 	teqvs	r0, #1694498816	; 0x65000000
  74:	00726168 	rsbseq	r6, r2, r8, ror #2
  78:	726f6873 	rsbvc	r6, pc, #7536640	; 0x730000
  7c:	6e752074 	mrcvs	0, 3, r2, cr5, cr4, {3}
  80:	6e676973 	mcrvs	9, 3, r6, cr7, cr3, {3}
  84:	69206465 	stmdbvs	r0!, {r0, r2, r5, r6, sl, sp, lr}
  88:	7300746e 	movwvc	r7, #1134	; 0x46e
  8c:	74726f68 	ldrbtvc	r6, [r2], #-3944	; 0xf68
  90:	746e6920 	strbtvc	r6, [lr], #-2336	; 0x920
  94:	7a697300 	bvc	1a5cc9c <_E_TEXT+0x1a5caa4>
  98:	70797465 	rsbsvc	r7, r9, r5, ror #8
  9c:	455f0065 	ldrbmi	r0, [pc, #-101]	; 3f <main+0x23>
  a0:	5845545f 	stmdapl	r5, {r0, r1, r2, r3, r4, r6, sl, ip, lr}^
  a4:	455f0054 	ldrbmi	r0, [pc, #-84]	; 58 <main+0x3c>
  a8:	5441445f 	strbpl	r4, [r1], #-1119	; 0x45f
  ac:	535f0041 	cmppl	pc, #65	; 0x41
  b0:	5441445f 	strbpl	r4, [r1], #-1119	; 0x45f
  b4:	5f500041 	svcpl	0x00500041
  b8:	00747364 	rsbseq	r7, r4, r4, ror #6
  bc:	61666544 	cmnvs	r6, r4, asr #10
  c0:	5f746c75 	svcpl	0x00746c75
  c4:	646e7548 	strbtvs	r7, [lr], #-1352	; 0x548
  c8:	0072656c 	rsbseq	r6, r2, ip, ror #10
  cc:	72617473 	rsbvc	r7, r1, #1929379840	; 0x73000000
  d0:	2e707574 	mrccs	5, 3, r7, cr0, cr4, {3}
  d4:	5f500063 	svcpl	0x00500063
  d8:	00637273 	rsbeq	r7, r3, r3, ror r2
  dc:	5f535342 	svcpl	0x00535342
  e0:	657a6953 	ldrbvs	r6, [sl, #-2387]!	; 0x953
  e4:	54414400 	strbpl	r4, [r1], #-1024	; 0x400
  e8:	69535f41 	ldmdbvs	r3, {r0, r6, r8, r9, sl, fp, ip, lr}^
  ec:	5300657a 	movwpl	r6, #1402	; 0x57a
  f0:	6b636174 	blvs	18d86c8 <_E_TEXT+0x18d84d0>
  f4:	706f545f 	rsbvc	r5, pc, pc, asr r4	; <UNPREDICTABLE>
  f8:	5f455f00 	svcpl	0x00455f00
  fc:	00535342 	subseq	r5, r3, r2, asr #6
 100:	5f705f67 	svcpl	0x00705f67
 104:	765f6e66 	ldrbvc	r6, [pc], -r6, ror #28
 108:	6f746365 	svcvs	0x00746365
 10c:	52007372 	andpl	r7, r0, #-939524095	; 0xc8000001
 110:	74657365 	strbtvc	r7, [r5], #-869	; 0x365
 114:	6e75485f 	mrcvs	8, 3, r4, cr5, cr15, {2}
 118:	72656c64 	rsbvc	r6, r5, #100, 24	; 0x6400
 11c:	5f535f00 	svcpl	0x00535f00
 120:	00535342 	subseq	r5, r3, r2, asr #6

Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <_E_TEXT+0x10d0b2c>
   4:	4e472820 	cdpmi	8, 4, cr2, cr7, cr0, {1}
   8:	34202955 	strtcc	r2, [r0], #-2389	; 0x955
   c:	322e372e 	eorcc	r3, lr, #12058624	; 0xb80000
	...

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003241 	andeq	r3, r0, r1, asr #4
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000028 	andeq	r0, r0, r8, lsr #32
  10:	726f4305 	rsbvc	r4, pc, #335544320	; 0x14000000
  14:	2d786574 	cfldr64cs	mvdx6, [r8, #-464]!	; 0xfffffe30
  18:	0600344d 	streq	r3, [r0], -sp, asr #8
  1c:	094d070d 	stmdbeq	sp, {r0, r2, r3, r8, r9, sl}^
  20:	14041202 	strne	r1, [r4], #-514	; 0x202
  24:	17011501 	strne	r1, [r1, -r1, lsl #10]
  28:	19011803 	stmdbne	r1, {r0, r1, fp, ip}
  2c:	1e011a01 	vmlane.f32	s2, s2, s2
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000014 	andeq	r0, r0, r4, lsl r0
  14:	00000000 	andeq	r0, r0, r0
  18:	0000001c 	andeq	r0, r0, ip, lsl r0
  1c:	0000011e 	andeq	r0, r0, lr, lsl r1
  20:	87040e41 	strhi	r0, [r4, -r1, asr #28]
  24:	070d4101 	streq	r4, [sp, -r1, lsl #2]
  28:	0000000c 	andeq	r0, r0, ip
  2c:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
  30:	7c020001 	stcvc	0, cr0, [r2], {1}
  34:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  38:	00000018 	andeq	r0, r0, r8, lsl r0
  3c:	00000028 	andeq	r0, r0, r8, lsr #32
  40:	0000013c 	andeq	r0, r0, ip, lsr r1
  44:	0000000a 	andeq	r0, r0, sl
  48:	87080e41 	strhi	r0, [r8, -r1, asr #28]
  4c:	41018e02 	tstmi	r1, r2, lsl #28
  50:	0000070d 	andeq	r0, r0, sp, lsl #14
  54:	0000001c 	andeq	r0, r0, ip, lsl r0
  58:	00000028 	andeq	r0, r0, r8, lsr #32
  5c:	00000148 	andeq	r0, r0, r8, asr #2
  60:	000000b0 	strheq	r0, [r0], -r0	; <UNPREDICTABLE>
  64:	87080e41 	strhi	r0, [r8, -r1, asr #28]
  68:	41018e02 	tstmi	r1, r2, lsl #28
  6c:	0d41200e 	stcleq	0, cr2, [r1, #-56]	; 0xffffffc8
  70:	00000007 	andeq	r0, r0, r7
