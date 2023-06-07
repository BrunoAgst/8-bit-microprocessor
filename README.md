# 8-Bit microprocessor

This project is the construction of an 8-bit microprocessor. <br>
The processor can run on computer or raspberry pico.<br>
<br>

## Instructions

| Item    | Description                                         | code |
| :------ | :-------------------------------------------------- | :--- |
| **HLT** | Stop processing                                     | 0x00 |
| **NOP** | This instruction is used to waste time              | 0x01 |
| **OTI** | Add accumulator value to OTR                        | 0x02 |
| **LDA** | Add UR value to accumulator                         | 0x03 |
| **LDI** | Add argument to accumulator                         | 0x04 |
| **ADD** | Add an argument to the accumulator                  | 0x05 |
| **SUB** | Subtracts argument from the accumulator             | 0x06 |
| **STA** | Add accumulator value to UR                         | 0x07 |
| **AND** | Does the logic and in the accumulator               | 0x08 |
| **ORL** | Does the logic or in the accumulator                | 0x09 |
| **XOR** | Does the logic xor in the accumulator               | 0x0A |
| **NOT** | Invert the accumulator bits                         | 0x0B |
| **GTA** | Conditional branch instruction                      | 0x0C |
| **IFC** | Conditional branch instruction if flag c is enabled | 0x0D |
| **IFZ** | Conditional branch instruction if flag z is enabled | 0x0E |
| **ITI** | Add ITR value to accumulator                        | 0x0F |
| **SHR** | Shift right accumulator                             | 0x1F |
| **SHL** | Shift left accumulator                              | 0x2F |
| **CPA** | Compares the accumulator with the argument          | 0x3F |

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

| Item      | Description                                                         |
| :-------- | :------------------------------------------------------------------ |
| **CFLAG** | Enabled if the result of some arithmetic operation is more than 255 |
| **ZFLAG** | Enabled if accumulator is zero                                      |
| **EFLAG** | Enabled if an accumulator is equal to the argument                  |

# Raspberry Pico

## Configuration

Create the **build** folder and inside the folder run the command:

```
cmake ..
```

## Build

```
make -j4
```

# Images

<img src="https://i.ibb.co/p4ZFmNb/Captura-de-Tela-2023-06-04-a-s-17-51-23.png" alt="schematic pico" border="0"><br>

<img src="https://i.ibb.co/hWwSsb1/IMG-4650.jpg" alt="image" border="0">
