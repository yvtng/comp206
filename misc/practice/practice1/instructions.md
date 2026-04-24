# Practice problem set 1: log analysis with Bash

In this assignment, you'll be writing some scripts to process a given log file
`nginx.log`, seen in class, which records a history of requests made to a web server.


The format of most lines is 

```
IP_ADDRESS - - [DATE:TIME TIMEZONE] "METHOD RESOURCE PROTOCOL" STATUS BYTES "REFERRER" "USER_AGENT"
```

**Your task** is to create the following analysis scripts:

1. `robot` to be used in the following way
   * `./robot nginx.log` -- counts the number of lines in which "/robots.txt" appears.

2. `largest_number_of_bytes` to be used in the following way
   * `./largest_number_of_bytes nginx.log` extracts the largest number of bytes
     that's in the log file. That is, the greatest of the BYTES values across all lines.

3. `line_of_largest_bytes` to be used in the following way
   * `./line_of_largest_bytes nginx.log` -- extracts the line number of the last occurence of largest number of bytes that's in the log file.


## Assumptions

- Your script should read from the log file given as the first positional argument.
- Each script outputs only a single number to stdout.

## Remarks

Some log lines contain missing or invalid fields.
You can ignore those lines when computing largest byte result.
(Use the strategy seen in class to check whether something is a number.)
