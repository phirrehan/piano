# Piano(SFML)

This is a simple Piano made using C++ with SFML library. It is cross-platform and will work on Linux, MacOS, and Windows. Here is a sample video of the piano on linux:

https://github.com/user-attachments/assets/950df874-6d36-45cd-83e9-264680c8ce4a

# Dependencies

- C++ Compiler
- CMake

## SFML Dependencies

These dependencies are only for Linux users.

- freetype
- x11
- xrandr
- xcursor
- xi
- udev
- opengl
- flac
- ogg
- vorbis
- vorbisenc
- vorbisfile
- pthread

> Note: The exact name of packages will vary from distribution to distribution.

For Ubuntu or Debian based OSes, the dependencies can be installed with the following command:

```
sudo apt update
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libfreetype-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libfreetype-dev
```

# Usage Guide

## Download Source Code

Download the source code from the github repository or using git:

```
git clone https://github.com/phirrehan/Piano.git
cd Piano
```

## Compile

Open terminal/powershell and run the following command in root of project:

> Note: Ensure you have the C++ compiler and cmake in PATH environment variable.

```
cmake -B build
cmake --build build
```

## Run Binary

After successful compilation, execute the `main` binary in `build/bin/main`. This can be done with `./build/bin/main` on terminal and `.\build\bin\main` on powershell.

Ensure that current working directory is root of project. Otherwise, the binary cannot find `assets` and gives error.

# Sound

The piano uses a singular sound (placed in `assets/Sounds`) for producing the sound of different notes. By default, this sound is set to `Acoustic.mp3`. It can be easily changed by editing `buffer`, a global variable in `src/main.cpp`.

## Brief Music Theory

This piano uses Equal Temperament as its tuning system. The pitch of adjacent notes have common ratio of $\sqrt[12]{2}$. The C2 Note of this piano is the original sound. All the other sounds have been derived from that sound by multiplying/dividing the pitch by $\sqrt[12]{2}$.

# Controls

The sharp notes (with # in front of them) are the black keys, while the rest are the white keys.

| Note | Control  |
| ---- | -------- |
| C1   | CapsLock |
| C1#  | Tab      |
| D1   | A        |
| D1#  | Q        |
| E1   | S        |
| F1   | D        |
| F1#  | E        |
| G1   | F        |
| G1#  | R        |
| A1   | G        |
| A1#  | T        |
| B1   | H        |
| C2   | J        |
| C2#  | U        |
| D2   | K        |
| D2#  | I        |
| E2   | L        |
| F2   | ;        |
| F2#  | P        |
| G2   | '        |
| G2#  | [        |
| A2   | \        |
| A2#  | ]        |
| B2   | M        |
