# Tetris

Some (shitty?) [Tetris](https://en.wikipedia.org/wiki/Tetris) Game implementation.

## Dependencies

[SDL](https://www.libsdl.org/) used for the graphics.
Install with aptitude: `> sudo apt install libsdl2-dev`.

## Usage

- Compile: `> make all`
- Run: `> ./tetris`

## TODO

- [x] Score counter
- [ ] Display score counter  @HappyTramp
- [ ] Different color tetriminoes
- [x] Hard drop
- [x] Soft drop
- [ ] Display next tetrimino spawn  @HappyTramp
- [ ] Display a hard drop preview  @HappyTramp
- [ ] Display well borders  @HappyTramp
- [ ] Prettier and resizable graphic interface  @HappyTramp
- [ ] Tetriminoes generation from config file (ex: ./standard.tetriminoes)
- [ ] Generate all rotations from one
- [ ] (MacOS/Windows) support
- [ ] Command line options (well dimensions, tetriminoes colors, ...)
- [ ] Default options config files
      (in minimalistic [TOML](https://github.com/toml-lang/toml) format)

## FIXME

- [x] Tetrimino rotation
- [x] Full lines clear
