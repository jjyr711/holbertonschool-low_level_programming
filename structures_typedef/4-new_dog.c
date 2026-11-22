#include "dog.h"
#include <stdlib.h>

/**
 * _str_len - computes the length of a string
 * @s: input string
 *
 * Return: length of string
 */
static int _str_len(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _str_copy - copies a string into newly allocated memory
 * @s: source string
 *
 * Return: pointer to copied string, or NULL on failure
 */
static char *_str_copy(char *s)
{
	char *copy;
	int i, len;

	if (s == NULL)
		return (NULL);
	len = _str_len(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		copy[i] = s[i];
	return (copy);
}

/**
 * new_dog - creates a new dog with copied name and owner strings
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the dog's owner
 *
 * Return: pointer to newly created dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = _str_copy(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->owner = _str_copy(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	d->age = age;
	return (d);
}
