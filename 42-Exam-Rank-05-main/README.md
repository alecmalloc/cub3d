# 42-Exam-Rank-05

Let's share our knowledge of the exam here.

If you have more information, please specify and/or transcribe the subjects further.

Corrections, functional improvements of solutions, and alternative solution approaches are welcome.

An overview of what we know so far:

| Level | Task    | Known subject | Transcribed subject | Solution available  | Solution passed exam                                              |
|-------|---------|---------------|---------------------|---------------------|-------------------------------------------------------------------|
| 1     | argo    | Yes           | Yes                 | Yes                 | [solution-ksansom](Level%201/argo/solution-ksansom/rendu)         |
| 1     | vbc     | Yes           | Yes                 | Yes                 | [solution-denizozd](Level%201/vbc/solution-denizozd/rendu)        |
| 2     | bigint  | Yes           | Yes                 | Yes                 | [solution-tischmid](Level%202/bigint/solution-tischmid/rendu)     |
| 2     | polyset | Yes           | Yes                 | Yes                 | [solution-ksansom](Level%202/polyset/solution-ksansom/rendu)      |
| 2     | vect2   | Yes           | Yes                 | Yes                 | [solution-denizozd](Level%202/vect2/solution-denizozd/rendu)      |
| 3     | life    | Yes           | Yes                 | Yes                 | [solution-thofting](Level%203/life/solution-thofting/rendu)       |
| 3     | bsq     | Yes           | Yes                 | Yes                 | [solution-tischmid](Level%203/bsq/solution-tischmid/rendu)        |


Note: The owner of this repository is no longer maintaining the code; it is now the responsibility of the current users to maintain it.

# Submission Recommendations
Per task (`bsq`, `bigint`, `vbc`, ...) create a folder with one of the following names:
- solution-LOGIN
- cleaned-solution-LOGIN

where LOGIN is replaced with your intra name.
The solution folder should contain the solution AS IS,
unmodified (otherwise how can you guarantee that it passes the exam?), with traces and subject. If you want
to submit cleaned up code, create the other directory. It might seem redundant to include the subject every time, but for
BSQ, pedago had to change it to make it work, therefore subjects can change.

# How to get the traces, subjects, and your code
During the exam, run a command like this to bundle up all the interesting folders:
```sh
tar czf ~/exam.tgz ~/subjects/ ~/traces/ ~/rendu/
mv ~/stuff.tgz /var/lib/php/sessions
```
You can also move it to `/tmp`, but it might not be super safe to do that.
Make sure to remember the computer you did the exam on.

Then, you have to login to the exact same computer and get back the archive
## For a failed exam
```sh
$ mkdir ~/failed_exam
$ mv /var/lib/php/sessions/stuff.tgz ~/failed_exam
$ cd ~/failed_exam
$ tar xf stuff.tgz
```

## For a successful exam that you want to submit to this repo (example: bigint, login: mmusterm)
```sh
$ # Replace '42-Exam-Rank-05' with the actual location of this git repo on your machine
$ SOLUTION_DIR="$HOME/42-Exam-Rank-05/Level 2/bigint/solution-mmusterm"
$ mkdir -p "$SOLUTION_DIR"/{tmp,rendu,subject,traces}
$ mv /var/lib/php/sessions/stuff.tgz "$SOLUTION_DIR/tmp"
$ cd "$SOLUTION_DIR/tmp"
$ tar xf stuff.tgz && rm stuff.tgz
$ # clean up stuff (remove unrelated traces, etc.)
$ mv subjects/bigint/* ../subject/
$ mv traces/*bigint* ../traces/
$ mv rendu/bigint/* ../rendu/
$ cd ..
$ rm -rf tmp
$ # it should now look like this:
$ pwd
/home/mmusterm/42-Exam-Rank-05/Level 2/bigint/solution-mmusterm
$ tree
.
├── rendu
│   ├── bigint.cpp
│   └── bigint.hpp
├── subject
│   ├── subject.en.txt
│   └── main.c
└── trace
    ├── 2-0_bigint.trace
    ├── 2-1_bigint.trace
    └── 2-2_bigint.trace
$ do the git stuff, add, commit, push, branch if you want
```
