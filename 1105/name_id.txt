.386
.model flat, stdcall
option casemap :none

include \masm32\include\windows.inc
include \masm32\include\masm32rt.inc

.data
    myId    db "2024964049", 13, 10, 0
    myName  db "황주은", 13, 10, 0

.code
start:

    print offset myId
    
    print offset myName

    exit

end start