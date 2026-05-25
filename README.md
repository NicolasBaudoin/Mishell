*This project has been created as part of the 42 curriculum by nbaudoin*
*It's a solo try to discover concepts by myself*
<a id="#top"></a>

# MINISHELL

- [MINISHELL](#minishell)
	- [Description](#description)
	- [Architecture](#architecture)
			- [Supported Features](#supported-features)
			- [Why This Project?](#why-this-project)
	- [Instructions](#instructions)
		- [How to Compile and Run](#how-to-compile-and-run)
			- [Cleaning the project](#cleaning-the-project)
			- [Important Notes](#important-notes)
	- [Resources](#resources)
		- [Official Documentation](#official-documentation)
		- [Useful Articles \& Tutorials](#useful-articles--tutorials)
		- [42 School Related](#42-school-related)
		- [Tools](#tools)
		- [How AI Was Used in This Project](#how-ai-was-used-in-this-project)
	- [Development](#development)
		- [branch management](#branch-management)
		- [Structure visualisation](#structure-visualisation)
		- [Minishell — Roadmap](#minishell--roadmap)
			- [Lexer (✅ 15/05/2026)](#lexer--15052026)
			- [🔧 Parser (✅ 23/05/2026)](#-parser--23052026)
			- [🔀 Expander](#-expander)
			- [⚙️ Exécution](#️-exécution)
			- [🏠 Builtins](#-builtins)
			- [🎯 Bonus](#-bonus)
			- [🎯 Test to handle](#-test-to-handle)
			- [Memory leaks](#memory-leaks)


## Description
Minishell is a custom Unix shell developed as part of the 42 School curriculum. It is a simplified but functional version of Bash, designed to help students understand how shells work at a low level.
In simple terms, Minishell allows you to interact with your system through the command line by:

Displaying a prompt and reading user input.
Executing commands (both built-in and external programs).
Supporting pipes, redirections, heredoc, and variable expansion.

## Architecture

```
input (readline)
	 ↓
  Lexer        → liste de tokens
	 ↓
  Parser       → liste de t_cmd
	 ↓
  Expander     → expansion $VAR, quotes
	 ↓
  Exécution    → fork, execve, pipes, redirections
```

#### Supported Features

*   Prompt with command history using readline()
*   Pipes |
*   Redirections: <, >, >>, << (heredoc)
*   Environment variable expansion ($VAR, $?)
*   Quotes handling: single quotes (' ') and double quotes (" ")
*   Signals: Ctrl+C, Ctrl+D, Ctrl+\ (behaves like bash)
*   Built-in commands:

		echo with -n option
		cd (with relative and absolute paths)
		pwd
		export
		unset
		env
		exit

#### Why This Project?
Minishell is one of the most difficult and educational projects at 42. It teaches many core concepts of system programming, such as:
*   Processes (fork, execve)
*   File descriptors (pipe, dup2, redirection)
*   Parsing (tokenization, quote handling, expansion)
*   Signal handling
*   Memory management

By completing this project, you will gain a deep understanding of how real shells like Bash operate.

[**back to top**](#top)

## Instructions
### How to Compile and Run

1. Clone the repository

```bash
>git clone  [vogsphere_link] [custom_name_optional]
```

2. Compile the project

```bash
>cd [name_of_directory_cloned]
>make
```
this will compilate and create the ./minishell executable

3. Launch Minishell

```bash
>./minishell
```
4. Start using it
Once launched, you will see the prompt:

```bash
minishell>
```
You can now type commands just like in Bash.

#### Cleaning the project

```Bash
>make clean  # Remove object files
>make fclean # Remove everything (executable + libft + objects)
>make re # Recompile the entire project
```
#### Important Notes

*   Make sure readline library is installed on your system.
*   The project must be compiled with the flags -Wall -Wextra -Werror.
*   Memory leaks from the readline() function itself are allowed (as per 42 subject), but your own code must be leak-free.
*   Use valgrind to check for memory leaks:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./minishell
```

[**back to top**](#top)

## Resources
### Official Documentation

*   Bash Manual
*   POSIX Shell Command Language
*   GNU Readline Library
*   Linux Manual Pages (especially execve, fork, pipe, dup2, signal)

### Useful Articles & Tutorials

*   Writing a simple shell in C (basic concepts)
*   Understanding Unix Processes and File Descriptors
*   How Shells Work – Everything You Need to Know
*   Heredoc Implementation Guide (search for <<)
*   [Conventional branchs](https://conventional-branch.github.io/)

### 42 School Related

*   Minishell Subject PDF
*   42 Common Instructions & Norm

### Tools

*   Valgrind – Memory leak detection
*   lldb / gdb – Debugging
*   readline tester & custom testers


### How AI Was Used in This Project
AI tools were used responsibly as a learning assistant in the following areas:

*   Explaining complex concepts (signals, file descriptors, heredoc logic).
*   Debugging difficult parts (especially parsing and expander logic).
*   Generating boilerplate code (Makefile structure, basic function templates).
*   Creating this README.md file (structure, examples, and formatting).
*   Suggesting better data structures and cleaner code organization.

All AI-generated code was carefully reviewed, understood, and modified before being used. No large portions were copy-pasted without full comprehension.

[**back to top**](#top)



<br><br>
## Development

### branch management

what's the diffrent branch :

- **main** : default branch, where the project must stay stable and norm proof
- **dev** : where we prepare a release on main (dev can be called release)

optional :
- **chore/**[anyname] : when it's not about code
- **feat/** when we work on a new features exemple : feat/echo or feat/parse_empty_args
- **fix/** when we need to fix a problem and do magic stuff exemple : fix/input_quoteception
- (not necessary here) **hotfix/** to do urgent fix or bugfix or quick fix.

### Structure visualisation

```bash
input : "echo hello | cat"

Tokens :
[echo] → [hello] → [|] → [cat] → NULL

Commands :
t_cmd                t_cmd
---------                ---------
args = ["echo","hello"]  args = ["cat"]
redirs = NULL       →    redirs = NULL
next ────────────────►   next = NULL
```

### Minishell — Roadmap

####  Lexer (✅ 15/05/2026)
- [x] Tokenisation des mots, opérateurs, quotes
- [x] Détection quotes non fermées
- [x] Gestion mémoire (free_tokens)
- [x] Signaux SIGINT / SIGQUIT
- [x] Refacto norme 42 (25 lignes)

#### 🔧 Parser (✅ 23/05/2026)
- [x] Structures t_cmd et t_redir
- [x] compter les args avant pipe
- [x] remplir char **args
- [x] construire liste t_redir
- [x] construire liste t_cmd
- [x] Détection erreurs syntaxe (pipe seul, etc.)
- [x] free_commands() — libération mémoire

#### 🔀 Expander
Todo :
- [ ] Expansion $VAR dans les WORD
- [ ] Expansion $? (exit status)
- [ ] Pas d'expansion dans les single quotes
- [ ] Expansion dans les double quotes
- [ ] $ seul ou suivis d'un character non valide -> garde le $ littéral
- [ ] Variable inexistante -> string vide
  - [ ] Quotes
    - [x] Suppression des single quotes
    - [x] suppresion des double quotes
    - [x] Quotes imbriquées : "hello"world -> helloword
    - [ ] Quotes vides: "" ou '' -> string vide conservée comme arg
**Steps**
- [x] **1.Suppression des quotes**: Parcourir chaque args[i] et reconstruire la string sans les quotes
- [ ] **2.Expansion des variables**: Detecter `$` dans les WORD, extraire le nom de la variable, chercher dans `env`, remplacer
- [ ] **3.Expansion `$?`**: Cas spécial -> remplacer par g_status
- [ ] **4.Combiner les deux**: L'ordre correct -> expansion d'abord, suppression des quotes ensuite
- [ ] **5.Intégrer dans le pipeline**: Appeler l'expander sur chaque `t_cmd` après le parser, avant l'execution

#### ⚙️ Exécution
- [ ] Recherche dans PATH (execve)
- [ ] Gérer envp -i
- [ ] Gestion des pipes (fork + pipe)
- [ ] Redirections (dup2)
- [ ] Heredoc (pipe temporaire)
- [ ] Mise à jour de g_status après exécution

#### 🏠 Builtins
- [ ] echo (-n)
- [ ] cd (avec ~, -, path relatif/absolu)
- [ ] pwd
- [ ] export
- [ ] unset
- [ ] env
- [ ] exit

#### 🎯 Bonus
- [ ] && et ||
- [ ] Wildcards *
- [ ] Sous-shells ()

#### 🎯 Test to handle
- [ ] Empty input
- [ ] Only spaces/tabs
- [x] Unclosed quotes: echo "hello
- [ ] Invalid pipes: | ls, ls |, ls | | grep
- [ ] Invalid redirections: >, < >, >> <<
- [ ] Very long input (> 1000 characters)
- [ ] Multiple consecutive spaces
- [ ] Special characters in quotes
- [ ] Environment variable expansion: $VAR, $?, $$
- [ ] Commands not in PATH
- [ ] Permission denied errors
- [ ] Directory vs file errors

#### Memory leaks

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
