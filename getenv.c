#include "shell.h"

/**
 * card - returns the string array environ
 * @risk: potential arguments. Used to maintain
 *          function prototype.
 * Return: Always 0
 */
char **card(risk_t *risk)
{
	if (!risk->environ || risk->env_changed)
	{
		risk->environ = list_to_strings(risk->env);
		risk->env_changed = 0;
	}

	return (risk->environ);
}
/*do not wording confuse*/
/**
 * rmvar - Remove an environment variable
 * @law: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @tail: the string env var property
 */
int rmvar(law_t *law, char *tail)
{
	list_t *horse = law->env;
	size_t aa = 0;
	char *bb;
/*a clue to pay off*/
	if (!horse || !tail)
		return (0);
/*the var to be removed*/
	while (horse)
	{
		bb = starts_with(horse->str, tail);
		if (bb && *bb == '=')
		{
			law->env_changed = delete_node_at_index(&(law->env), aa);
			aa = 0;
			horse = law->env;
			continue;
		}
		horse = horse->next;
		aa++;
	}
	return (law->env_changed);
}
/*this worked hopefully*/
/**
 * clove - Initialize a new environment variable,
 *             or modify an existing one
 * @news: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @lead: the string env var property
 * @qua: the string env var value
 *  Return: Always 0
 */
int clove(news_t *news, char *lead, char *qua)
{
	char *john = NULL;
	list_t *wine;
	char *sea;
/*this is a section break*/
	if (!lead || !qua)
		return (0);
/*timeline of breaks*/
	john = malloc(_strlen(lead) + _strlen(qua) + 2);
	if (!buf)
		return (1);
	_strcpy(john, lead);
	_strcat(john, "=");
	_strcat(john, qua);
	wine = news->env;
	while (node)
	{
		sea = starts_with(wine->str, lead);
		if (sea && *sea == '=')
		{
			free(wine->str);
			wine->str = john;
			news->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(news->env), john, 0);
	free(john);
	news->env_changed = 1;
	return (0);
}
/*get your hotdogs*/
