# Mini-carapace
Minishell 42
*This project has been created as part of the 42 curriculum by nbaudoin, uuenkhba.*

# Minishell

- [Mini-carapace](#mini-carapace)
- [Minishell](#minishell)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Resources](#resources)
- [Temporary part](#temporary-part)
	- [Checklist / todolist](#checklist--todolist)
	- [branch management](#branch-management)
	- [Build](#build)
		- [Makefile](#makefile)
	- [test](#test)
		- [Edge cases](#edge-cases)
		- [Memory leaks](#memory-leaks)

## Description

Discover the challenges developers faced before windows existed.

Learn about : processes and file descriptiors

## Instructions

## Resources

- [conventional branch](https://conventional-branch.github.io/)</br></br></br>

# Temporary part

## Checklist / todolist

- [ ] Makefile
  - [ ] make a makefile that works for minishell
- [ ] Readme
  - [x] Basic structure + info
  - [ ] add continiously what we are doing
- [ ] Setup headers
  - [ ] Includes
  - [ ] Struct
    - [ ] s_minishell
  - [ ] Macros
    - [ ] colors
  - [ ] global vairable EXIT_STATUT for signals status
- [ ] Main/init
- [ ] Parsing
- [ ] Execution
- [ ] Built-in commands
  - [ ] **echo()** - Prints arguments with optional newline
  - [ ] **pwd()** - Prints current working directory
  - [ ] **cd()** - Changes directory
  - [ ] **unset()** - Removes environment variables
  - [ ] **remove_env()** - Helper for unset
- [ ] Environnement variable
- [ ] Path resolution
- [ ] Signal handlings
- [ ] Testing
  - [ ] basic entry
  - [ ] edge cases to test
  - [ ] comparaison testing
  - [ ] memory leaks


## branch management

what's the diffrent branch :

- **main** : default branch, where the project must stay stable and norm proof
- **dev** : where we prepare a release on main (dev can be called release)

optional :
- **chore/**[anyname] : when it's not about code
- **feat/** when we work on a new features exemple : feat/echo or feat/parse_empty_args
- **fix/** when we need to fix a problem and do magic stuff exemple : fix/input_quoteception
- (not necessary here) **hotfix/** to do urgent fix or bugfix or quick fix.

## Build

### Makefile

need -lreadline for :

Command line editing
Command history
Input reading with prompts readline()

## test

### Edge cases


- [ ] Edge Cases to Test
- [ ] Empty input
- [ ] Only spaces/tabs
- [ ] Unclosed quotes: echo "hello
- [ ] Invalid pipes: | ls, ls |, ls | | grep
- [ ] Invalid redirections: >, < >, >> <<
- [ ] Very long input (> 1000 characters)
- [ ] Multiple consecutive spaces
- [ ] Special characters in quotes
- [ ] Environment variable expansion: $VAR, $?, $$
- [ ] Commands not in PATH
- [ ] Permission denied errors
- [ ] Directory vs file errors

### Memory leaks

**to avoid leaks from readline**

- create readline.supp
```bash
{
   readline_still_reachable
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   obj:*/libreadline.so.*
}
```
- then run :
```bash
valgrind --leak-check=full --suppressions=readline.supp ./minishell
```







