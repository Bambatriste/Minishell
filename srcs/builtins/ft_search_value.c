#include "../../includes/minishell.h"

int	found_in_env(char *str, void *content)
{
	t_env_str *content2 = (t_env_str *)content;
	size_t len;

	len = ft_strlen(content2->name);
	if (ft_strlen(str) == len)
	{
		if (ft_strncmp(content2->name, str, len) == 0)
			return (1);
	}
	return (0);
}

char	*ft_get_value(void *content)
{	
	t_env_str *content2 = (t_env_str *)content;
	return (content2->value);
}

char	*ft_search_value(t_list *lst, char *name)
{
	while(lst)
	{
		if (found_in_env(name, lst->content))
			return (ft_get_value(lst->content));
		lst = lst->next;
	}
	return (NULL);
}

int	ft_check_if_exists(t_list *lst, char *name)
{
	while(lst)
	{
		if (found_in_env(name, lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}