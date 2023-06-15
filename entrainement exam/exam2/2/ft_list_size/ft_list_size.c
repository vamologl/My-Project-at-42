typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

int		ft_list_size(t_list *begin_lst)
{
	int		len;
	t_list	*element;

	len = 0;
	element = begin_lst;
	while (element)
	{
		len++;
		element = element->next;
	}
	return (len);
}

