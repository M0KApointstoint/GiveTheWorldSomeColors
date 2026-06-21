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

## Stage 5 — merge conflicts

- A conflict happens when two branches change the same lines of the same
  file differently — git refuses to guess and stops the merge.
- Markers in the file: `<<<<<<< HEAD` = your current branch's version,
  `=======` = divider, `>>>>>>> branch-name` = the incoming branch's version.
- Resolve by editing the file to what it should actually be, deleting all
  three marker lines, then `git add` the file (this also marks it resolved).
- Once every conflicted file is `add`ed, `git status` says "all conflicts
  fixed" — then `git commit` (no `-m`, git pre-fills a merge message).
- The result is a merge commit with two parents — visible in
  `git log --oneline --graph --all` as two lines joining into one.

## Stage 6 — stashing

- `git stash` shelves uncommitted changes and gives you back a clean
  working tree, without committing half-finished work.
- `git stash list` shows what's shelved; `git stash pop` restores the most
  recent one (and removes it from the stash list).
- Use this for "I need to switch context but I'm not done" — not as a
  substitute for committing real progress.
