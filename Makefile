# A sample Makefile
# This Makefile demonstrates and explains
# Make Macros, Macro Expansions,
# Rules, Targets, Dependencies, Commands, Goals
# Artificial Targets, Pattern Rule, Dependency Rule.

# Comments start with a # and go to the end of the line.

# This is a simple make Macros that contains the flags for the
# compiler: -Wall prints all warning; -std=c11 instructs gcc to use
# the ANSI 2011 standard; and -g instructs gcc to output the symbol
# table so gdb, the GNU debugger, will work.
CFLAGS  = -Wall -std=c11 -g
LIBS = -lm

# This make instruction lets the program know that clean does not have
# any dependencies
.PHONY: clean 

# Here is a simple Make Macro that defines the name of the app we are
# making.
APP = calc

# Object files are designated by a .o, we delete them when we want to
# start again.
OBJS =  calc.o main.o

# Test files are in the test directory
TEST_OBJS = test/test.o test/test_main.o

# There are two standard targets your Makefile should probably have:
# "all" and "clean", because they are often command-line Goals.  Also,
# these are both typically Artificial Targets, because they don't
# typically correspond to real files named "all" or "clean".

# The rule for "all" is used to incrementally build your system.  It
# does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all : $(APP)
	echo All done

# Here is a Make Macro defined by two Macro Expansions.  A Macro
# Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in
# (parentheses).

# This macro describes all of the things that make will build.
REBUILDABLES = $(OBJS) $(APP) $(TEST_OBJS) calc_test

# Emacs creates backup files with a ~ as the final character. This
# defines the backup files so we can remove them.
BACKUPS = *~ test1/*~

# Make Macros do not need to be defined before their Macro Expansions,
# but they normally should be defined before they appear in any Rules.
# Consequently Make Macros often appear first in a Makefile.

# Here is a simple Rule (used for "cleaning" your build environment).
# It has a Target named "clean" (left of the colon ":" on the first
# line), no Dependencies (right of the colon), and two Commands
# (indented by tabs on the lines that follow).  The space before the
# colon is not required but added here for clarity.

# Make clean removes all of the files that make creates and all of the
# emacs backup files.
clean :
	rm -f $(REBUILDABLES) $(BACKUPS) *~ **/*~
	echo Clean done

# There is no required order to the list of rules as they appear in
# the Makefile.  Make will build its own dependency tree and only
# execute each rule only once its dependencies' rules have been
# executed successfully.

# Here is a Rule that uses some built-in Make Macros in its command:
# $@ expands to the rule's target, in this case "calc".  $^ expands to
# the rule's dependencies, in this case the two files main.o and
# calc.o
$(APP) : $(OBJS)
	gcc $(CFLAGS) -o $@ $^ $(LIBS)

# This rule says to make a test, which we will call calc_test, you
# will need the TEST_OBJS (test_main and test, both of which are in
# the test directory). We also need to include the cunit library
# (lcunit).
test : $(TEST_OBJS) calc.o
	gcc $(CFLAGS) -o calc_test $^ -lcunit $(LIBS)

# Here is a Pattern Rule, often used for compile-line.  It says how to
# create a file with a .o suffix, given a file with a .c suffix.
# The rule's command uses some built-in Make Macros: $@ for the
# pattern-matched target $<; for the pattern-matched dependency

# This rule indicates that any time a file with a .o extension is
# older than the thing with a .c extension, recompile it. It also says
# to make recompile by calling the gcc compile the .c file using the
# CFLAGS and to put the output in the .o file.
%.o : %.c
	gcc $(CFLAGS) -o $@ -c $<

# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon
# changes, the target to the left of the colon should be considered
# out-of-date.  The commands for making an out-of-date target
# up-to-date may be found elsewhere (in this case, by the Pattern Rule
# above).  Dependency Rules are often used to capture header file
# dependencies.

# These say that calc.o also depends on calc.h and that test
calc.o : calc.h
test.o : test.h
