# CACTI-4.1

CACTI-4.1 uses requires the following inputs:

```
Cmd-line parameters: C B A TECH NSubbanks
                 OR: C B A TECH RWP ERP EWP NSubbanks
```

- `C`: the cache size
- `B`: size of cache line in bytes (64)
- `A`: associativity of the cache (DM, 2, 4, or FA)
- `TECH`: feature size in microns (0.8, 0.18)
- `NSubbanks`: number of banks
- `RWP`: number of read/write ports (default 1)
- `ERP`: number of exclusive read ports (default 0)
- `EWP`: number of exclusive write ports (default 0)

For example, we can have for a 2-way 32KiB cache:

```
./cacti 32768 64 2 0.8 1
```