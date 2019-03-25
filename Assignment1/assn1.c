#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "assn1.h"
struct list_movie *movie_list;
struct list_genre *genre_list;
struct list_source *source_list;
void modify_genre_list (struct list_genre *genre_list, struct movie *new_movie, int do_recursive);
void modify_source_list (struct list_source *source_list, struct movie *new_movie,int do_recursive);

int print_menu (void);
void print_list (void);
void add_movie (void);
void pivot_table(void);
void pivot_chart(void);

int main()
{
	movie_list = malloc(sizeof(struct list_movie));
	movie_list->head = NULL;
	movie_list->tail = NULL;
	genre_list = malloc(sizeof(struct list_genre));
	genre_list->head = NULL;
	genre_list->tail = NULL;
	genre_list->num_genre = 0;
	source_list = malloc(sizeof(struct list_source));
	source_list->head = NULL;
	source_list->tail = NULL;
	source_list->num_source = 0;
	while (1)
	{
		
		int selectmenu = print_menu ();
		if (selectmenu == 1)
			add_movie ();
		else if (selectmenu == 2)
			print_list ();
		else if (selectmenu == 3)
			pivot_table ();
		else if (selectmenu == 4)
			pivot_chart ();  
		else
			break;
	}
	struct movie *cur_movie = movie_list->head;
	while (cur_movie != NULL)
	{
		struct movie *next_movie = cur_movie->next;
		free(cur_movie);
		cur_movie = next_movie;
	}
	struct genre_node *cur_genre = genre_list->head;
	while (cur_genre != NULL)
	{
		struct source_node *cur_source1 = cur_genre->genre_source_list->head;
		while (cur_source1 != NULL)
		{
			struct source_node *next_source1 = cur_source1->next;
			free(cur_source1);
			cur_source1 = next_source1;
		}
		struct genre_node *next_genre = cur_genre->next;
		free(cur_genre);
		cur_genre = next_genre;
	}
	struct source_node *cur_source = source_list->head;
	while (cur_source != NULL)
	{
		struct genre_node *cur_genre1 = cur_source->source_genre_list->head;
		while (cur_genre1 != NULL)
		{
			struct genre_node *next_genre1 = cur_genre1->next;
			free(cur_genre1);
			cur_genre1 = next_genre1;
		}
		struct source_node *next_source = cur_source->next;
		free(cur_source);
		cur_source = next_source;
	}
    return 0;
}


int print_menu (void)
{
	int select_menu;
	printf ("----------MENU----------\n");
	printf ("1. Add Movie\n");
	printf ("2. Print List\n");
	printf ("3. Pivot Table\n");
	printf ("4. Pivot Chart\n");
	printf ("5. Exit\n");
	printf ("------------------------\n");
	do{
		printf("Selection: ");
		scanf("%d", &select_menu);
		if (select_menu < 1 || select_menu > 5)
			printf("Try Again!\n");
	} while (select_menu < 1 || select_menu > 5);
	return select_menu;
}

void add_movie ()
{
	char name[50];
	char genre[20];
	char source[20];
	printf ("Name: ");
	scanf ("%s",name);
	for (struct movie *cur = movie_list->head; cur != NULL; cur = cur->next)
	{
		if (strcasecmp (name,cur->name) == 0)
		{
			printf("Error: Movie name already exists.\n");
			return ;
		}
	}
	struct movie *new_movie;
	new_movie = malloc (sizeof(struct movie));
	if (movie_list->head == NULL)
		movie_list->head = new_movie;
	if (movie_list->tail != NULL)
		movie_list->tail->next = new_movie;
	new_movie->prev = movie_list->tail;
	new_movie->next = NULL;
	movie_list->tail = new_movie;
	strncpy (new_movie->name,name,sizeof(new_movie->name));
	printf ("Genre: ");
	scanf ("%s",genre);
	strncpy (new_movie->genre,genre,sizeof(new_movie->genre));
	printf ("Source: ");
	scanf ("%s",source);
	strncpy (new_movie->source,source,sizeof(new_movie->source));
	printf ("Production: ");
	scanf ("%lf",&new_movie->values[Production]);
	printf ("Gross: ");
	scanf ("%lf",&new_movie->values[Gross]);
	printf ("Rating: ");
	scanf ("%lf",&new_movie->values[Rating]);
	modify_genre_list (genre_list,new_movie,1);
	modify_source_list (source_list,new_movie,1);
}

void modify_genre_list (struct list_genre *genre_list, struct movie *new_movie, int do_recursive)
{
	for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
	{
		if (strcasecmp (new_movie->genre,cur->genre) == 0)
		{
			cur->movies_genre++;
			for (int i = 0; i < 3; i++)
			{
				cur->genre_values[i][Sum] += new_movie->values[i];
				cur->genre_values[i][Average] = cur->genre_values[i][Sum]/(double)cur->movies_genre;
				if(cur->genre_values[i][Max] < new_movie->values[i])
					cur->genre_values[i][Max] = new_movie->values[i];
				if(cur->genre_values[i][Min] > new_movie->values[i])
					cur->genre_values[i][Min] = new_movie->values[i];
			}
			if (do_recursive == 1)
				modify_source_list (cur->genre_source_list, new_movie,0);
			break;
		}
		else if (strcasecmp (new_movie->genre,cur->genre) < 0 || cur->next == NULL)
		{
			genre_list->num_genre++;
			struct genre_node *new_genre = malloc(sizeof(struct genre_node));
			if(cur->next == NULL && strcasecmp (new_movie->genre,cur->genre) > 0)
			{
				new_genre->prev = cur;
				new_genre->next = NULL;
				cur->next = new_genre;
				genre_list->tail = new_genre;
			}
			else
			{
				new_genre->prev = cur->prev;
				new_genre->next = cur;
				if(cur->prev != NULL)
					cur->prev->next = new_genre;
				else
					genre_list->head = new_genre;
				cur->prev = new_genre;
			}		
			strncpy (new_genre->genre,new_movie->genre,sizeof(new_genre->genre));
			new_genre->movies_genre = 1;
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0;j < 4; j++)
					new_genre->genre_values[i][j] = new_movie->values[i];
			}
			new_genre->genre_source_list = NULL;
			if (do_recursive == 1)
			{
				new_genre->genre_source_list = malloc(sizeof(struct list_source));
				new_genre->genre_source_list->head = NULL;
				new_genre->genre_source_list->tail = NULL;
				modify_source_list(new_genre->genre_source_list, new_movie,0);
			}
			break;	
		}
		else;
	}
	if (genre_list->head == NULL)
	{
		genre_list->num_genre++;
		struct genre_node *new_genre = malloc(sizeof(struct genre_node));
		genre_list->head = new_genre;
		genre_list->tail = genre_list->head;
		strncpy (new_genre->genre,new_movie->genre,sizeof(new_genre->genre));
		new_genre->movies_genre = 1;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0;j < 4; j++)
				new_genre->genre_values[i][j] = new_movie->values[i];
		}
		new_genre->genre_source_list = NULL;
		if (do_recursive == 1)
		{
			new_genre->genre_source_list = malloc(sizeof(struct list_source));
			new_genre->genre_source_list->head = NULL;
			new_genre->genre_source_list->tail = NULL;
			modify_source_list(new_genre->genre_source_list, new_movie,0);
		}
	}
}

void modify_source_list (struct list_source *source_list, struct movie *new_movie,int do_recursive)
{
	for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
	{
		if (strcasecmp (new_movie->source,cur->source) == 0)
		{
			cur->movies_source++;
			for(int i = 0; i < 3; i++)
			{
				cur->source_values[i][Sum] += new_movie->values[i];
				cur->source_values[i][Average] = cur->source_values[i][Sum]/(double)cur->movies_source;
				if(cur->source_values[i][Max] < new_movie->values[i])
					cur->source_values[i][Max] = new_movie->values[i];
				if(cur->source_values[i][Min] > new_movie->values[i])
					cur->source_values[i][Min] = new_movie->values[i];
			}
			if (do_recursive == 1)
				modify_genre_list(cur->source_genre_list,new_movie,0);
			break;
		}
		else if (strcasecmp (new_movie->source,cur->source) < 0 || cur->next == NULL)
		{
			source_list->num_source++;
			struct source_node *new_source = malloc(sizeof(struct source_node));
			if(cur->next == NULL && strcasecmp (new_movie->source,cur->source) > 0)
			{
				new_source->prev = cur;
				new_source->next = NULL;
				cur->next = new_source;
				source_list->tail = new_source;
			}
			else
			{
				new_source->prev = cur->prev;
				new_source->next = cur;
				if(cur->prev != NULL)
					cur->prev->next = new_source;
				else
					source_list->head = new_source;
				cur->prev = new_source;
			}
			new_source->movies_source = 1;
			strncpy (new_source->source,new_movie->source,sizeof(new_source->source));
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0;j < 4; j++)
					new_source->source_values[i][j] = new_movie->values[i];
			}
			new_source->source_genre_list = NULL;
			if (do_recursive == 1)
			{
				new_source->source_genre_list = malloc(sizeof(struct list_genre));
				new_source->source_genre_list->head = NULL;
				new_source->source_genre_list->tail = NULL;
				new_source->source_genre_list->num_genre = 0;
				modify_genre_list(new_source->source_genre_list, new_movie,0);
			}
			break;
				
		}
		else;
	}
	if (source_list->head == NULL)
	{
		source_list->num_source++;
		struct source_node *new_source = malloc(sizeof(struct source_node));
		source_list->head = new_source;
		source_list->tail = source_list->head;
		strncpy (new_source->source,new_movie->source,sizeof(new_source->source));
		new_source->movies_source = 1;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0;j < 4; j++)
				new_source->source_values[i][j] = new_movie->values[i];
		}
		new_source->source_genre_list = NULL;
		if (do_recursive == 1)
		{
			new_source->source_genre_list = malloc(sizeof(struct list_genre));
			new_source->source_genre_list->head = NULL;
			new_source->source_genre_list->tail = NULL;
			new_source->source_genre_list->num_genre = 0;
			modify_genre_list(new_source->source_genre_list, new_movie,0);
		}
	}
}

void print_list ()
{
	printf("Name\tGenre\tSource\tProduction\tGross\tRating\n");
	for(struct movie *cur = movie_list->head; cur != NULL; cur = cur->next)
	{
		printf("%s\t%s\t%s\t%d\t%d\t%.1f\n",cur->name,cur->genre,cur->source,(int)cur->values[Production],(int)cur->values[Gross],cur->values[Rating]);
	}
}

int print_category ()
{
	int select_category;
	printf ("----------Category----------\n");
	printf ("1. Genre\n");
	printf ("2. Source\n");
	printf ("3. Genre and Source\n");
	printf ("4. Source and Genre\n");
	printf ("----------------------------\n");
	do{
		printf("Selection: ");
		scanf("%d",&select_category);
		if(select_category < 1 || select_category > 4)
			printf("Try again!\n");
	}while (select_category < 1 || select_category > 4);
	return select_category;
}

int print_figure ()
{
	int select_figure;
	printf ("----------Figure----------\n");
	printf ("1. Production\n");
	printf ("2. Gross\n");
	printf ("3. Rating\n");
	printf ("--------------------------\n");
	do{
		printf("Selection: ");
		scanf("%d",&select_figure);
		if(select_figure < 1 || select_figure > 3)
			printf("Try again!\n");
	}while (select_figure < 1 || select_figure > 3);
	return --select_figure;
}

int print_function ()
{
	int select_funtion;
	printf ("----------Function----------\n");
	printf ("1. Average\n");
	printf ("2. Sum\n");
	printf ("3. Max\n");
	printf ("4. Min\n");
	printf ("----------------------------\n");
	do{
		printf("Selection: ");
		scanf("%d",&select_funtion);
		if(select_funtion < 1 || select_funtion > 4)
			printf("Try again!\n");
	}while (select_funtion < 1 || select_funtion > 4);
	return --select_funtion;
}

void pivot_table ()
{
	int select_category = print_category ();
	int select_figure = print_figure ();
	int select_funtion = print_function ();
	char *figures[3] = {"Production","Gross","Rating"};
	
	if (select_category == 1)
	{
		printf ("Genre\t%s\n",figures[select_figure]);
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
			printf("%s\t%.2f\n",cur->genre,cur->genre_values[select_figure][select_funtion]);
	}
	else if (select_category == 2)
	{
		printf ("Source\t%s\n",figures[select_figure]);
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
			printf("%s\t%.2f\n",cur->source,cur->source_values[select_figure][select_funtion]);
	}
	else if (select_category == 3)
	{
		printf ("Genre\tSource\t%s\n",figures[select_figure]);
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
		{
			for (struct source_node *cur_1 = cur->genre_source_list->head; cur_1 != NULL; cur_1 = cur_1->next)
				printf("%s\t%s\t%.2f\n",cur->genre,cur_1->source,cur_1->source_values[select_figure][select_funtion]);
		}
	}
	else 
	{
		printf ("Source\tGenre\t%s\n",figures[select_figure]);
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
		{
			for (struct genre_node *cur_1 = cur->source_genre_list->head; cur_1 != NULL; cur_1 = cur_1->next)
				printf("%s\t%s\t%.2f\n",cur->source,cur_1->genre,cur_1->genre_values[select_figure][select_funtion]);
		}
	}
}

void pivot_chart()
{
	int select_category = print_category ();
	int select_figure = print_figure ();
	int select_funtion = print_function ();
	char *figures[3] = {"Production","Gross","Rating"};
	char *genre_index[genre_list->num_genre];
	char *source_index[source_list->num_source];
	int i = 0;
	int bar;
	double min = 9876543210;
	double max = 0;	
	if (select_category == 1)
	{
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
		{
			if (min > cur->genre_values[select_figure][select_funtion])
				min = cur->genre_values[select_figure][select_funtion];
			if (max < cur->genre_values[select_figure][select_funtion])
				max = cur->genre_values[select_figure][select_funtion];
		}
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
		{
			printf("%c|",65+(i++));
			if(max == min || cur->genre_values[select_figure][select_funtion] == max)
				bar = 20;
			else if (cur->genre_values[select_figure][select_funtion] == min)
				bar = 0;
			else
				bar = (int)((double)20 * (cur->genre_values[select_figure][select_funtion] - min)/(max - min) + 0.9999);
			for(int j = 0;j < bar;j++)
				printf("=");
			printf("%.2f\n",cur->genre_values[select_figure][select_funtion]);
		}
		printf ("----------------------------\n");
		i = 0;
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
			printf("%c: %s\n",65+(i++),cur->genre);
	}
	else if (select_category == 2)
	{
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
		{
			if (min > cur->source_values[select_figure][select_funtion])
				min = cur->source_values[select_figure][select_funtion];
			if (max < cur->source_values[select_figure][select_funtion])
				max = cur->source_values[select_figure][select_funtion];
		}
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
		{
			printf("%d|",++i);
			if (max == min || cur->source_values[select_figure][select_funtion] == max)
				bar = 20;
			else if (cur->source_values[select_figure][select_funtion] == min)
				bar =0;
			else
				bar = (int)((double)20 * (cur->source_values[select_figure][select_funtion] - min)/(max - min) + 0.9999);
			for (int j = 0;j < bar;j++)
				printf("=");
			printf("%.2f\n",cur->source_values[select_figure][select_funtion]);
		}
		printf ("----------------------------\n");
		i = 0;
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
			printf("%d: %s\n",++i,cur->source);
	}
	else if (select_category == 3)
	{
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
		{
			source_index[i] = malloc(sizeof(cur->source));
			strncpy (source_index[i++],cur->source,sizeof(cur->source));
		}
		i = 0;
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
		{
			for (struct source_node *cur_1 = cur->genre_source_list->head; cur_1 != NULL; cur_1 = cur_1->next)
			{
				if (min > cur_1->source_values[select_figure][select_funtion])
					min = cur_1->source_values[select_figure][select_funtion];
				if (max < cur_1->source_values[select_figure][select_funtion])
					max = cur_1->source_values[select_figure][select_funtion];
			}
		}
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
		{
			for (struct source_node *cur_1 = cur->genre_source_list->head; cur_1 != NULL; cur_1 = cur_1->next)
			{
				int j;
				for(j = 0; j < source_list->num_source; j++)
					if(strcasecmp(source_index[j],cur_1->source) == 0)
					{
						j++;
						break;
					}
				printf("%c%d|",i+65,j);
				if(max == min || cur_1->source_values[select_figure][select_funtion] == max)
					bar = 20;
				else if (cur_1->source_values[select_figure][select_funtion] == min)
					bar = 0;
				else
					bar = (int)((double)20 * (cur_1->source_values[select_figure][select_funtion] - min)/(max - min) + 0.9999);
				for(int j = 0;j < bar;j++)
					printf("=");
				printf("%.2f\n",cur_1->source_values[select_figure][select_funtion]);
			}
			i++;
			if(cur->next == NULL)
				printf ("----------------------------\n");
			else
				printf("|\n");
		}
		i = 0;
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
			printf("%c: %s\n",65+(i++),cur->genre);
		i = 0;
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
			printf("%d: %s\n",++i,cur->source);
	}
	else 
	{
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
		{
			genre_index[i] = malloc(sizeof(cur->genre));
			strncpy (genre_index[i++],cur->genre,sizeof(cur->genre));
		}
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
		{
			for (struct genre_node *cur_1 = cur->source_genre_list->head; cur_1 != NULL; cur_1 = cur_1->next)
			{
				if (min > cur_1->genre_values[select_figure][select_funtion])
					min = cur_1->genre_values[select_figure][select_funtion];
				if (max < cur_1->genre_values[select_figure][select_funtion])
					max = cur_1->genre_values[select_figure][select_funtion];
			}
		}
		i = 0;
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
		{
			i++;
			for (struct genre_node *cur_1 = cur->source_genre_list->head; cur_1 != NULL; cur_1 = cur_1->next)
			{
				int j;
				for(j = 0; j < genre_list->num_genre; j++)
					if(strcasecmp(genre_index[j],cur_1->genre) == 0)
						break;
				printf("%d%c|",i,j+65);
				if (max == min || cur_1->genre_values[select_figure][select_funtion] == max)
					bar = 20;
				else if (cur_1->genre_values[select_figure][select_funtion] == min)
					bar = 0;
				else
					bar = (int)((double)20 * (cur_1->genre_values[select_figure][select_funtion] - min)/(max - min) + 0.9999);
				for(int j = 0;j < bar;j++)
					printf("=");
				printf("%.2f\n",cur_1->genre_values[select_figure][select_funtion]);
			}
			if(cur->next == NULL)
				printf ("----------------------------\n");
			else
				printf("|\n");
		}
		i = 0;
		for (struct source_node *cur = source_list->head; cur != NULL; cur = cur->next)
			printf("%d: %s\n",++i,cur->source);
		i = 0;
		for (struct genre_node *cur = genre_list->head; cur != NULL; cur = cur->next)
			printf("%c: %s\n",65+(i++),cur->genre);
	}
}