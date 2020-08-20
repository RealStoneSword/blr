#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void usage() {
    printf("Usage: blr [-weh] [c,bash,latex,html] [filename]\n\nCommands:\n\t-w\t\twrite a file\n\t-e\t\twrite a executable file\n\t-h\t\tdisplay this help message\n\nLanguages:\n\tc\n\tbash\n\tlatex\n\thtml\nNOTE: language names are case insensitive.\n");
}

int write(FILE ** pntr, char lang[]);

int main (int argc, char *argv[]) {

    FILE * fp = fopen(argv[3], "w");

    if (argv[1][0] != '-') {
        printf("Invalid Argument.\n");
        return 1;
    }

    switch (argv[1][1]) {
        case 'w' :
            write(&fp, argv[2]);
            break;
        case 'e' :
            write(&fp, argv[2]);
            chmod(argv[3], 0755);
            break;
        case 'h' :
            usage();
            return 0;
        default :
            printf("Invalid Argument.\n");
            return 1;
    }

    fclose(fp);
    printf("Created %s file %s.\n", argv[2], argv[3]);
    return 0;
}

int write (FILE ** pntr, char lang[]) {
    if (strcasecmp(lang, "c") == 0) { 
        fprintf(*pntr, "#include <stdio.h>\n#include <stdlib.h>\n\nint main() {\n\n    <++>\n\n    return 0;\n}\n");
    } else if (strcasecmp(lang, "bash") == 0) {
        fprintf(*pntr, "#!/bin/bash\n\n<++>\n");
    } else if (strcasecmp(lang, "latex") == 0) {
        fprintf(*pntr, "\\documentclass{article}\n\n\\begin{document}\n\n<++>\n\n\\end{document}\n");
    } else if (strcasecmp(lang, "html") == 0) {
        fprintf(*pntr, "<!DOCTYPE HTML>\n\n<html>\n    <head>\n        <++>\n    </head>\n\n    <body>\n        <++>\n    </body>\n</html>");
    } else {
        printf("Invalid or unsupported language.\n");
        return 1;
    }
}
