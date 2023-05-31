# 8-Bit microprocessor

This project is the construction of an 8-bit microprocessor. <br>
Currently has one instruction implemented and two pending. New instructions will be added in the future.<br>
<br>

## Instructions

| Item    | Description                             |
| :------ | :-------------------------------------- |
| **LDI** | Add argument to accumulator             |
| **ADD** | Add an argument to the accumulator      |
| **SUB** | Subtracts argument from the accumulator |
| **STA** | Add accumulator to UR                   |
| **XOR** | Pending...                              |
| **OR**  | Pending...                              |
| **AND** | Pending...                              |
| **LDA** | Pending...                              |

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

<br>

## Flags

Currently has two flags:<br>

| Item      | Description                                                                   |
| :-------- | :---------------------------------------------------------------------------- |
| **CFLAG** | Enabled if the result of some arithmetic operation is more than 8 bits or 255 |
| **ZFLAG** | Enabled if accumulator is zero                                                |

## To-do List:

- [x] LDI
- [x] ADD
- [x] SUB
- [x] STA
- [ ] LDA
- [ ] AND
- [ ] OR
- [ ] XOR
