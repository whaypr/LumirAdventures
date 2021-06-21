#! /bin/bash

F='drbalpat'

( cd drbalpat; make clean; )

zip -r drbalpat.zip       \
       $F/zadani.txt      \
       $F/prohlaseni.txt  \
       $F/Makefile        \
       $F/src/*           \
       $F/doc/*           \
       $F/examples/*      \
       $F/Doxyfile        \
       $F/assets/*        \
