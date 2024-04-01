section .text
  [bits 32]
  [extern NxKernel]
  call NxKernel
  jmp $
