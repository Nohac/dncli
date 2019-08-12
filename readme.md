# dncli
`dncli` is a small command line utility that takes a list of files and
initiates a `drag and drop` action. This utility is useful when you want to
just drop some files from your terminal to a website or a file manager etc.

## Usage example
```bash
dncli files.txt to.md drag.gif
```
> Move cursor to desired drop zone and left click

## Build instructions
> Note: Qt5 or above is required to build

```bash
qmake
make -j4
```
> Copy `dncli` to desired location, preferably a location in your `PATH`
