#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// max number of candidates
#define MAX 9

// array of vote totals and candidate names
int points[MAX];
string candidates[MAX];

// number of candidates
int count;

// function prototypes
bool add_rank(int ranks[], string candidate, int rank);
void update_points(int ranks[]);
void print_winner();

int main(int argc, string argv[])
{
    // check for invalid usage
    if (argc < 2)
    {
        fprintf(stderr, "Usage: borda [candidate ...]\n");
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

    // keep querying for votes
    for (int i = 0; i < voters; i++)
    {
        // ranks[j] is rank for candidate j
        int ranks[count];
        for (int j = 0; j < count; j++)
        {
            ranks[j] = 0;
        }

        // query for ranks
        bool valid = true;
        for (int j = 1; j <= count; j++)
        {
            string candidate = get_string("Rank %i: ", j);

            // if no more votes, go to next voter
            if (!strcmp(candidate, ""))
            {
                break;
            }

            // record rank
            valid = add_rank(ranks, candidate, j);
            if (!valid)
            {
                break;
            }
        }

        // don't count invalid votes
        if (!valid)
        {
            fprintf(stderr, "Invalid vote.\n\n");
            continue;
        }

        // update point totals
        update_points(ranks);
        printf("\n");
    }

    // display winner of election
    print_winner();
}

// update ranks given a new vote
bool add_rank(int ranks[], string candidate, int rank)
{
    // TODO
}

// update vote totals given a set of ranks
void update_points(int ranks[])
{
    // TODO
}

void print_winner()
{
    // TODO
}
