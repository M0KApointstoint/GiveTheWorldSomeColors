# give_the_world_some_colors

A small C image processor for binary PPM (P6) files, built step by step
while learning the core git workflow. The commit history is intentionally
incremental — each stage of `GIT_NOTES.md` corresponds to a real commit
or two, so the history itself is part of the lesson.

## Building

```sh
make
```

This produces an `imgproc` binary.

For the input ppm file you can use AI to write some python script that
creates such an image. The output ppm file does not need to exist.

## Usage

```sh
./imgproc <input.ppm> <filter> <output.ppm>
```

Supported filters: `grayscale`, `invert`, `flip`, `blur`.

## Learning git from this repo

See `GIT_NOTES.md` for a stage-by-stage recap of the git concepts covered
(init, diffs/staging, branching, merging, conflicts, stashing, undo tools,
tagging) alongside the commands used.
