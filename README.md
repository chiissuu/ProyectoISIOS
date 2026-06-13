# MegatronixOS

![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux-green)
![Build](https://img.shields.io/badge/build-GCC-orange)
![Status](https://img.shields.io/badge/status-Active-success)

MegatronixOS is an educational operating systems project developed in C that simulates the behavior of a direct-mapped CPU cache memory system. The simulator processes memory access requests, detects cache hits and misses, loads memory blocks from RAM when required, and generates detailed execution statistics such as cache faults, average access time and reconstructed output data.

The project was designed to explore low-level systems programming concepts, including memory hierarchy management, cache organization, address decoding and binary file manipulation. By emulating the interaction between the CPU, cache and RAM, it provides a practical understanding of how modern computer architectures optimize memory access performance.

## Project Structure

```text
MegatronixOS/
├── MEMsym.c
├── CONTENTS_RAM.bin
├── accesos_memoria.txt
├── CONTENTS_CACHE.bin
└── logcache.txt
```

- `MEMsym.c`: main source code of the cache memory simulator.
- `CONTENTS_RAM.bin`: binary file representing the simulated RAM.
- `accesos_memoria.txt`: input file containing memory addresses requested by the CPU.
- `CONTENTS_CACHE.bin`: output file generated with the final cache contents.
- `logcache.txt`: execution log containing cache hits, misses, cache state dumps and performance statistics.

## Workflow

1. The simulator loads the RAM contents from `CONTENTS_RAM.bin`.
2. Memory addresses are read sequentially from `accesos_memoria.txt`.
3. Each address is decoded into tag, line, word and block fields.
4. The cache determines whether the access is a **HIT** or a **MISS**.
5. On a **MISS**, the corresponding memory block is loaded from RAM into the cache.
6. The simulator continuously updates cache statistics and execution time.
7. Detailed execution information is recorded in `logcache.txt`, including cache hits, cache misses, memory block loads and cache state snapshots.
8. The final cache state is exported to `CONTENTS_CACHE.bin`.
9. A summary report containing total accesses, cache misses, average access time and reconstructed output text is displayed at the end of execution.

## Output Files

After execution, the simulator generates the following outputs:

- `CONTENTS_CACHE.bin`: binary dump containing the final state of the cache memory.
- `logcache.txt`: detailed execution report showing cache activity throughout the simulation.

The terminal output also displays:

- Total memory accesses
- Cache misses
- Average access time
- Reconstructed text obtained from memory accesses

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
