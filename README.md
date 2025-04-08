# STM32-VSCode-Hello
This is a template project that demonstrates how to use VSCode/STM32CubeMX/OpenOCD/CMSIS_DAP
to develop and debug on the STM32 MCU.
# Components
## STM32CubeMX
STM32CubeMX is used to generate the project startup code and config MCU, such as GPIO/Clock..  
STM32CubeMX support CMake build system.
## SWD
**SWD** stands for **Serial Wire Debug** — it's a **two-wire** debug protocol developed by ARM for their Cortex-M microcontrollers. It's an alternative to **JTAG**, which typically uses more pins (at least 4–5).

SWD is a **lightweight, 2-pin interface** (plus ground) used for:
- **Flashing firmware**
- **Debugging code**
- **Reading/writing memory**

### How it works:
It uses two main lines:
- **SWDIO** – Serial Wire Data Input/Output (bidirectional)
- **SWCLK** – Serial Wire Clock

Sometimes there’s also:
- **RESET** – optional, for resetting the target MCU
- **GND** – always needed

## CMSIS_DAP
**CMSIS-DAP** stands for **Cortex Microcontroller Software Interface Standard - Debug Access Port**. It's a standardized interface defined by ARM for debugging and programming ARM Cortex-M microcontrollers.

CMSIS-DAP is a **firmware interface** that implements the **CMSIS Debug Access Port protocol** over USB. It allows your computer to communicate with a microcontroller for:

- Flash programming
- Debugging (e.g., breakpoints, stepping through code)
- Accessing memory registers

It typically runs on a debug probe (hardware device) that connects your PC to the target microcontroller via **SWD** (Serial Wire Debug) or **JTAG**.

## OpenOCD
OpenOCD stands for **Open On-Chip Debugger**. It's an open-source tool that provides debugging, in-system programming, and boundary-scan testing for embedded devices.  
You can imagine that OpenOCD is somewhat like GDBServer, OpenOCD connects to STM32 device by CMSIS_DAP debugger and communicate with GDB by network.

### In simpler terms:
OpenOCD helps you **talk to a microcontroller or processor** over a debug interface like **JTAG** or **SWD**. It's especially useful when you're working with **ARM Cortex-M** chips, but it supports a wide range of targets.

### What it's used for:
- **Flashing firmware** onto microcontrollers
- **Debugging code** running on embedded systems
- **Reading/writing memory** on a chip
- **Setting breakpoints and stepping through code**
- Used alongside tools like **GDB**, **Eclipse**, or **Visual Studio Code**

### Example command:
```bash
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg
```

That would start OpenOCD for an STM32F1 target using an ST-Link debugger.

Let me know if you're trying to set it up or troubleshoot something — happy to help!

# how to use
The overall workflow  
GDB <----TCP/IP----> OpenOCD <----- USB -----> CMSIS_DAP Debugger <------ SWD ------> STM32 Chip
## Program
Run OpenOCD command to download program to Chip ROM, [Here](https://github.com/flj512/STM32-VSCode-Hello/blob/3beb2af712062a41f3ef0ae8f0696db22f6a2be2/.vscode/tasks.json#L9) is an example configuration.  

## Debug
### Start OpenOCD manually
Start OpenOCD server manually and waiting for GDB connect to it.  
see [OpenOCD Config](https://github.com/flj512/STM32-VSCode-Hello/blob/3beb2af712062a41f3ef0ae8f0696db22f6a2be2/.vscode/tasks.json#L51) and [GDB config](https://github.com/flj512/STM32-VSCode-Hello/blob/3beb2af712062a41f3ef0ae8f0696db22f6a2be2/.vscode/launch.json#L27).  
You can use telnet to connect to OpenOCD to do program or other commands.  
### Debug with Cortex-Debug
Cortex-Debug is a VSCode extension to help debug, Example [Config](https://github.com/flj512/STM32-VSCode-Hello/blob/3beb2af712062a41f3ef0ae8f0696db22f6a2be2/.vscode/launch.json#L12).
