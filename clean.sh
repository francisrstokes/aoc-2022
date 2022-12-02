#!/bin/bash

find . -type f \( -iname \*.exe -o -iname \*.o \) | xargs rm