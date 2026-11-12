include \masm32\include\masm32rt.inc

.data
    quo     dd 0
    frac    dd 0

.data?
    buf     db 32 dup(?)

.code
start:
    xor ebx, ebx
    mov esi, 5

input_loop:
    print "Enter a number: "
    invoke StdIn, addr buf, 31
    invoke atodw, addr buf
    add ebx, eax
    dec esi
    jnz input_loop

    mov eax, ebx
    xor edx, edx
    mov ecx, 5
    div ecx

    mov quo, eax
    shl edx, 1
    mov frac, edx

    print "Average: "
    print str$(quo)
    print "."
    print str$(frac)
    print chr$(13, 10)

    exit
end start