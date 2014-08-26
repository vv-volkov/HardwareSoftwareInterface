
myprog.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <bang>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	bf 00 00 00 00       	mov    $0x0,%edi
   9:	e8 00 00 00 00       	callq  e <bang+0xe>
   e:	5d                   	pop    %rbp
   f:	c3                   	retq   

0000000000000010 <setGlobVar>:
  10:	55                   	push   %rbp
  11:	48 89 e5             	mov    %rsp,%rbp
  14:	48 c7 05 00 00 00 00 	movq   $0x64,0x0(%rip)        # 1f <setGlobVar+0xf>
  1b:	64 00 00 00 
  1f:	b8 00 00 00 00       	mov    $0x0,%eax
  24:	e8 00 00 00 00       	callq  29 <setGlobVar+0x19>
  29:	5d                   	pop    %rbp
  2a:	c3                   	retq   

000000000000002b <main>:
  2b:	55                   	push   %rbp
  2c:	48 89 e5             	mov    %rsp,%rbp
  2f:	e8 00 00 00 00       	callq  34 <main+0x9>
  34:	b8 00 00 00 00       	mov    $0x0,%eax
  39:	5d                   	pop    %rbp
  3a:	c3                   	retq   
