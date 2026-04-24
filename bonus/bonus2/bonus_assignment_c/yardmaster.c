#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train.h"
#include "cargo.h"

void print_help() {
    printf("Commands:\n");
    printf("  append \"LABEL\"\n");
    printf("  insert INDEX \"LABEL\"\n");
    printf("  delete INDEX\n");
    printf("  print\n");
    printf("  search \"GOOD\"\n");
    printf("  goods add INDEX \"GOOD\" QTY\n");
    printf("  goods set INDEX \"GOOD\" QTY\n");
    printf("  goods remove INDEX \"GOOD\" QTY\n");
    printf("  help\n");
    printf("  exit\n");
}

int main() {
    Train train;
    train_init(&train);

    char line[512];

    printf("YardMaster ready.\n");
    print_help();

    while (1) {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin))
            break;

        /* TODO: implement parsing and command handling */
        printf("(Parser not implemented yet)\n");

        if (strncmp(line, "exit", 4) == 0)
            break;
    }

    train_destroy(&train);
    return 0;
}

