# Project purpose

This repo is a teaching vehicle: Cristi (first-year computer engineering)
is learning the core local git workflow. The C PPM image processor is the
real, working project we build *as* the vehicle for that — not a finished
deliverable in itself.

# How the git-teaching lessons worked

- One git concept per stage, paired with one small real code addition.
  Full stage-by-stage breakdown and commands used: see `GIT_NOTES.md`.
- Cristi ran the git commands himself; Claude explained what to type and
  why rather than running git on his behalf.
- Update `GIT_NOTES.md` if any further git lessons happen in this repo.

# Git ownership (as of 2026-06-21)

- The 8-stage lesson plan is done. Going forward, **Cristi owns all git
  operations in this repo, for all future work, not just lesson stages** —
  Claude must not run git commands (add/commit/branch/merge/tag/etc.) on
  his behalf, even if it would be convenient mid-task.
- Claude's job from here is to write/explain C code; Cristi will report
  back what he did or plans to do via git after each meaningful step, for
  Claude to review.

# Git lessons: status

All 8 planned stages complete as of tag `v1.0`. Core local git workflow
covered: init, staging/diff, branching, merging (fast-forward and merge
commit), conflict resolution, stashing, undo tools (amend/revert/reset),
tagging. GitHub-specific collaboration (remotes, push/pull, PRs, issues)
and `git rebase` were explicitly out of scope for this round — don't
assume Cristi wants those next, ask first.

# Current state of the image processor

- `ppm.h` — `Image` struct: `width`, `height`, `pixels` (flat RGB byte
  array, 3 bytes per pixel, row-major).
- `ppm.c` — `ppm_read` accepts both binary (P6) and ASCII (P3) PPM input.
  `ppm_write` always emits binary PPM (P6); no P3 output support.
- `filters.c`/`filters.h` — `filter_grayscale`, `filter_invert`,
  `filter_flip` (horizontal mirror), `filter_brightness` (takes an
  `amount` param, not wired into the CLI), `filter_blur` (3x3 box blur).
- `main.c` — CLI dispatch: `./imgproc <input.ppm> <filter> <output.ppm>`.
  Wired filters: `grayscale`, `invert`, `flip`, `blur`. `brightness`
  exists as a function but has no CLI argument for `amount` yet.
- `Makefile` — builds `imgproc` from `main.c ppm.c filters.c`.
- Everything was kept intentionally minimal/unoptimized since the C code
  was a vehicle for git lessons, not the focus — expect rougher edges
  (no SIMD, no real error messages beyond stderr one-liners, single
  malloc per image with no chunking) if the next task is something more
  ambitious like new image formats, performance work, or a filter
  pipeline/chaining system.
