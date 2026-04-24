# Bash Scripting: First Steps

In this exercise, you'll learn the basic usage of several
tools that form the backbone of many bash scripts.
We won't pretend that this exercise is comprehensive!
We'll talk about several more tools in the next
couple of weeks, and you'll probably find yet more useful
tools on your own.

For now, we'll focus on tools that are useful for searching
files and aggregating some data from them.

This exercise works very well if you do it with someone
next to you -- have one person keep this README file open
while the other runs the commands. Work and think together!

If you don't have a partner, that's OK too.

# Step 1: The Data File

Take a moment to open the other file, nginx.log, that came
in the tarball. You can either open it in vim, or
alternatively open it with the following command:

    $ less nginx.log

less is a program for reading text files. It gives you the
motion commands of vim (e.g. j/k to go down/up, q to quit)
without the ability to edit the file.

Take a look at what kind of data is in this file.
While looking, discuss with people near you what you think
you are seeing. Try not to read ahead!

# Step 2: Word Counting

You took a look? Good!

This log file is a website's request log.
Each line identifies a request (over the internet) to connect
to this website. (The website is Jake's blog.) In each line,
there's an "IP address," which identifies the computer
making the request, as well as some data like which file is
requested, what time the request was made, whether the
request succeeded or ran into an issue, etc.

Now try passing the log file to the utility `wc`, which is
short for "word count." Your terminal interaction should
look something like this:

    $ wc nginx.log
     10000  158676  1559470

The first number is the number of lines in the file.
That's a long file! It's exactly 10000 because we produced
this log file with `head -n 10000` (a command you saw last
week).

The second number is the number of "words" in the file.
`wc` doesn't know what constitutes an english word; rather
it figures out how many blocks of text are separated by
spaces on each line and tallies those all up.
Based solely on these first two numbers, approximately how
many "words" are there per line of the file?
Count the number of words on the first line. Why might it
be different?

The final number is the size of the file in bytes.
Usually, we're not too concerned with this one.
In fact, the most common usage of `wc` is, despite the name,
to count the number of lines in a file. Try this:

    $ wc -l nginx.log

What is the meaning of the result that you get?

# Step 3: HTTP Response Codes (1)

If you've ever tried to go to a bad URL, you've probably
seen a "404," or "page not found" error. But did you know
that every time you access a webpage, it sends a number
back as a status response? 404 is just one specific status!

The two most common statuses are 404 when the page is not
found, and 200 when the page was accessed  and returned by
the website successfully.
Other status codes in the 200s are used for other types of
successful access and are more rare.
Codes in the 300s are used for things like webpage
redirection and codes in the 400s are errors, like 404.

We now introduce one of the most ubiquitous bash commands:
`grep`. Grep searches for a pattern specified by its first
input in the body of text given by its second input.
(If there is no second input, like we saw last week,
it reads from stdin, making it suitable for use in pipelines).

Start by running the following command.
WARNING: You are going to get about 2500 lines of output.

    $ grep 200 nginx.log

Notice how every line of the output contains the number 200.
If you're using a .bashrc that enables color, the 200 should
even be highlighted in red so that you can spot it easily.

For most of these lines, that 200 is in the response code.
But try running this variant:

    $ grep 200901 nginx.log

There is exactly one line of output. In other words, exactly
one line of the log file contains this number. Do you think
this line was or was not included in the output from the
first grep command?

When you're ready to check your understanding, the following
command will run the first grep command, and then pipe the
output to the second. If this produces a line of output,
then the "bad" line containing 200901 is contained in the
output of the first grep command.

    $ grep 200 nginx.log | grep 200901

Take a moment to check your understanding with those
around you.

# Step 4: HTTP Response Codes (2)

Even though we know `grep` turns up some false positives
for status code 200, we might still be interested in
counting just how many responses there were with code 200.
We might also be interested in codes, 206 (hehe), 400, and
404.

Can you come up with a way to build a pipeline that counts
how many lines contain a specific number? Run that pipeline
for 200, 206, 400, and 404. Be sure to discuss your
understanding with your partner/neighbours!

# Step 5: HTTP Response Codes (3)

The pattern above is so commonly useful that grep provides
some direct support for it, without needing a pipeline.
Try this:

    $ grep 200 nginx.log -c

What is the output? What does it mean? What do you think
`-c` is short for?

# Step 6: Unique Incoming IP Addresses

Another commonly-required task is to figure out how many
(or which) bits of data in a file are duplicated, and how
many copies there are. Equivalently, we may want to know
how many unique pieces of data there are.

The first entry in each line of the log file is an IP
address. Let's try to figure out how many of those IP
addresses are distinct. Unfortunately, `grep` won't
help us here.

Let's start with a simpler problem. First, let's create
a file that contains 100 random numbers between 0 and 9.
You don't have to understand what's happening here yet,
just run the following command:

    $ for _ in {1..100}; do echo $(( $RANDOM % 10 )) >> numbers; done

This will create a new file called `numbers` containing 100
lines, each of which is a random number between 0 and 9.

If you make a mistake entering this command, it's possible
that your terminal may appear "stuck." It thinks the command
isn't over and that you have more stuff to enter. If this
happens to you, just hit Ctrl+C to make it stop waiting,
and then try again.

We can now try to figure out how many of these random
numbers are unique (hopefully, 10 of them!) and how many
times each number appears.

Let's start by making sure there are 100 lines.

    $ wc -l numbers
       100

Good!

Now we'll introduce a new command: `uniq`, short for
"unique". `uniq`'s task is to remove duplicate lines
from its input. Try this command:

    $ uniq numbers

Well that's definitely not right. What happened??
Did I just lie to you?? Well, maybe a little bit.

Try this command:

    $ uniq numbers | wc -l

Unless you're spectacularly unlucky (about 3 in 100,000),
this number will be less than 100. So `uniq` removed some
lines, but clearly not enough lines. Why not?

PAUSE HERE AND DISCUSS WITH YOUR PARTNER.

If you guessed that `uniq` only removes /adjacent/
duplicate lines, you're right on the money!

In an input like
    9
    0
    9
`uniq` does nothing.

To fix this, we must first /sort/ the input. Once the input
is sorted, all duplicate lines will be adjacent and `uniq`
can remove them. Conveniently, there's a `sort` command.
Run this:

    $ sort numbers | uniq

Unless you're spectacularly unlucky, this should print all
the numbers from 0 to 9.

But how many of each value were there? For this, `uniq`
comes with a handy-dandy `-c` switch, just like `grep`.
Give it a shot! How do you interpret the output?

PAUSE TO DISCUSS AGAIN.

Now it's time to get unique incoming IP addresses.

`sort nginx.log` will indeed sort the lines by IP addresses.
This works because the IP address happens to be the first
bit of the file. But `uniq` will do nothing on the output,
because none of the lines are /entirely/ identical.

This is a very common problem when scripting, so `sort`
comes with an extra utility for handling this. We can
instruct `sort` to operate only on a specific range of words
in each line with the `-k` switch. We pass two numbers to
this switch, the starting (inclusive) and ending (exclusive)
word index to use. `sort` counts indices from 1.
So if we want to operate only on the IP address,
we can inform `sort` to operate on only the first word:

    $ sort -k 1,2 nginx.log

(It's not too picky about spaces: `-k1,2` also works.)

Unfortunately this still produces entire lines, so `uniq`
won't work. But `sort` comes prepared for this too:
the `-u` switch to `sort` /combines/ `sort` with `uniq`
and /does/ account for the word range specifier.

If you run

    $ sort -k 1,2 nginx.log | head -n 2

You should see that the very first IP address is duplicated.
If you then run

    $ sort -u -k1,2 nginx.log | head -n 2

You should see that the `-u` flag has gotten rid of one!

Now that each line contains a unique IP address, how can
you count how many unique IP addresses there are?
Do that. And of course, discuss. On average, how many
times did each IP try to access the site?

# Step 7: More Accurate Status Counting

We can use `sort` and `uniq` to get a more accurate count
of how many times each status code appears in the log,
if we combine them with a new command, `cut`.

In the previous section, we had the problem that `uniq`
can only see entire lines at once, but we wanted to focus
in on a particular word. `cut` serves the purpose of
"cutting" particular words out of each line so that later
components of the pipeline can focus on them.

Cut (usually) requires two switches:
    `-d`: the "delimiter." What separates words? By default,
        this is a tab character, which is only rarely what
        you want.
        We want spaces, so we will pass `-d' '`. The quotes
        are required for spaces. If you want commas,
        (e.g. to interact with a CSV file), `-d,` works.

    `-f`: The field index.

Open the log file and count how many spaces there are before
the status 404 on the first line. I count that it's the 9th
word. Therefore, we construct this cut command:

    $ cut -d' ' -f9 nginx.log

This produces 10000 lines of output, most of which are
status codes. We can now sort and deduplicate them.
Let's also pass `-c` to uniq like we saw earlier:

    $ cut -d' ' -f9 nginx.log | sort | uniq -c

Woah, there's some weird stuff there!

We see that we have a few thousand 200s and 404s, but also
some very, very weird ones. What's going on? I'll tell you:
those weird lines are people trying to hack Jake's blog!

That's interesting and all, but let's see if we can get
rid of those lines for the purposes of having a clean
output. Any "well-behaved" user trying to connect should
be sending a request that starts with the word GET or the
word POST (in all caps). If you grep the file for one
of these weird "codes," you'll see that the connecting user
did not do so.

Normally, grep can only search for one word. But we can give
it a fancier pattern to search for "either word A or word B."
It looks like this:

    $ grep -E "GET|POST" nginx.log

This gets rid of most of the misbehaving lines of the log.
How many connections were trying to hack Jake? Discuss.

Now that we have this, we can apply the same technique as
before to the remaining lines.

    $ grep -E "GET|POST" nginx.log | cut -d' ' -f9 | sort | uniq -c

Now we see a nice readout of all the status codes given to
non-hackers... as well as one "chmod" from a hacker we missed.

# Review

If you get to the end, amazing! Take the remaining time
to review what you've learned with your partner and/or
other neighbours. We'll come back together to talk about
scripting soon!

Learned basic usage of:
1. less
2. wc
3. grep
4. uniq
5. sort
6. cut

You also saw, without explanation, a `for`-command
and some funky stuff with `$`, parentheses, and the word
RANDOM. Within a few weeks, you'll understand that too :)
