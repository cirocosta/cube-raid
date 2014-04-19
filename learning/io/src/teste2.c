#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

// The representation of a row in the table of Addresses
struct Address
{
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

// The database, which contains only one table here (the Address table).
// It contains multiple rows.
struct Database
{
    struct Address rows[MAX_ROWS];
};

// the connection with the Database. It stores a FILE and the Database
// struct.
struct Connection
{
    // a structure describing an opened file. It is implemented in
    // stdio.h.
    FILE *file;
    struct Database *db;
};

// Aborts with an error.
void die(const char *message)
{
    // when we have an error returning from a function, it will have an
    // external variable called errno to say what exactly happened. As
    // errno is just a number, perror will the print the error message
    // related to that number.
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

// Sends to STDOUT a representation of a Row.
void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    // fread(void *ptr, int size, int nmemb, FILE *stream). fread reads
    // data from the given STREAM into the array pointed to by PTR. The
    // PTR must have the minimum size of (size*nmemb), being size the
    // size in bytes of each element to be read and nmemb the number of
    // elements. STREAM is the pointer to a FILE object that specifies
    // an input stream.
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) {
        die("Failed to load database");
    }
}


int main(int argc, char const *argv[])
{

    return 0;
}
