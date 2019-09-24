# Tetris

Some (shitty?) [Tetris](https://en.wikipedia.org/wiki/Tetris) Game implementation.

## Dependencies

- [SDL2](https://www.libsdl.org/) for the graphics.
  Install with aptitude: `> sudo apt install libsdl2-dev`.
- [SDL2_tff]() to display text.
  Install with aptitude: `> sudo apt install libsdl2-ttf-dev`.

## Usage

- Compile: `> make all`
- Run: `> ./tetris`

## TODO

- [x] Score counter
- [x] Display score counter  @HappyTramp
- [ ] Different color tetriminoes
- [x] Hard drop
- [x] Soft drop
- [ ] Display a hard drop preview  @HappyTramp
- [x] Display well borders  @HappyTramp
- [ ] Prettier and resizable graphic interface  @HappyTramp
- [ ] Tetriminoes generation from config file (ex: ./standard.tetriminoes)
- [ ] Generate all rotations from one
- [ ] (MacOS/Windows) support
- [ ] Command line options (well dimensions, tetriminoes colors, ...)
- [ ] Default options config files
      (in the [libconfig](https://hyperrealm.github.io/libconfig/) format)
- [ ] Add level and accelerate fall according to it.
- [ ] Display level  @HappyTramp
- [x] Generate next spawn in advance
- [x] Display next tetrimino spawn  @HappyTramp
- [ ] Game over when no more space
- [ ] Display end game screen with scores  @HappyTramp
- [ ] Log previous games score

## FIXME

- [x] Tetrimino rotation
- [x] Full lines clear

### Fonts

- [Potra](./fonts/potra)
- [Monofonto](./fonts/monofonto)
