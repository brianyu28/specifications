# DNA

Implement a program that identifies a person based on their DNA, per the below.

```
$ python profile.py data.csv sequence.txt
Erin
```

## Getting Started

Here's how to download this problem into your own CS50 IDE. Log into [CS50 IDE](https://ide.cs50.io/) and then, in a terminal window, execute each of the below.

* Execute `cd` to ensure that you're in `~/` (i.e., your home directory, aka `~`).
* Execute `mkdir pset6` to make (i.e., create) a directory called `pset6` in your home directory.
* Execute `cd pset6` to change into (i.e., open) that directory.
* Execute `wget TODO` to download a (compressed) ZIP file with this problem's distribution.
* Execute `unzip dna.zip` to uncompress that file.
* Execute `rm dna.zip` followed by `yes` or `y` to delete that ZIP file.
* Execute `ls`. You should see a directory called `dna`, which was inside of that ZIP file.
* Execute `cd dna` to change into that directory.
* Execute `ls`. You should see `data.csv`, `sequence.txt`, and `profile.py`

## Background

DNA, the carrier of genetic information in living things, has been used in criminal justice for decades. But how, exactly, does DNA profiling work? Given a sequence of DNA, how can forensic investigators identify who it belongs to?

Well, DNA is really just a sequence of molecules called nucleotides, arranged into a particular shape (a double helix). Each nucleotide of DNA contains one of four different bases: adenine (A), cytosine (C), guanine (G), or thymine (T). Every human cell has billions of these nucleotides arranged in sequence. Some portions of this sequence (i.e. genome) are the same, or at least very similar, across almost all humans, but other portions of the sequence have a higher genetic diversity, and thus vary more across the population.

One place where DNA tends to have high genetic diversity is in Short Tandem Repeats (STRs), also known as microsatellites. An STR is a short sequence of DNA bases that tends to be repeated consecutively numerous times at specific locations inside of a person's DNA. The number of times any particular STR repeats varies a lot among individuals. In the DNA samples below, for example, Alice has the STR `AGAT` repeated four times in her DNA, while Bob has the same STR repeated five times.

![Sample STRs](strs.png)

Using multiple STRs, rather than just one, can improve the accuracy of DNA profiling. If the probability that two people have the same number of repeats for a single STR is 5%, and the analyst looks at 10 different STRs, then the probability that two DNA samples match purely by chance is about 1 in 1 quadrillion (assuming all STRs are independent of each other). So if two DNA samples match in the number of repeats for each of the STRs, the analyst can be pretty confident they came from the same person. CODIS, The FBI's [DNA database](https://www.fbi.gov/services/laboratory/biometric-analysis/codis/codis-and-ndis-fact-sheet), uses 20 different STRs as part of its DNA profiling process.

What might such a DNA database look like? Well, in its simplest form, you could imagine formatting a DNA database as a CSV file, where each row corresponds to an individual, and each column corresponds to a particular STR.

```
name,AGAT,AATG,TATC
Alice,28,42,14
Bob,17,22,19
Charlie,36,18,25
```

The data in the above file would suggest that Alice has the sequence `AGAT` repeated 28 times consecutively somewhere in her DNA, the sequence `AATG` repeated 42 times, and `TATC` repeated 14 times. Bob, meanwhile, has those same three STRs repeated 17 times, 22 times, and 19 times, respectively.

So given a sequence of DNA, how might you identify who it belongs to? Well image that you looked through the DNA sequence for the longest consecutive sequence of repeated `AGAT`s, and found that the longest sequence was 17 repeats long. If you then found that the longest sequence of `AATG` is 22 repeats long, and the longest sequence of `TATC` is 19 repeats long, that would provide pretty good evidence that the DNA was Bob's. Of course, it's also possible that once you take the counts for each of the STRs, it doesn't match anyone in your DNA database, in which case you have no match.

In practice, since analysts know on which chromosome and at which location in the DNA a STR will be found, they can localize their search to just a narrow section of DNA. But we'll ignore that detail for this problem.

Your task is to write a program that will take a sequence of DNA, and a CSV file containing STR counts for a list of individuals, and output who the DNA (most likely) belongs to.

## Specification

In `profile.py` implement a program that identifies who a sequence of DNA belongs to.

* The program should require as its first command-line argument the name of a CSV file containing the STR counts for a list of individuals, and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.
* Your program should open the CSV file and read its contents into memory.
  * You may assume that the first row of the CSV file will be the column names. The first column will be the word `name`, and the remaining columns will be the STR sequences themselves.
* Your program should open the DNA sequence and read its contents into memory.
* For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats of the STR in the DNA sequence to identify.
* If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
  * You may assume that the STR counts will not match more than one individual.
  * If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print `"No match"`.

## Walkthrough

TODO

## Usage

Your program should behave per the example below:

```
$ python profile.py data.csv sequence.txt
Erin
```

```
$ python profile.py
Usage: python profile.py data.csv sequence.txt
```

```
$ python profile.py data.csv
Usage: python profile.py data.csv sequence.txt
```

## Hints

* You may find Python's [`csv`](https://docs.python.org/3/library/csv.html) module helpful for reading CSV files into memory. You may want to take advantage of either [`csv.reader`](https://docs.python.org/3/library/csv.html#csv.reader) or [`csv.DictReader`](https://docs.python.org/3/library/csv.html#csv.DictReader).
* The [`open`](https://docs.python.org/3.3/tutorial/inputoutput.html#reading-and-writing-files) and [`read`](https://docs.python.org/3.3/tutorial/inputoutput.html#methods-of-file-objects) functions may prove useful for reading text files into memory.
* Consider what data structures might be helpful for keeping tracking of information in your program. A [`list`](https://docs.python.org/3/tutorial/introduction.html#lists) or a [`dict`](https://docs.python.org/3/tutorial/datastructures.html#dictionaries) may prove useful.

## Testing

For the CSV file:

```
name,AGAT,AATG,TATC
Alice,5,2,8
Bob,3,7,4
Charlie,6,1,5
```

The following sequence should match with `Alice`:

```
AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA
```

The following sequence should match with `Bob`:

```
AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG
```

The following sequence should match with `Charlie`:

```
CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC
```

And the following sequence should have `No match`:

```
GGTACAGATGCAAAGATAGATAGATGTCGTCGAGCAATCGTTTCGATAATGAATGAATGAATGAATGAATGAATGACACACGTCGATGCTAGCGGCGGATCGTATATCTATCTATCTATCTATCAACCCCTAG
```

## How to Submit

TODO