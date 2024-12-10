#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct song{
    char title[100];
    char singer[100];
    struct song* next;
};

struct playlist {
    char name[100];
    struct playlist* next;
};

// create
struct song* createSong(char title[], char singer[]) 
{
    struct song* newSong = (struct song*) malloc(sizeof(struct song));

    strcpy(newSong -> title, title);
    strcpy(newSong -> singer, singer); 
    newSong -> next = NULL; 

    return newSong;
} 



struct playlist* createPlaylist(char name[]) {
    struct playlist* newPlaylist = (struct playlist*)malloc(sizeof(struct playlist));

    strcpy(newPlaylist-> name, name); 
    newPlaylist->next = NULL;
    return newPlaylist;
} 
//Playlist;

// Insert
// Insert at End
struct song* insertSongFromUser(struct song* head, char title[], char singer[]) {
    struct song* newSong = createSong(title, singer);
    if (head == NULL) return newSong;

    struct song* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newSong;
    return head;
} 

struct playlist* insertPlaylistFromUser(struct playlist* head, char title[]) {
    struct playlist* newPlaylist = createPlaylist(title);           
    if (head == NULL) return newPlaylist;                            

    struct playlist* temp = head;                                  
    while(temp -> next != NULL)                                       
    {                                                            
        temp = temp -> next;                                     
    }                                                            
    temp -> next = newPlaylist;                                   
    return head;  
}

// insert Song to Playlist
struct playlist* addSongtoPlaylist(struct playlist* head, char title[], char singer[]) {
    struct song* newSong = createSong(title, singer); 
    if (head == NULL) printf("Sorry, playlist not found"); 

    for (int i = 0; i < 100; i++)
    {
        if (title[i] == '\0')
        {
            title[i], title;
            singer[i], singer;
        }
        else if (title[i+1] == '\0')
        {
            title[i+1], title;
            singer[i+1], singer;
        }
    }
    return head;
}

void search(struct song* head, char key[]) {
    struct song* current = head;
    int index = 0;
    while (current != NULL) {
        if (strcmp((current->next)->title, key) == 1) {
            printf("%s", current->singer);
            break; // Element found
        }
        current = current->next;
    }
    // printf("elemen tidak ditemukan.\n");
     // Element not found
}


// Delete at Index
struct song* deleteSong(struct song* head, int index) {
    struct song* temp = head;                                       
    struct song* temp_delete; 

    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {        
        temp = temp -> next;                  
    }

    if (temp_delete == NULL) return head;            
    temp_delete = temp -> next;                       
    temp -> next = temp -> next -> next;                    
    free(temp_delete);                                    
    return head;  
}

struct playlist* deletePlaylist(struct playlist* head, int index) {
    struct playlist* temp = head;                                         
    struct playlist* temp_delete;                                  

    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {                                                           
        temp = temp -> next;                                     
    }

    if (temp_delete = NULL) return head;                        
    temp_delete = temp -> next;                                  
    temp -> next = temp -> next -> next;                      
    free(temp_delete);                                        
    return head;  
}



void printSong(struct song *head)                                           
{
    printf("Title\t\tSinger\n");                                                 
    struct song* temp = head;                          
    while (temp != NULL)                                               
    {                 
        printf("%s\t\t%s\n", temp->title, temp->singer);   
        temp = temp -> next;                           
    }
    printf("\n\n");

}

void printPlaylist(struct playlist *head, struct song *head2)                                           
{
    struct playlist* temp = head;
    while (temp != NULL)                                               
    {                                                                  
        printf("%s\n\n", temp->name);   
        temp = temp -> next;
    }
    printSong(head2);
}
    
// }

int main()
{
    struct song* head = createSong("Ini Aku", "Devano Danendra");
    head -> next = createSong("Wow", "Afgan");
    head -> next -> next = createSong("Newt", "John Mayer");
    struct playlist* head_2 = createPlaylist("Ini Playlist");


    // printSong(head);
    addSong(head, "Ini Aaa", "AAAA");
    printPlaylist(head_2, head);
    // deleteSong(head, 1);
    printPlaylist(head_2, head);
    search(head, "Newt");

}



