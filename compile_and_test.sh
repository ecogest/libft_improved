#!/usr/bin/env bash

# executable_name="a.out"
executable_tester_name="UnitTests"
build_directory=".build"
src_directory="src"

compiling=false
testing=false
norminette=false
execute=false
test_regex=
leak_checking=false

leak_program=

# Usage and parsing {{{
usage() {
  printf "Usage: \e[32m./$executable_tester_name\e[33m [-a|-all] [-e|--execute] [-h|--help] [-l|--leaks] [-n|--norminette] [-t|--test [\e[3mtest-regex\e[23m]]\e[0m\n"
  echo "Rebuild executable except if only \`--norminette' parameter is given."
  echo "If no parameter is given, only build. Does not execute nor run the tests."
}
if [ $# -eq 0 ]; then compiling=true; fi

PARAMS=()
while [ $# -gt 0 ]; do
  case "$1" in
    -a|--all)
      compiling=true
      testing=true
      norminette=true
      leak_checking=true
      shift
      ;;
    -e|--exe*)
      compiling=true
      execute=true
      shift
      ;;
    -l|--leaks)
      compiling=true
      leak_checking=true
      shift
      ;;
    -n|--norm*)
      norminette=true
      shift
      ;;
    -t|--test*)
      compiling=true
      testing=true
      shift
      if [ -n "$1" ] && [ ${1:0:1} != "-" ]; then
        test_regex="-R $1"
        shift
      fi
      ;;
    -h|--help*)
      usage
      exit 0
      ;;
    --)
      shift
      break
      ;;
    -*) # unsupported flags
      printf "\e[31mError: Unsupported flag $1\e[0m" >&2
      exit 1
      ;;
    *) # preserve positional arguments
      PARAMS+=("$1")
      shift
      ;;
  esac
done
# set positional arguments in their proper place
set -- "${PARAMS[@]}" "$@"
#}}}
# Put section function{{{
repeat_char() {
  printf %$1s | tr " " $2
}
put_section() {
  color="\e[34m"
  start="#"
  middle="="
  len_title=${#1}
  printf "\n$color$start "
  repeat_count=$((80 - 4 - 2*${#start} - len_title))
  left_repeat_count=$((repeat_count / 2))
  right_repeat_count=$((repeat_count - left_repeat_count))
  repeat_char $left_repeat_count $middle
  echo -n " $1 "
  repeat_char $right_repeat_count $middle
  printf " $start\e[0m\n\n"
}
#}}}
# Leak program{{{
if $leak_checking; then
  if type valgrind  &> /dev/null; then
    # valgrind is prefered tool. May set -q option in the future.
    leak_program="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes "
  elif type leaks  &> /dev/null; then
    leak_program="leaks --atExit --quiet -- "
  else
    printf "\e[31mNo leak detection utility installed on this system.\n"
    printf "\`valgrind' or \`leaks' required\e[0m\n"
  fi
fi

#}}}
# ================================ COMPILING ================================= #

if $compiling; then
put_section "COMPILING"

cmake -S. -B"$build_directory"
cmake --build "$build_directory"
ln -sf "$build_directory/compile_commands.json" compile_commands.json
# ln -sf "$build_directory/$src_directory/$executable_name" "$executable_name"
ln -sf "$build_directory/tests/$executable_tester_name" "$executable_tester_name"
fi

# ================================= TESTING ================================== #

if $testing; then
put_section "TESTING"

GTEST_COLOR=1 $leak_program ctest --test-dir "$build_directory/tests/" $test_regex --output-on-failure
rm -rf Testing # Sometimes ctest creates a Testing folder
fi

# ================================ NORMINETTE ================================ #

if $norminette; then
put_section "NORMINETTE"

python3 -m norminette
fi

# ================================= EXECUTE ================================== #

if $execute; then
put_section "EXECUTE"

# $leak_program "./$executable_name"
fi

# vim: fdm=marker
