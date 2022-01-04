#pragma once

// Object Constructor List Example
// 
// compiler treats them as same when members are primitives
// but when member is class type, using constructor list is more efficient

class ObjectConstructorListExampleSource
{
    int sourceNum = 0;
};


class ObjectConstructorList_UsingList
{
public:
    ObjectConstructorList_UsingList() :mNum{ 0 }, mChar{ 0 }, mSource{ ObjectConstructorListExampleSource() }{}

private:
	int mNum;
	unsigned char mChar;
    ObjectConstructorListExampleSource mSource;

    // WITH CLASS MEMBER
    // x64 msvc v19
    /*
        this$ = 48
        ObjectConstructorList_UsingList::ObjectConstructorList_UsingList(void) PROC        ; ObjectConstructorList_UsingList::ObjectConstructorList_UsingList, COMDAT
        $LN3:
        mov     QWORD PTR [rsp+8], rcx
        push    rdi
        sub     rsp, 32                             ; 00000020H
        mov     rax, QWORD PTR this$[rsp]
        mov     DWORD PTR [rax], 0
        mov     rax, QWORD PTR this$[rsp]
        mov     BYTE PTR [rax+4], 0
        mov     rax, QWORD PTR this$[rsp]
        add     rax, 8
        mov     rdi, rax
        xor     eax, eax
        mov     ecx, 4
        rep stosb
        mov     rax, QWORD PTR this$[rsp]
        add     rax, 8
        mov     rcx, rax
        call    ObjectConstructorListExampleSource::ObjectConstructorListExampleSource(void)
        mov     rax, QWORD PTR this$[rsp]
        add     rsp, 32                             ; 00000020H
        pop     rdi
        ret     0
        ObjectConstructorList_UsingList::ObjectConstructorList_UsingList(void) ENDP        ; ObjectConstructorList_UsingList::ObjectConstructorList_UsingList
    */

    // ONLY PRIMITIVES
    // 
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
        mSource = ObjectConstructorListExampleSource();
	}

private:
	int mNum;
	unsigned char mChar;
    ObjectConstructorListExampleSource mSource;

    // WITH CLASS MEMBER
    // x64 msvc v19
    /*
        $T1 = 32
        this$ = 64
        ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope(void) PROC     ; ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope, COMDAT
        $LN3:
        mov     QWORD PTR [rsp+8], rcx
        push    rdi
        sub     rsp, 48                             ; 00000030H
        mov     rax, QWORD PTR this$[rsp]
        add     rax, 8
        mov     rcx, rax
        call    ObjectConstructorListExampleSource::ObjectConstructorListExampleSource(void)
        mov     rax, QWORD PTR this$[rsp]
        mov     DWORD PTR [rax], 0
        mov     rax, QWORD PTR this$[rsp]
        mov     BYTE PTR [rax+4], 0
        lea     rax, QWORD PTR $T1[rsp]
        mov     rdi, rax
        xor     eax, eax
        mov     ecx, 4
        rep stosb
        lea     rcx, QWORD PTR $T1[rsp]
        call    ObjectConstructorListExampleSource::ObjectConstructorListExampleSource(void)
        mov     eax, DWORD PTR [rax]
        mov     rcx, QWORD PTR this$[rsp]
        mov     DWORD PTR [rcx+8], eax
        mov     rax, QWORD PTR this$[rsp]
        add     rsp, 48                             ; 00000030H
        pop     rdi
        ret     0
        ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope(void) ENDP     ; ObjectConstructorList_UsingInScope::ObjectConstructorList_UsingInScope

    */

    // ONLY PRIMITIVES
    // 
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