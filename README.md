# A Zephyr Application Template

An out-of-tree [Zephyr](https://www.zephyrproject.org/) application template.

## Getting started

The following prerequisites are required for building and flashing onto a
board target.

### Prerequisites

Ensure the following dependencies are installed on the host system:
- [asdf](https://asdf-vm.com/guide/getting-started.html)
- [cmake](https://cmake.org/)
- [direnv](https://direnv.net/)
- [ninja-build](https://ninja-build.org/)
- [python3-venv](https://docs.python.org/3/library/venv.html)

Install Zephyr dependencies using `asdf`.

```shell
asdf plugin add zephyr https://github.com/redwirelabs/asdf-zephyr.git
asdf plugin add zephyr-sdk https://github.com/redwirelabs/asdf-zephyr-sdk.git
asdf install
```

Create the project's `.envrc`. See `.envrc.example` for more details.

```shell
cp .envrc.example .envrc
```

### Building

```shell
west build
```

### Flashing

```shell
west flash
```

### Emulating (QEMU)

```shell
$ west build -t run

[0/1] To exit from QEMU enter: 'CTRL+a, x'[QEMU] CPU: qemu32,+nx,+pae
SeaBIOS (version zephyr-v1.0.0-0-g31d4e0e-dirty-20200714_234759-fv-az50-zephyr)
Booting from ROM..
*** Booting Zephyr OS build v3.7.0 ***
[00:00:00.010,000] <inf> main: Hello world from qemu_x86/atom
```
