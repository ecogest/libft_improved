#! /usr/bin/env bash

[ ! -d build ] && mkdir build

cd build
if cmake .. && make ; then
	[ ! -L ../compile_commands.json ] && ln -s "$PWD/compile_commands.json" ../compile_commands.json
fi
