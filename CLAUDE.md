# Project purpose

This repo is a teaching vehicle: Cristi (first-year computer engineering)
is learning the core local git workflow. The C PPM image processor is the
real, working project we build *as* the vehicle for that — not a finished
deliverable in itself.

# How to work in this repo

- One git concept per stage, paired with one small real code addition.
  See `/home/m0ka/.claude/plans/hi-my-name-is-nifty-goblet.md` for the
  full stage breakdown (init, diff/staging, branching, merging, conflicts,
  stash, undo tools, tagging).
- Cristi runs the git commands himself. Explain what to type and why;
  don't run git commands on his behalf unless he asks you to.
- Keep C code minimal — just enough to make each git lesson concrete.
- Update `GIT_NOTES.md` at the end of each stage with a short recap.

# Current stage

All 8 stages complete as of tag `v1.0`. Core local git workflow covered:
init, staging/diff, branching, merging (fast-forward and merge commit),
conflict resolution, stashing, undo tools (amend/revert/reset), tagging.

If Cristi comes back wanting more: natural next topics are GitHub-specific
collaboration (remotes, push/pull, pull requests, issues) and `git rebase`,
neither of which was in scope for this round (he chose core local workflow
only). Don't assume he wants those next — ask first.
