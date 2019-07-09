#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// max number of candidates
#define MAX 9

// array of vote totals and candidate names
int votes[MAX];
string candidates[MAX];

// number of candidates
int count;

// function prototypes
bool vote(string candidate);
void print_winner();

int main(int argc, string argv[])
{
    // check for invalid usage
    if (argc < 2)
    {
        fprintf(stderr, "Usage: plurality [candidate ...]\n");
        return 1;
    }

    // populate array of candidates
    count = argc - 1;
    if (count > MAX)
    {
        fprintf(stderr, "Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    int voters = get_int("Number of voters: ");

    // loop over all voters
    for (int i = 0; i < voters; i++)
    {
        string candidate = get_string("Vote: ");

        // check for invalid vote
        if (!vote(candidate))
        {
            printf("Invalid vote.\n");
        }
    }

    // display winner of election
    print_winner();
}

// update vote totals given a new vote
bool vote(string candidate)
{
    // TODO
}

void print_winner()
{
    // TODO
}
