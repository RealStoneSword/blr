const char *supported_langs[] = {"c", "cpp", "bash", "tex", "html"};
const char *templates[] = {
    ( /* c */
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n"
    "\n"
    "int main(int argc, char *argv[]) {\n"
    "    <++>\n"
    "\n"
    "    return 0;\n"
    "}"
    ),

    ( /* cpp */
    "#include <iostream>\n"
    "\n"
    "using namespace std;\n"
    "\n"
    "int main(int argc, char *argv[]) {\n"
    "    <++>\n"
    "\n"
    "    return 0;\n"
    "}"
    ),

    ( /* bash */
    "#!/bin/sh\n"
    "\n"
    "<++>"
    ),

    ( /* tex */
    "\\documentclass{article}\n"
    "\n"
    "\\begin{document}\n"
    "\n"
    "<++>\n"
    "\n"
    "\\end{document}"
    ),

    ( /* html */
    "<!DOCTYPE HTML>\n"
    "\n"
    "<html>\n"
    "    <head>\n"
    "        <++>\n"
    "    </head>\n"
    "    <body>\n"
    "        <++>\n"
    "    </body>\n"
    "</html>"
    )
};
