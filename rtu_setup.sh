#!/bin/bash

set -e

USERNAME=MartinsSmirnovs
DIRECTORY=RTR105

while getopts u:d:h flag
do
    case "${flag}" in
        u) USERNAME=${OPTARG};;
        d) DIRECTORY=${OPTARG};;
        h) echo -e "Usage:\n./rtu_setup.sh -u GIT_USERNAME -d GIT_DIRECTORY" && exit 0;;
    esac
done

echo
echo "Installing Visual Studio Code extensions"
code --install-extension shardulm94.trailing-spaces
code --install-extension nathanridley.autotrim
code --install-extension xaver.clang-format
code --install-extension ms-vscode.cpptools

echo
echo "Cloning git repository"
git clone https://github.com/$USERNAME/$DIRECTORY.git

echo
echo "Opening Visual Studio Code"
code $DIRECTORY

echo
echo "Done!"
