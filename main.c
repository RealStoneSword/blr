#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void usage() {
    printf("Usage: blr [COMMAND] [LANGUAGE] [FILENAME]\nCreate boilerplate starter files for popular computer languages.\n\nCommands:\n - write, w\twrite a new file\n - wrexec, wx\twrite a file that is executable (for scripts)\n - usage\tdisplay this message\n\nLanguages:\n - bash\n - c\n - latex\n");
}

int main (int argc, char *argv[]) {

    FILE * fp;

    if (strcmp(argv[1], "write") == 0 || strcmp(argv[1], "w") == 0) {
        if (strcmp(argv[2], "bash") == 0) {
            fp = fopen(argv[3], "w");
            fprintf(fp, "#!/bin/bash\n\n<++>\n");
        } else if (strcmp(argv[2], "c") == 0) {
            fp = fopen(argv[3], "w");
            fprintf(fp, "#include <stdio.h>\n#include <stdlib.h>\n\nint main() {\n\n    <++>\n\n    return 0;\n}\n");
        } else if (strcmp(argv[2], "latex") == 0) {
            fp = fopen(argv[3], "w");
            fprintf(fp, "\\documentclass{article}\n\n\\begin{document}\n\n<++>\n\n\\end{document}\n");
        } else {
            printf("-> Invalid or unsupported language `%s'. Run `blr usage' to see supported languages.\n", argv[2]);
            return 1;
        };

        fclose(fp);
        printf("-> Successfully created %s file `%s'.\n", argv[2], argv[3]);
        return 0;
    } else if (strcmp(argv[1], "wrexec") == 0 || strcmp(argv[1], "wx") == 0) { 
        if (strcmp(argv[2], "bash") == 0) {
            fp = fopen(argv[3], "w");
            fprintf(fp, "#!/bin/bash\n\n<++>\n");
        } else {
            printf("-> Cannot create executable type `%s'.", argv[2]);
            return 1;
        };

        fclose(fp);
        chmod(argv[3], 0755);
        printf("-> Successfully created executable %s file `%s'.\n", argv[2], argv[3]);
        return 0;
    } else if (strcmp(argv[1], "usage") == 0) {
        usage();
        return 0;
    } else {
        printf("-> Invalid command `%s'.\n\n", argv[1]);
        usage();
        return 1;
    };

}
