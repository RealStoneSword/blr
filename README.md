# blr: Boilerplate
Create boilerplate starter files for computer languages.

## Compilation and Installation
1. Clone this repository (and cd into it):
```
git clone https://github.com/nswerhun/blr.git
cd blr
```
2. Install/Compile
    1. To compile only:
    ```
    make
    ```
    2. To compile and install to /usr/local/bin:
    ```
    sudo make install
    ```

## Usage
```
blr [COMMAND] [LANG] [FILENAME]
```
COMMAND:
- `-w` write a file
- `-e` write an executable file (for scripts)
- `-h` display this help message    # currently does not work

LANG (natively supported):
- `c`
- `cpp`
- `bash`
- `latex`
- `html`
\*note: lang names are case insensitive

If FILENAME already exists, it will be overwritten. Be careful. 

## Adding custom templates
I tried my best to make adding templates as easy as possible. This is subject to change in the future.

Configuration is done in `config.h`. You can see that there are two arrays, `supported_langs` and `templates`. **Each entry in** `supported_langs` **must correspond to the template in `templates`**. For example, `c` is the first entry in `supported_langs`. `c` is also the first entry in `templates`. `cpp` is the second entry in both lists. `bash` is the third. You get the idea. 

To add a template, first add an entry to `supported_langs`. This will be the name you call it by in LANG at runtime. Then, add a template in the **same index in the array** in `templates`. Lets add a custom Java template. First, we add `"java"` to `supported_langs`:
```c
const char *supported_langs[] = {"c", "cpp", "bash", "tex", "html", "java"};
```
We added `"java"` as the **last** entry in `supported_langs`, so, our template **must be the last entry** in `templates`. We can add it like so:
```c
    "    </body>\n"
    "</html>"
    ),

    ( /* java */
    "public class Main {\n"
    "    public static void main(String[] args) {\n"
    "        <++>\n"
    "    }\n"
    "}"
    )
}
```
We can see that since `"java"` is after `"html"` in `supported_langs`, `java` must also be after `html` in `templates`. I cannot stress this enough. Both arrays must be in the **same order**.

Each line must be surrounded in double quotes `" "`, and have a `\n`. So it should look like this: `"your stuff here\n"`. The last line does not need a `\n`. 
Also notice that you must add a comma before the previous entry if it is not already there. In this case, since `html` was the last entry, there was no comma. So we added it.

After this, we are done modifying the config. Run `make` to recompile the program (or `sudo make install` to reinstall it). We can now use our new template by simply running:
```
blr -w java Main.java
```

I hope this was clear enough.
