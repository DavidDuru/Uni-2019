#!/bin/bash

#Testing create file

clang -Wall -Werror myfilesystem.c runtest.c -o output
./output

clear

# printf "f1 contains:\n"
# xxd -b file_data.bin
# stat -c %s file_data.bin
# printf "\n\n"


# printf "f2 contains:\n"
# xxd -b directory_table.bin
# stat -c %s directory_table.bin
# printf "\n\n"


# printf "f3 contains:\n"
# xxd -b hash_data
# printf "\n\n"

#rm file_data
# rm data_directory
#rm hash_data
