#include <cs50.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// max number of voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// index representing no selected candidate
#define NO_CANDIDATE -1

// prefs[i][j] is the jth preference for voter i
int prefs[MAX_VOTERS][MAX_CANDIDATES];

// arrays of candidates, vote totals, and eliminated candidates
string candidates[MAX_CANDIDATES];
int votes[MAX_CANDIDATES];
bool eliminated[MAX_CANDIDATES];

// number of voters and candidates
int voter_count;
int candidate_count;

// function prototypes
bool record_preference(int voter, int rank, string candidate);
int tabulate();
bool print_winner(int total);
int get_minimum();
void eliminate(int min);

int main(int argc, string argv[])
{
    // check for invalid usage
    if (argc < 2)
    {
        fprintf(stderr, "Usage: runoff [candidate ...]\n");
        return 1;
    }

    // populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        fprintf(stderr, "Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        fprintf(stderr, "Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // pre-populate all preferences
        for (int j = 0; j < candidate_count; j++)
        {
            prefs[i][j] = NO_CANDIDATE;
        }

        // query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string candidate = get_string("Rank %i: ", j + 1);

            // no more ranks
            if (!strcmp(candidate, ""))
            {
                break;
            }

            // record vote, unless it's invalid
            if (!record_preference(i, j, candidate))
            {
                for (int k = 0; k < candidate_count; k++)
                {
                    prefs[i][k] = NO_CANDIDATE;
                }
                printf("Invalid vote.\n");
                break;
            }
        }

        printf("\n");
    }

    // keep holding runoffs until winner exists
    while (true)
    {
        // calculate votes given remaining candidates
        int total = tabulate();

        // check for a winner
        bool won = print_winner(total);
        if (won)
        {
            break;
        }

        // get minimum number of votes
        int min = get_minimum();

        // check for tie between all remaining voters
        bool tie = true;
        for (int i = 0; i < candidate_count; i++)
        {
            if (!eliminated[i] && votes[i] > min)
            {
                tie = false;
            }
        }

        // if tie, print all winners
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!eliminated[i])
                {
                    printf("%s\n", candidates[i]);
                }
            }
            return 0;
        }

        // eliminate last-place candidates
        eliminate(min);
    }
}

// record preference if vote is valid
bool record_preference(int voter, int rank, string candidate)
{
    // TODO
}

// tabulate votes for non-eliminated candidates
int tabulate()
{
    // TODO
}

bool print_winner(int total)
{
    // TODO
}

// gets smallest number of votes any candidate has
int get_minimum()
{
    // TODO
}

// eliminate any candidate with minimum number of votes
void eliminate(int min)
{
    // TODO
}
