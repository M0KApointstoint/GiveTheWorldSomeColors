# Git notes

A running log of git concepts covered, with the commands used. Written for
future-me to skim before picking the project back up.

## Stage 1 — init & first commit

- `git init` creates the `.git/` folder — this is what makes a directory a repo.
- `git status` shows untracked / staged / committed state for every file.
- `git add <file>` moves a file from untracked (or modified) into staged.
- `git commit -m "message"` takes everything staged and saves it as a
  permanent snapshot in history.

## Stage 2 — diff, partial staging, commit messages

- `git diff` shows unstaged changes vs. the last commit. `git diff --staged`
  shows what's staged vs. the last commit. Always check before committing.
- `git add -p <files>` walks through changes hunk by hunk, asking whether
  to stage each one — lets you split unrelated changes into separate commits.
- Commit message shape: short imperative summary line, blank line, then
  *why* (not what — the diff already shows what) if it's not obvious.
- Rule of thumb for splitting commits: if you can't describe the change in
  one sentence without "and," it's probably two commits.

## Stage 3 — branching

- `git switch -c <name>` creates a branch and switches to it in one step.
- A branch is just a movable pointer to a commit — cheap to create, cheap
  to delete if an idea doesn't pan out.
- `git log --oneline --graph --all` is the command to actually see how
  branches relate to each other.

## Stage 4 — merging

- `git merge <branch>` brings another branch's commits into the current one.
- Fast-forward: if the target branch hasn't moved since you branched off,
  git just moves the pointer forward — no new commit.
- `--no-ff` forces a real merge commit even when a fast-forward is possible,
  if you want a visible marker that a feature branch happened.
- `git branch -d <name>` deletes a branch that's been merged (safe — git
  warns you if it isn't merged yet).
