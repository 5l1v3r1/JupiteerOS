[![GitHub license](https://img.shields.io/github/license/jupiteer/JupiteerOS)](https://github.com/jupiteer/JupiteerOS/blob/master/LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/jupiteer/JupiteerOS)](https://github.com/jupiteer/JupiteerOS/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/jupiteer/JupiteerOS)](https://github.com/jupiteer/JupiteerOS/network)
# JupiteerOS
Experimental Operating System

## Build requirements
In order to build JupiteerOS, make sure to have the following installed:
- git
- bash
- make
- GCC 
- nasm
- QEMU (to test it)

### Build
```
./build.sh
```
### Compile to ISO
```
make iso
```
### Run in QEMU:
```
make run
```
### Run in Bochs
```
make bochs
```
After running bochs, type "c" to start it.

### V0.1
* GRUB bootloader
* Global and Interrupt Descriptor Table
* ISR handler

### References
* https://wiki.osdev.org/
