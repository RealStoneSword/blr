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
            printf("\033[1;32m->\033[0m Invalid or unsupported language \033[1;32m`%s'\033[0m. Run \033[1;32m`blr usage'\033[0m to see supported languages.\n", argv[2]);
            return 1;
        };

        fclose(fp);
        printf("\033[1;32m->\033[0m Successfully created %s file \033[1;32m`%s'\033[0m.\n", argv[2], argv[3]);
        return 0;
    } else if (strcmp(argv[1], "wrexec") == 0 || strcmp(argv[1], "wx") == 0) { 
        if (strcmp(argv[2], "bash") == 0) {
            fp = fopen(argv[3], "w");
            fprintf(fp, "#!/bin/bash\n\n<++>\n");
        } else {
            printf("\033[1;32m->\033[0m Cannot create executable type \033[1;32m`%s'\033[0m.", argv[2]);
            return 1;
        };

        fclose(fp);
        chmod(argv[3], 0755);
        printf("\033[1;32m->\033[0m Successfully created executable %s file \033[1;32m`%s'\033[0m.\n", argv[2], argv[3]);
        return 0;
    } else if (strcmp(argv[1], "usage") == 0) {
        usage();
        return 0;
    } else {
        printf("\033[1;32m->\033[0m Invalid command \033[1;32m`%s'\033[0m.\n\n", argv[1]);
        usage();
        return 1;
    };

}
