#!/bin/bash

#   usage:
#       add <item_name> <quantity> <price>
#       remove <item_name> <quantity>
#       list
#       total
function add(){}
function remove(){}
function list(){}
function total(){}

function robust_parser(){
    if [ "$#" -lt 1 ] || [ "$#" -gt 4 ]; then
        echo "Error: expected at least one argument" >&2
        echo "Try: "$0" -h" >&2
        exit 1
    fi

}

if [ "${1-}" = "-h" ] || [ "${1-}" = "--help" ]; then
    usage
    exit 0;
fi
     

cmd="$1"

case "$cmd" in
    add)
        
