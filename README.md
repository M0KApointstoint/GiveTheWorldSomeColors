# give_the_world_some_colors

**The whole point of this project is not the image processor itself.**

A small C image processor for PPM files, built step by step while learning
the core git workflow. Input accepts both binary (P6) and ASCII (P3) PPM;
output is always written as binary PPM (P6). The commit history is
intentionally incremental — each stage of `GIT_NOTES.md` corresponds to a
real commit or two, so the history itself is part of the lesson.

## Acquired skills:

- Using Claude Code
- Learning more about using git
- Manually handling git commands
- Reviewing code that is not writted by me

## Building

```sh
make
```

This produces an `imgproc` binary.

For the input ppm file you can use AI to write some python script that
creates such an image. The output ppm file does not need to exist.

## Usage

```sh
./imgproc <input.ppm> <filter> <output.ppm> [amount]
```

Supported filters: `grayscale`, `invert`, `flip`, `blur`, `brightness`,
`rotate`. `brightness` and `rotate` require a trailing `<amount>`:
- `brightness <amount>` — integer (can be negative), added to every pixel
  value and clamped to `[0, 255]`.
- `rotate <degrees>` — clockwise rotation, must be a multiple of 90
  (e.g. `90`, `180`, `270`, `-90`).

## Learning git from this repo

See `GIT_NOTES.md` for a stage-by-stage recap of the git concepts covered
(init, diffs/staging, branching, merging, conflicts, stashing, undo tools,
tagging) alongside the commands used.

The git history and workflow for this repo is driven directly by Cristi —
all commits, branches, and other git operations are his own.
