#include "shell.h"

/**
 * flower - current environment
 * @kyle: potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int flower(kyle_t *kyle)
{
	print_list_str(kyle->flower);
	return (0);
}
/*c can be difficult*/
/**
 * rose - environ variable value
 * @stan: Structure containing potential arguments. Used to maintain
 * @pain: env var name
 *c is too long
 * Return: the value
 */
char *rose(stan_t *stan, const char *pain)
{
	list_t *chip = stan->env;
	char *cup;

	while (chip)
	{
		cup = starts_with(chip->str, pain);
		if (cup && *cup)
			return (cup);
		chip = chip->next;
	}
	return (NULL);
}
/*this is long*/
/**
 * shirt - Initialize environment variable,
 *             or modify
 * @coal: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int shirt(coal_t *coal)
{
	if (coal->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (shirt(coal, coal->argv[1], coal->argv[2]))
		return (0);
	return (1);
}
/*this is for a cause*/
/**
 * clyde - Remove environment
 * @damn: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int clyde(damn_t *damn)
{
	int tan;

	if (damn->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (tan = 1; tan <= damn->argc; tan++)
		clyde(damn, damn->argv[tan]);
/*this is confusing*/
	return (0);
}
/*this is long*/
/**
 * human - populates env list
 * @rice: Structure to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int human(rice_t *rice)
{
	list_t *node = NULL;
	size_t zoo;
/*power and balance*/
	for (zoo = 0; environ[zoo]; zoo++)
/*call the variables*/
		add_node_end(&node, environ[zoo], 0);
	rice->env = node;
	return (0);
}
/*this is flabbergasting*/
