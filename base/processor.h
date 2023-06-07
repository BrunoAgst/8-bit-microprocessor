// NOTE: instructions
#define HLT 0x00
#define NOP 0x01
#define OTI 0x02
#define LDA 0x03
#define LDI 0x04
#define ADD 0x05
#define SUB 0x06
#define STA 0x07
#define AND 0x08
#define ORL 0x09
#define XOR 0x0A
#define NOT 0x0B
#define GTA 0x0C
#define IFC 0x0D
#define IFZ 0x0E
#define ITI 0x0F
#define SHR 0x1F
#define SHL 0x2F

// NOTE: functions
void print_init();
void fetch_cycle();
void get_instruction();
void search_instruction();
int select_instruction(char opcode);
void search_operation(char instruction);
void lda_exec();
void sta_exec();
void and_exec();
void orl_exec();
void xor_exec();
void not_exec();
void ldi_exec();
void add_exec();
void sub_exec();
void oti_exec();
void gta_exec();
void ifc_exec();
void ifz_exec();
void nop_exec();
void iti_exec();
void shl_exec();
void shr_exec();
void print_output();