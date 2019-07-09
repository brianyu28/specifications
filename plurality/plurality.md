# Plurality

Implement a program that runs a plurality election, per the below.

```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```

## Getting Started

Here's how to download this problem's "distribution code" (i.e., starter code) into your own CS50 IDE. Log into [CS50 IDE](https://ide.cs50.io/) and then, in a terminal window, execute each of the below.

* Execute `cd` to ensure that you're in `~/` (i.e., your home directory).
* Execute `mkdir pset3` to make (i.e., create) a directory called `pset3` in your home directory.
* Execute `cd pset3` to change into (i.e., open) that directory.
* Execute `wget TODO` to download a (compressed) ZIP file with this problem's distribution.
* Execute `unzip plurality.zip` to uncompress that file.
* Execute `rm plurality.zip` followed by `yes` or `y` to delete that ZIP file.
* Execute `ls`. You should see a directory called `plurality`, which was inside of that ZIP file.
* Execute `cd plurality` to change into that directory.
* Execute `ls`. You should see this problem's distribution code, in a file called `plurality.c`.

## Background

Elections come in all shapes and sizes. In the UK, the [Prime Minister](https://www.parliament.uk/education/about-your-parliament/general-elections/) is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step [Electoral College](https://www.archives.gov/federal-register/electoral-college/about.html) process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the "plurality vote" (also known as "first-past-the-post" or "winner take all"). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

## Understanding

Let's now take a look at `plurality.c` and read through the distribution code that's been provided to you.

The line `#define MAX 9` is some syntax used here to mean that `MAX` is a constant (equal to `9`) that can be used throughout the program. Here, it represents the maximum number of candidates an election can have.

Notice that the file also includes definitions for two global arrays. First, there's an array of `int`s called `votes`, which will store the number of votes for each candidate. The second is an array of `string`s called `candidates`, which will store the names of each of the candidates. How are these two arrays related to each other? You can think of `candidates[i]` as the name of the `i`th candidate, and `votes[i]` as the number of votes that the `i`th candidate has. So if the string `"Alice"` is stored at `candidates[2]`, then if you want to know how many votes Alice has, you can look at `votes[2]`.

Now, take a look at the `main` function itself. See if you can find where the program sets a global variable `count` representing the number of candidates in the election, copies command-line arguments into the array `candidates`, and asks the user to type in the number of voters. Then, the program lets every voter type in a vote (see how?), calling the `vote` function on each candidate voted for. Finally, `main` makes a call to the `print_winner` function to print out the winner (or winners) of the election.

If you look further down in the file, though, you'll notice that the `vote` and `print_winner` have been left blank. This part is up to you to complete!

## Specification

Complete the implementation of `plurality.c` in such a way that the program simulates a plurality vote election.

* Complete the `vote` function. `vote` takes a single argument, a `string` called `candidate`, representing the candidate who was voted for. The function should behave as follows:
  * If `candidate` matches (case-insensitively) one of the names of the candidates in the election, then add one to that candidate's vote total. The `vote` function in this case should return `true` to indicate a successful ballot.
  * If `candidate` does not match the name of any of the candidates in the election, then the `votes` array should be left unchanged, and the `vote` function should return `false` to indicate an invalid ballot.
* Complete the `print_winner` function. The `print_winner` function should print out the name of the candidate who received the most votes in the election, and then print a newline.
  * It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.
 
## Walkthrough

TODO

## Usage

Your program should behave per the examples below.

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice
```

```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```

## Hints

* You may find the [strcasecmp](https://man.cs50.io/3/strcasecmp) function helpful for comparing whether two strings are identical.

## Testing

Be sure to test your code to make sure it handles...

* An election with any number of candidate (up to the `MAX` of `9`)
* Voting for a candidate by name, case-insensitively
* Invalid votes for candidates who are not on the ballot
* Printing the winner of the election if there is only one
* Printing the winner of the election if there are multiple winners

## How to Submit

TODO