# 8-Bit microprocessor

This project is the construction of an 8-bit microprocessor. <br>
Currently has one instruction implemented and two pending. New instructions will be added in the future.<br>
<br>

## Instructions

| Item    | Description                                         |
| :------ | :-------------------------------------------------- |
| **LDI** | Add argument to accumulator                         |
| **ADD** | Add an argument to the accumulator                  |
| **SUB** | Subtracts argument from the accumulator             |
| **STA** | Add accumulator value to UR                         |
| **XOR** | Does the logic xor in the accumulator               |
| **ORL** | Does the logic or in the accumulator                |
| **AND** | Does the logic and in the accumulator               |
| **NOT** | Invert the accumulator bits                         |
| **LDA** | Add UR value to accumulator                         |
| **OTI** | Add accumulator value to OTR                        |
| **ITI** | Add ITR value to accumulator                        |
| **GTA** | Conditional branch instruction                      |
| **IFC** | Conditional branch instruction if flag c is enabled |
| **IFZ** | Conditional branch instruction if flag z is enabled |
| **NOP** | This instruction is used to waste time              |
| **HLT** | Stop processing                                     |

<br>

## Registrars

Currently has five registrars:<br>

| Item                | Description                                  |
| :------------------ | :------------------------------------------- |
| **INSTRUCTION**     | Instruction                                  |
| **ADD_INSTRUCTION** | Instruction address                          |
| **ARGUMENT**        | Argument                                     |
| **ACC**             | Accumulator                                  |
| **ADD_ROM**         | Current address of rom memory                |
| **BR**              | 8-bit registers to aid in logical operations |
| **UR**              | Ten registers for the user to use            |
| **OTR**             | Output register                              |
| **ITR**             | Input register                               |

<br>

## Flags

Currently has two flags: <br>

| Item      | Description                                                                   |
| :-------- | :---------------------------------------------------------------------------- |
| **CFLAG** | Enabled if the result of some arithmetic operation is more than 8 bits or 255 |
| **ZFLAG** | Enabled if accumulator is zero                                                |

## To-do List:

- [x] LDI
- [x] ADD
- [x] SUB
- [x] STA
- [x] LDA
- [x] AND
- [x] ORL
- [x] XOR
- [x] NOT
- [x] OTI
- [x] GTA
- [x] IFZ
- [x] IFC
- [x] NOP
- [x] HLT
- [x] ITI
- [ ] Adapt 8bit processor for raspberry pi pico
