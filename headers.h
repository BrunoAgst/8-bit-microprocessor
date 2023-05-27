// NOTE: instructions
#define LDI 0x04
#define ADD 0x05
#define SUB 0x06
#define NULL 0x00

// NOTE: functions
void fetch_cycle();
void get_instruction();
void search_instruction();
int select_instruction(char opcode);
void search_operation(char instruct);
void ldi_exec();
void add_exec(); // TODO: Implement the sub statement
void sub_exec(); // TODO: Implement the sub statement
void print_output();