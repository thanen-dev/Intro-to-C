#include <stdio.h>
#include <string.h>

#define MAX 100 // max number of candidates

// Candidate struct
typedef struct
{
    char name[50];
    int votes;
    float percentage;
} candidate;

// Global variables
candidate candidates[MAX];
int candidate_count;
int total_votes = 0;

// Function prototypes
void init_candidates();
void cast_vote();
void calculate_percentages();
void selection_candidates();
void bubble_candidates();
void merge_candidates();
void print_results();

int main(void)
{
    init_candidates();

    int voters;
    printf("Welcome!\n");
    printf("Number of voters: ");
    scanf("%d", &voters);

    for (int i = 0; i < voters; i++)
    {
        cast_vote();
    }

    calculate_percentages();
    bubble_candidates();
    print_results();

    return 0;
}

// Initialize candidate list
void init_candidates()
{
    candidate_count = 3; // number of candidates

    strcpy(candidates[0].name, "Thanen");
    strcpy(candidates[1].name, "Leslie");
    strcpy(candidates[2].name, "Charles");

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
        candidates[i].percentage = 0.0;
    }
}

// Collect a vote from one voter
void cast_vote()
{
    int choice;

    printf("\nPlease select your candidate:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Please enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= candidate_count)
    {
        candidates[choice - 1].votes++;
        total_votes++;
    }
    else
    {
        printf("Invalid choice. Vote not counted.\n");
    }
}

// Compute percentages for each candidate
void calculate_percentages()
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (total_votes > 0)
        {
            candidates[i].percentage = (candidates[i].votes * 100.0) / total_votes;
        }
        else
        {
            candidates[i].percentage = 0.0;
        }
    }
}

// Sort candidates by votes via bubble sort (descending)
void bubble_candidates()
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count - i - 1; j++)
        {
            if (candidates[j].votes < candidates[j + 1].votes)
            {
                candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }
}

// Print final results
void print_results()
{
    printf("\nElection Results:\n");
    printf("------------------\n");
    for (int i = 0; i < candidate_count && i < 3; i++)
    {
        char *suffix;
        if (i == 0) suffix = "st";
        else if (i == 1) suffix = "nd";
        else if (i == 2) suffix = "rd";
        else suffix = "th";

        printf("%d%s: %-7s %.2f%%\n", i + 1, suffix, candidates[i].name, candidates[i].percentage);
    }
}
