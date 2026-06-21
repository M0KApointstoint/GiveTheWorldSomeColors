# Git notes

A running log of git concepts covered, with the commands used. Written for
future-me to skim before picking the project back up.

## Stage 1 — init & first commit

- `git init` creates the `.git/` folder — this is what makes a directory a repo.
- `git status` shows untracked / staged / committed state for every file.
- `git add <file>` moves a file from untracked (or modified) into staged.
- `git commit -m "message"` takes everything staged and saves it as a
  permanent snapshot in history.
