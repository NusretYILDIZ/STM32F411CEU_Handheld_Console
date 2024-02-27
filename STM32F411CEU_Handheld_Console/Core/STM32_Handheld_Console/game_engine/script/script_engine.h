#ifndef __script_engine_h
#define __script_engine_h

#include <stdint.h>

#define RAM_SIZE    (1024 * 80) // 85 KB (Max possible size is 88 KB but expect it to be lesser than that.)
#define STACK_SIZE  (256)

#if (RAM_SIZE > 65536)
	typedef uint32_t ram_t;
#else
	typedef uint16_t ram_t;
#endif

#if (STACK_SIZE > 256)
	typedef uint16_t stack_t;
#else
	typedef uint8_t stack_t;
#endif

extern uint8_t ram[RAM_SIZE];
extern uint32_t stack[STACK_SIZE];

extern ram_t prg_counter;
extern stack_t stack_ptr;

//extern uint32_t a_int;
//extern float a_flt;
extern uint8_t logical_flag;
//extern ram_t abs_addr;
//extern ram_t ptr_addr;

void vm_execute(void);
void vm_push(uint32_t data);
uint32_t vm_pop(void);

#endif //__script_engine_h