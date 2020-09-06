#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void usage() {
    printf("Usage: blr [-weh] [language] [filename]\n\nCommands:\n    -w    write a file\n    -e    write an executable file\n    -h    display this help message\n\nLanguages:\n    c\n    bash\n    tex\n    html\nNOTE: language names are case insensitive.\n");
}

int write(FILE ** pntr, char lang[], char name[]);

int main (int argc, char *argv[]) {

    FILE * fp = fopen(argv[3], "w");

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) { usage(); return 0; };
    if (argv[1][0] != '-') { printf("Invalid Argument.\n"); return 1; };

    switch (argv[1][1]) {
        case 'w' :
            write(&fp, argv[2], argv[3]);
            break;
        case 'e' :
            write(&fp, argv[2], argv[3]);
            chmod(argv[3], 0755);
            break;
        default :
            printf("Invalid Argument.\n");
            return 1;
    }


    fclose(fp);
    printf("Created `%s` file `%s`.\n", argv[2], argv[3]);
    return 0;
}

int write (FILE ** pntr, char lang[], char name[]) {
    if (strcasecmp(lang, "c") == 0) { 
        fprintf(*pntr, "#include <stdio.h>\n#include <stdlib.h>\n\nint main(int argc, char *argv[]) {\n\n    <++>\n\n    return 0;\n}\n");
    } else if (strcasecmp(lang, "bash") == 0) {
        fprintf(*pntr, "#!/bin/bash\n\n<++>\n");
    } else if (strcasecmp(lang, "tex") == 0) {
        fprintf(*pntr, "\\documentclass{article}\n\n\\begin{document}\n\n<++>\n\n\\end{document}\n");
    } else if (strcasecmp(lang, "html") == 0) {
        fprintf(*pntr, "<!DOCTYPE HTML>\n\n<html>\n    <head>\n        <++>\n    </head>\n\n    <body>\n        <++>\n    </body>\n</html>");
    } else {
        remove(name);
        printf("Invalid or unsupported language.\n");
        exit(1);
    }
}
