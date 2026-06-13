# MegatronixOS

![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux-green)
![Build](https://img.shields.io/badge/build-GCC-orange)
![Status](https://img.shields.io/badge/status-Active-success)

MegatronixOS is an educational operating systems project developed in C that simulates the behavior of a direct-mapped CPU cache memory system. The simulator processes memory access requests, detects cache hits and misses, loads memory blocks from RAM when required, and generates detailed execution statistics such as cache faults, average access time and reconstructed output data.

The project was designed to explore low-level systems programming concepts, including memory hierarchy management, cache organization, address decoding and binary file manipulation. By emulating the interaction between the CPU, cache and RAM, it provides a practical understanding of how modern computer architectures optimize memory access performance.

## Project Structure

```text
## Project Structure

```text
MegatronixOS/
├── MEMsym.c
├── CONTENTS_RAM.bin
├── accesos_memoria.txt
└── CONTENTS_CACHE.bin
```

- `MEMsym.c`: main source code of the cache memory simulator.
- `CONTENTS_RAM.bin`: binary file representing the simulated RAM.
- `accesos_memoria.txt`: input file containing memory addresses requested by the CPU.
- `CONTENTS_CACHE.bin`: output file generated with the final cache contents.

## Workflow
1. The simulator loads the RAM contents from CONTENTS_RAM.bin.
2. Memory addresses are read sequentially from accesos_memoria.txt.
3. Each address is decoded into tag, line, word and block fields.
4. The cache determines whether the access is a HIT or a MISS.
5. On a MISS, the corresponding block is loaded from RAM into the cache.
6. Cache statistics are updated throughout execution.
7. The final cache state is exported to CONTENTS_CACHE.bin.
8. A summary report containing total accesses, cache misses, average access time and reconstructed text is displayed.

## Technologies

- C
- GNU GCC
- Linux
- POSIX APIs

## Installation

Clone the repository:

```bash
git clone https://github.com/chiissuu/MegatronixOS.git
cd MegatronixOS
```

Compile the project:

```bash
gcc MEMsym.c -o megatronixos
```

Run the executable:

```bash
./megatronixos
```


## Contributing

Contributions, bug reports and feature suggestions are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a Pull Request

## Contributors

- Jesús León Romero Atienza (Username de GITHUB: chiissuu)

- Mario Viso Quito (Username de GITHUB: Marioo239)



## License

This project is distributed for educational purposes.
