#include <stdio.h>

enum figures
{
	Production = 0,
	Gross,
	Rating
};

enum functions
{
	Average = 0,
	Sum,
	Max,
	Min
};
struct list_movie
{
	struct movie *head;
	struct movie *tail;
};

struct movie
{
	struct movie *next;
	struct movie *prev;
	char name[50];
	char genre[20];
	char source[20];
	double values[3];
};

struct list_genre
{
	struct genre_node *head;
	struct genre_node *tail;
	int num_genre;
};

struct genre_node
{
	struct genre_node *next;
	struct genre_node *prev;
	struct list_source *genre_source_list;
	char genre[20];
	int movies_genre;
	double genre_values[3][4];
};

struct list_source
{
	struct source_node *head;
	struct source_node *tail;
	int num_source;
};

struct source_node
{
	struct source_node *next;
	struct source_node *prev;
	struct list_genre *source_genre_list;
	char source[20];
	int movies_source;
	double source_values[3][4];
};