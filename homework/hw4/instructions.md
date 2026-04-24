# Practice problem set 1: file renaming with Bash

In this assignment, you'll be writing a script to rename files in a given directory.

**Your task** is to create a script called,

1. `rename` to be used in the following way

* `./rename <directory>` -- prepends the current date in `YYYY-MM-DD-` format
  to every file in the given directory, unless the filename already starts with a date.

The script should check whether a filename already starts with a date in the
format `YYYY-MM-DD-` and skip those files.

## Assumptions

* Only prepend the date once.
* Skip files that already start with a date.
* Keep files in the same directory after renaming.


## Remarks

The directory that you should be running the script on is called `dummy_data`.

You're given some starter code in the file `rename`. In particular, it contains
a helper function which checks whether a filename starts with the previously
mentioned date format.

**When testing your code locally,** you should make a copy of the `dummy_data`
first, or else you'll need to go back and rename the files manually when you
want to test again later.
