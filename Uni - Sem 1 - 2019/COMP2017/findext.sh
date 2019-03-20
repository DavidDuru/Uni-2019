#!/bin/sh

folder=$1
ext=$2

cd $folder
if [ $(ls | wc -l) -gt 0 ]
then
    find *$ext
fi





