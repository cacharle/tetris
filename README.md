# Tetris

Some (shitty?) [Tetris](https://en.wikipedia.org/wiki/Tetris) Game implementation.

## Dependencies

[SDL](https://www.libsdl.org/) used for the graphics.
Install with aptitude: `> sudo apt install libsdl2-dev`.

## Usage

- Compile: `> make all`
- Run: `> ./tetris`

## TODO

- [ ] Score counter
- [ ] Display score counter
- [ ] Different color tetriminoes
- [ ] Hard drop
- [ ] Soft drop
- [ ] Display next tetrimino spawn
- [ ] Display a hard drop preview
- [ ] Display well borders
- [ ] Prettier and resizable graphic interface
- [ ] Tetriminoes generation from config file (ex: ./standard.tetriminoes)
- [ ] Generate all rotations from one
- [ ] (MacOS/Windows) support
- [ ] Command line options (well dimensions, tetriminoes colors, ...)
- [ ] Default options config files
      (in minimalistic [TOML](https://github.com/toml-lang/toml) format)

## FIXME

- [ ] Tetrimino rotation
- [ ] Full lines clear
