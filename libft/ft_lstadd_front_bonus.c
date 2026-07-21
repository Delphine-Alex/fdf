/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:13:51 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/10 21:48:56 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdlib.h>

// typedef struct s_list
// {
//     void            *content;
//     struct s_list   *next;
// }   t_list;

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

// #include <stdio.h>

// int	main(void)
// {
//     t_list *head;
//     t_list *newhead;

//     head = ft_lstnew("word!");
//     newhead = ft_lstnew("hello ");

//     ft_lstadd_front(&head, newhead);

//     t_list *test = head;
//     while (test != NULL)
//     {
//         printf("%s", (char *) test->content);
//         test = test->next;
//     }
// 	return (0);
// }
