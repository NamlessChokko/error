# error

A simple utility that exits with a custom status code.  
This can be useful for testing scripts, pipelines, or error handling logic.  

---

## Usage  

The program takes **exactly one argument**:  

```bash
error {number}
````

* `{number}` must be an integer.
* The exit code is always returned as a **single byte (0–255)**.
* Values outside this range will wrap around (overflow).

### Examples:

```bash
error 30    # $? = 30
error 0     # $? = 0
error 258   # $? = 2   (because 258 % 256 = 2)
error -5    # $? = 251 (because -5 % 256 = 251)
```

---

## Installation

### Compile

```bash
gcc main.c -o error -lm
```

### Install

Move the binary into a directory included in your `$PATH`, for example:

```bash
sudo mv error /usr/local/bin/
```

Now you can run `error` from anywhere.

---

## Notes

* If no argument is provided, the program exits with code `0`.
* Non-numeric input will also result in exit code `0`.
* Internally, the conversion logic is very minimal and doesn’t handle edge cases like very large numbers or whitespace.

---

## Example

```bash
$ error 42
$ echo $?
42

$ error 999
$ echo $?
231
```


