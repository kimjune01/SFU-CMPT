# > as -g converterAssembly.s -o converterAssembly.o
# > gcc -o converterAssembly converterAssembly.o
# > gdb converterAssembly



        .data
Z:      .quad 1,2,3
ans:    .quad

        .text
        .global main
main:
        mov $Z, %rbx
        mov 0(%rbx), %rax
        add 8(%rbx), %rax
        add 16(%rbx), %rax
        mov %rax,24(%rbx)
        ret

#------------------------------------------------------------------------------


#------------------------------------------------------------------------------


#------------------------------------------------------------------------------

