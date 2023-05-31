# 8 Bit microprocessor

This project is the construction of an 8-bit microprocessor. <br>
Currently has one instruction implemented and two pending. New instructions will be added in the future.<br>
<br>

## Instructions

**LDA** -> pending...<br>
**LDI** -> Add argument to accumulator. <br>
**ADD** -> Add an argument to the accumulator. <br>
**SUB** -> Subtracts argument from the accumulator.<br>
<br>

## Registrars

Currently has five registrars:<br>

**INSTRUCTION** -> Instruction. <br>
**ADD_INSTRUCTION** -> Instruction address <br>
**ARGUMENT** -> Argument. <br>
**ACC** -> Accumulator. <br>
**ADD_ROM** -> Current address of rom memory. <br>
<br>

## Flags

Currently has two flags:<br>

**CFLAG** -> enabled if the result of some arithmetic operation is more than 8 bits or 255.<br>
**ZFLAG** -> enabled if accumulator is zero .<br>

## To-do List

- [x] LDI
- [x] ADD
- [x] SUB
- [ ] LDA
