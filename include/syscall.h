#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <sys/defs.h>
#include <sys/syscall.h>
#include<stdio.h>

static __inline uint64_t syscall_0(uint64_t n) {

	 uint64_t ret;

	__asm__ volatile("int $0x80;"

			:"=a"(ret)

			 :"a"(n)

			 : "cc", "rcx", "r11", "memory"
		
			);

	return ret;
}

static __inline uint64_t syscall_1(uint64_t n, uint64_t a1) {
		 uint64_t ret;
		
          
	__asm__ volatile("int $0x80;"
			
			 :"=a"(ret)

			 :"a"(n),"D"(a1)

			 : "cc", "rcx", "r11", "memory"
	

			 );
	return ret;
}

static __inline uint64_t syscall_2(uint64_t n, uint64_t a1, uint64_t a2) {
	uint64_t ret;

	__asm__ volatile(

		"int $0x80;"

		:"=a"(ret) 

		: "a"(n), "D"(a1), "S"(a2)

		: "cc", "rcx", "r11", "memory"

		);		 

	return ret;
	
}

static __inline uint64_t syscall_3(uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3) {
	
		uint64_t ret;
		 //printf("%x\n",a2);

	__asm__ volatile(


		"int $0x80;"

		:"=a"(ret) 

		: "a"(n), "D"(a1), "S"(a2), "d"(a3)

		: "cc", "rcx", "r11", "memory"

		);		 

	return ret;
	
}



#endif
