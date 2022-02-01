//plurality
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{


    // to vote we must count each vote and give that vote to the correct candidate
    for (int y = 0; y < candidate_count; y++)
    {


        if (strcmp(name, candidates[y].name) == 0)
        {
            // this will take the candidate we are currently iterating over and add 1 to their vote count
            candidates[y].votes++;

            return true;
        }
    }

    // TODO
    // we check for true or false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int x = 0;

    // keeps track of the candidate we are looking at
    int y = 0;
    while (y < candidate_count)
    {
        if (x < candidates[y].votes)
        {
            x = candidates[y].votes;
        }

        // to go over to the next candidate
        y++;
    }


    for (y = 0; y < candidate_count; y++)
    {
        if (candidates[y].votes == x)
        {
            printf("%s\n", candidates[y].name);
        }
    }

    // TODO
    return;
}