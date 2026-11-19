INCLUDE Irvine32.inc

.data
p1 BYTE "Enter first number : ",0
p2 BYTE "Enter second number: ",0

.code
main PROC
    mov  edx, OFFSET p1
    call WriteString
    call ReadInt
    mov  si, ax            ; si = A

    mov  edx, OFFSET p2
    call WriteString
    call ReadInt
    mov  di, ax            ; di = B

    xor  eax, eax          ; 상위 비트 정리 (DumpRegs 출력용)
    xor  ebx, ebx
    xor  ecx, ecx
    xor  edx, edx

    mov  ax, si
    cwd                    ; DX:AX = A
    idiv di                ; AX = 몫, DX = 나머지
    mov  dx, ax            ; DX = A / B

    mov  cx, si
    imul cx, di            ; CX = A * B

    mov  bx, si
    sub  bx, di            ; BX = A - B

    mov  ax, si
    add  ax, di            ; AX = A + B

    call DumpRegs          ; AX, BX, CX, DX 확인
    exit
main ENDP
END main