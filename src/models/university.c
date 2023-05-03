/**
 * File		: university.c
 * Author		: Tountoun Abel AYANOU
 * Created at	: April 24 2023
 * Last update	: May 3 2023
 */

#include "syges.h"
#include "university.h"
#include <string.h>

const char *const countries[] = {
    "Togo",
    "Benin",
    "Ghana",
    "Ivory Coast",
    "Senegal",
    "Nigeria",
    "Ethiopia",
    "Kenya",
    "Uganda",
    "Morocco",
    "Angola",
    "Niger",
    "Mali",
    "Burkina Faso",
    "Cameroon",
    "Liberia",
    "Congo"
};

/**
 * createUniversity - creates a new university based on the given properties
 * 
 * @name: a pointer to the name of the university
 * @addresse: a pointer to the addresse of the university
 * @country: a pointer to the country of the university
 * @creation_date: the creation date of the university
 * 
 * Return: a pointer to the newly created university or NULL on failure
*/
university_t *createUniversity(char *name, addr_t *addresse, country_t *country, struct tm creation_date)
{
	university_t *new_university;

	if (!name || !addresse || !country)
		return (NULL);

	new_university = (university_t *)malloc(sizeof(university_t));
	if (!new_university)
		return (NULL);

	new_university->id = generateID(name, country);
	new_university->name = strdup(name);
	new_university->addr = addresse;
	new_university->country = country;
	new_university->since = creation_date;

     return (new_university);
}

/**
 * addUniversity - adds a new university at the end of a linked list of universities
 *
 * @univ: pointer to the new university
 * @head: pointer to the list
 *
 * Return: 0 if @univ is successfully added, else -1
 */
int addUniverisity(university_t *univ, linked_university_t **head)
{
	linked_university_t *current, *new;

	if (head == NULL)
		return (-1);

	new = (linked_university_t *)malloc(sizeof(linked_university_t));
	new->next = NULL;
	new->univ = univ;

	if (new == NULL)
		return (-1);

	if (*head == NULL)
		(*head) = new;
	else 
	{
		current = (*head);
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (0);
}

/**
 * deleteUniversity - deletes a university based on its id in a linked list
 * 
 * @univ_id: a pointer to the string that represents the id of the university
 * @head: a pointer to the first element in the linked list
 * 
 * Return: 0 on success; -1 on failure
*/
int deleteUniversity(char *univ_id, linked_university_t **head)
{
	linked_university_t *current, *prev, *tmp;
	char *key;

	if (!univ_id || !head || !(*head))
		return (-1);
	current = *head;
	prev = NULL;

	while (current)
	{
		key = generateID(current->univ->name, current->univ->country);
		if (strcmp(univ_id, key) == 0)
		{
			if (size(head) == 1)
			{
				tmp = current;
				current = NULL;
			}
			else
			{
				tmp = current;
				prev->next = current->next;
			}
			free(tmp->univ->id);
			free(tmp->univ->addr);
			free(tmp->univ);
			free(tmp);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	/* ID not found */
     return (-1);
}

/**
 * updateUniversity - updates a university
 * 
 * @univ: a pointer to the university to be updated
 * 
 * Return: 0 on success; -1 on failure
*/
int updateUniversity(university_t *univ)
{
	if (univ == NULL)
		return (-1);

	/*TODO: Make sure that the name or the country has changed */	
	univ->id = generateID(univ->name, univ->country);
	return (0);
}

/**
 * viewAllUniversities - displays all universities saved in a linked list
 * 
 * @head: a pointer to the first element in the linked list
 * 
 * Return: nothing
*/
void viewAllUniversities(linked_university_t **head)
{
	linked_university_t *current;

	if (!(head) || !(*head))
		return;

	current = *head;
	while (current)
	{
		printf("ID: %s\n", current->univ->id);
		printf("Name: %s\n", current->univ->name);
		printf("Address: \n");
		printf("\tCountry: %s\n", countries[*(current->univ->country)]);
		printf("\tCity: %s\n", current->univ->addr->city);
		printf("\tRoad: %s\n", current->univ->addr->road);
		struct tm *date = &(current->univ->since);
		printf("Creation date: %d/%d/%d\n", date->tm_mday, date->tm_mon, (date->tm_year + 1900));
		printf("\n");
		current = current->next;
	}
}

/**
 * viewUniversity - displays a single university based on its id
 * 
 * @key: a pointer to the string that represents the id of the university
 * @head: a pointer to the first element in the linked list
 * 
 * Return: nothing
*/
void viewUniversity(char *key, linked_university_t **head)
{
	university_t *univ;
	
	univ = getUniversity(key, head);
	if (univ)
	{
		printf("ID: %s\n", univ->id);
		printf("Name: %s\n", univ->name);
		printf("Address: \n");
		printf("\tCountry: %s\n", countries[*(univ->country)]);
		printf("\tCity: %s\n", univ->addr->city);
		printf("\tRoad: %s\n", univ->addr->road);
		struct tm *date = &(univ->since);
		printf("Creation date: %d/%d/%d\n", date->tm_mday, date->tm_mon, (date->tm_year + 1900));
		printf("\n");
	}
	else
		printf("No university has the ID you entered\n");

}

/**
 * size - calculates the number of elements in a linked list
 * 
 * @head: a pointe to the first element of the linked list
 * 
 * Return: the number of elements in the list
*/
size_t size(linked_university_t **head)
{
	size_t size;
	linked_university_t *current;

	if (!head || !(*head))
		return ((size_t)NULL);

	size = 0;
	current = *head;
	while (current)
	{
		current = current->next;
		size++;
	}

     return (size);
}

/**
 * len - counts the number of characters in the string
 * 
 * @str: a pointer to the string to be used
 * 
 * Return: the number of characters in @str
*/
int len(const char *str)
{
	int length;
	length = 0;
	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * generateID - generates a unique string as id for a university
 * 
 * @name: a pointer to the string that represents the name of the university
 * @country: a pointer to the country that hosts the university
 * 
 * Return: a pointer to the string that represents the id
*/
char *generateID(char *name, country_t *country)
{
	char *id, *countryString;

	countryString = (char *)countries[*country];
	id = strdup(name);
	/* 2 because append a space first and take in account the end of str */
	id = realloc(id, len(id) + len(countryString) + 2);
	strcat(strcat(id, " "), countryString);

	return (id);
}

/**
 * getUniversity - gets a specific university in a linked list
 * 
 * @key: a pointer to the string that represents the id of the university
 * @head: a pointer to the first element of the linked list
 * 
 * Return: a pointer to the university found or NULL
*/
university_t *getUniversity(char *key, linked_university_t **head)
{
	linked_university_t *current;

	if (head == NULL || *head == NULL)
		return (NULL);

	current = *head;
	while (current)
	{
		if ((strcmp(key, current->univ->id) == 0))
			return (current->univ);
		current = current->next;
	}
	return (NULL);
}
