#pragma once

// Object Constructor List Example
// 
// compiler treats them as same
class ObjectConstructorList_UsingList
{
public:
	ObjectConstructorList_UsingList() :mNum{ 0 }, mChar{ 0 }{}

private:
	int mNum;
	unsigned char mChar;

    // x64 msvc v19
    /*
        this$ = 8
        ObjectConstructorList_UsingList::ObjectConstructorList_UsingList(void) PROC        ; ObjectConstructorList_UsingList::ObjectConstructorList_UsingList, COMDAT
        mov     QWORD PTR [rsp+8], rcx
        mov     rax, QWORD PTR this$[rsp]
        mov     DWORD PTR [rax], 0
        mov     rax, QWORD PTR this$[rsp]
        mov     BYTE PTR [rax+4], 0
        mov     rax, QWORD PTR this$[rsp]
        ret     0
        ObjectConstructorList_UsingList::ObjectConstructorList_UsingList(void) ENDP        ; ObjectConstructorList_UsingList::ObjectConstructorList_UsingList
    */

	// gcc 11.2
	/*
	    push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 0
        mov     rax, QWORD PTR [rbp-8]
        mov     BYTE PTR [rax+4], 0
        nop
        pop     rbp
        ret
	*/

    // clang 13.0.0
    /*
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rdi, [rbp - 8]
        call    ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope() [base object constructor]
        xor     eax, eax
        add     rsp, 16
        pop     rbp
        ret
    */
};

class ObjectConstructorList_UsingInScope
{
public:
	ObjectConstructorList_UsingInScope()
	{
		mNum = 0;
		mChar = 0;
	}

private:
	int mNum;
	unsigned char mChar;

    // x64 msvc v19
    /*  
        this$ = 8
        ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope(void) PROC     ; ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope, COMDAT
        mov     QWORD PTR [rsp+8], rcx
        mov     rax, QWORD PTR this$[rsp]
        mov     DWORD PTR [rax], 0
        mov     rax, QWORD PTR this$[rsp]
        mov     BYTE PTR [rax+4], 0
        mov     rax, QWORD PTR this$[rsp]
        ret     0
        ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope(void) ENDP     ; ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope
    */

	// gcc 11.2
	/*
		push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 0
        mov     rax, QWORD PTR [rbp-8]
        mov     BYTE PTR [rax+4], 0
        nop
        pop     rbp
        ret
	*/

    // clang 13.0.0
    /*
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rdi, [rbp - 8]
        call    ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope() [base object constructor]
        xor     eax, eax
        add     rsp, 16
        pop     rbp
        ret
    */
};