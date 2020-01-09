/*
    Name: Baljot Hansi
    Std#: 105160856
    Date: April 08, 2019 (due)
    assignment4: a simple program that loads event data from a user specified file into a linked list, then saves the data
                 stored in the linked list back into another user specified file  
*/

// Include the standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXD 41 // Define the max size of the description

// A self-referential structure to abstract the idea of an event
struct event
{
    unsigned int hour; // Holds the hour value for an event (0 - 23)
    unsigned int minute; // Holds the minute value for an event (0 - 59)
    char description[MAXD]; // Holds the description of an event

    struct event *pNext; // Holds the address of the event in the linked list
};

// A type alias for struct event
typedef struct event Event;

Event *pFirst = NULL; // Holds the address of the first event in the linked list
Event *pLast = NULL; // Holds the address of the last event in the linked list

// Function Prototypes
Event *allocEvent();
int sortList(Event *pNew);
int loadList(char *filename);
int saveList(char *filename);
void freeList();

// allocEvent: allocates the size of an Event in memory and returns the address of that space
// Input: n/a
// Output: returns the address of the newly allocated memory
Event *allocEvent()
{
    return (Event *) malloc(sizeof(Event));
}

// sortList: takes a new event that was loaded from a file and inserts it in its respective spot in the linked list
// Input: a pointer to the new event
// Output: returns 0 if the new event was not placed in the linked list (the event was a repeat of an event already stored in
// the list) or returns 1 if the new event was successfully placed in the linked list
int sortList(Event *pNew)
{
    // If the new event is a repeat of either the first or last event in the linked list, then...
    if(((pNew->hour == pFirst->hour) && (pNew->minute == pFirst->minute) && (strcmp(pNew->description, pFirst->description) == 0)) || ((pNew->hour == pLast->hour) && (pNew->minute == pLast->minute) && (strcmp(pNew->description, pLast->description) == 0)))
    {
        free(pNew); // Release from memory the new event
        return 0; // Communicate that the new event was not stored in the linked list
    }

    // Otherwise, if the new event belongs before the first event in the linked list, then...
    else if((pNew->hour < pFirst->hour) || ((pNew->hour == pFirst->hour) && (pNew->minute < pFirst->minute)) || ((pNew->hour == pFirst->hour) && (pNew->minute == pFirst->minute) && (strcmp(pNew->description, pFirst->description) < 0)))
    {
        pNew->pNext = pFirst; // Link the new event to the beginning of the linked list
        pFirst = pNew; // Make the new event the first event in the linked list
        return 1; // Communicate that the new event was stored in the linked list
    }

    // Otherwise, if the new event belongs after the last event in the linked list, then...
    else if((pNew->hour > pLast->hour) || ((pNew->hour == pLast->hour) && (pNew->minute > pLast->minute)) || ((pNew->hour == pLast->hour) && (pNew->minute == pLast->minute) && (strcmp(pNew->description, pLast->description) > 0)))
    {
        pLast->pNext = pNew; // Link the new event to the end of the linked list
        pLast = pNew; // Make the new event the last event in the linked list
        pNew->pNext = NULL; // Set the new event's next pointer to null since it is now the last event in the linked list
        return 1;
    }

    // Otherwise...
    else
    {
        Event *pCrnt = pFirst; // Holds the address of the event currently being pointed at

        // While the next event in the linked list is not the last event...
        while(pCrnt->pNext != NULL)
        {
            // If the new event occurs at an earlier time than the event next to the current event, then...
            if((pNew->hour < pCrnt->pNext->hour) || ((pNew->hour == pCrnt->pNext->hour) && (pNew->minute < pCrnt->pNext->minute)))
            {
                // Insert the new event between the current event and the event next to the current event
                pNew->pNext = pCrnt->pNext;
                pCrnt->pNext = pNew;

                break; // Break the loop
            }

            // Otherwise, if the hour and minute of the new event and the event next to the current event are the same, then...
            else if((pNew->hour == pCrnt->pNext->hour) && (pNew->minute == pCrnt->pNext->minute))
            {
                // If the descreption of the new event is the same as the description of the event next to the current event, then...
                if(strcmp(pNew->description, pCrnt->pNext->description) == 0)
                {
                    free(pNew); // Release from memory the new event
                    return 0; // Communicate that the new event was not stored in the linked list
                }

                // Otherwise, if the description of the new event is higher in alphabetical order than the event next to the current event, then...
                else if(strcmp(pNew->description, pCrnt->pNext->description) < 0)
                {
                    // Insert the new event between the current event and the event next to the current event
                    pNew->pNext = pCrnt->pNext;
                    pCrnt->pNext = pNew;

                    break; // Break the loop
                }

                // Otherwise...
                else
                {
                    // Insert the new event between the event next the current event and the event two events down from the
                    // current event
                    pNew->pNext = pCrnt->pNext->pNext;
                    pCrnt->pNext->pNext = pNew;

                    break; // Break the loop
                }
            }

            // Otherwise, make pCrnt point to the event next to the current event
            else
            {
                pCrnt = pCrnt->pNext;
            }   
        }
    }

    return 1; // Communicate that the new event was stored in the linked list
}

// loadList: loads data for a new event from a file and calls sortList in order to save the new event in a linked list
// Input: the name of the file from which the data is being loaded
// Output: returns -1 if either the file was not opened successfully or memory for the new event was not able to be allocated
//         or returns 0 if the data was successfully saved from the file
int loadList(char *filename)
{
    FILE *pFile = fopen(filename, "r"); // Open the specified file for reading

    // If the file could not be opened, then return -1
    if(pFile == NULL)
    {
        return -1;
    }

    // Otherwise...
    else
    {
        // Set pFirst and pLast to point to the new event since it is the only event in the linked list
        pFirst = allocEvent(); // Allocate memory for the new event
        pLast = pFirst;

        // If memory could not be allocated for the new event, then close the file and return -1
        if(pFirst == NULL)
        {
            fclose(pFile);
            return -1;
        }

        fscanf(pFile, "%d%d%s", &(pFirst->hour), &(pFirst->minute), pFirst->description); // Retrieve the event data from the file and store it in the first event
        pFirst->pNext = NULL; // Set the next pointer of the first new event to null since it is the only event in the linked list

        Event *pNew; // Holds the address of the new event in memory

        // While the end of the file has not been reached...
        while(!feof(pFile))
        {
            pNew = allocEvent(); // Assocate memory for the new event
            
            // If memory could not be allocated for the new event, then close the file and return -1
            if(pNew == NULL)
            {
                fclose(pFile);
                return -1;
            }

            fscanf(pFile, "%d%d%s", &(pNew->hour), &(pNew->minute), pNew->description); // Retrieve the event data from the file and store it in the new event
            sortList(pNew); // Insert the new event in its respective space in the linked list
        }
    }

    fclose(pFile); // Close the file

    return 0;
}

// saveList: saves the data from the linked list into a file
// Input: the name of the file into which the data is being saved
// Output: returns -1 if the file could not be opened or returns 0 if the files were successfully saved
int saveList(char *filename)
{
    FILE *pFile = fopen(filename, "w"); // Open the specified file for writing

    // If the file could not be opened, then return -1
    if(pFile == NULL)
    {
        return -1;
    }

    // Otherwise...
    else
    {
        Event *pCrnt = pFirst; // Holds the address of the current event

        // While the end of the linked list has and the end of the file has not been reached...
        while(pCrnt != NULL && !feof(pFile))
        {
            // If the last element in the linked list has not been reached, then...
            if(pCrnt->pNext != NULL)
            {
                fprintf(pFile, "%d %d %s\n", pCrnt->hour, pCrnt->minute, pCrnt->description); // Save the data from the current event and add a new-line
            }

            // Otherwise...
            else
            {
                fprintf(pFile, "%d %d %s", pCrnt->hour, pCrnt->minute, pCrnt->description); // Save the data from the current event and do not add a new-line
            }
            
            pCrnt = pCrnt->pNext; // Make pCrnt point to the next event in the linked list
        }
    }

    fclose(pFile); // Close the file

    return 0;
}

// freeList: frees the space in memory where the linked list is occupying
// Input: n/a
// Output: empties the linked list
void freeList()
{
    Event *pCrnt = pFirst;

    while(pCrnt != NULL)
    {
        pFirst = pFirst->pNext;
        free(pCrnt);
        pCrnt = pFirst;
    }

    pLast = NULL;
}

// Main entryway into the program
int main()
{
    char filename[MAXD]; // Holds the name of the user specified file

    // Prompt and retrive the name of the file from which the user wishes to load the event data
    printf("\nPlease enter the name of the file from which you wish to load the schedule: ");
    scanf("%[^\n]s", filename);

    // Load the specified file and inform the user if any errors occur when loading the list
    if(loadList(filename))
    {
        printf("\nAn error occured when loading the list.\n");
        freeList(); // Free the linked list
        return 0;
    }

    // Prompt and retrieve the name of the file into which the user wishes to save the event data
    printf("\nPlease enter the name of the file in which you wish to save the schedule: ");
    fgetc(stdin); // "Eats" the new-line stored in the buffer so that the proceeding scanf can retrieve the file name
    scanf("%[^\n]s", filename);

    // Save the data into the specified file and inform the user if any errors occur when saving the linked list
    if(saveList(filename))
    {
        printf("\nAn error occured when saving the list.\n");
        freeList(); // Free the linked list
        return 0;
    }

    freeList(); // Free the linked list
    return 0;
}