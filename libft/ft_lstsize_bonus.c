/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:59:50 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/12 20:50:19 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdlib.h>

// typedef struct s_list
// {
//   void *content;
//   struct s_list *next;
// } t_list;

// t_list *ft_lstnew(void *content)
// {
//   t_list *node;

//   node = malloc(sizeof(t_list));
//   if (node == NULL)
//     return (NULL);
//   node->content = content;
//   node->next = NULL;
//   return (node);
// }

// void ft_lstadd_front(t_list **lst, t_list *new)
// {
//   if (lst != NULL && new != NULL)
//   {
//     new->next = *lst;
//     *lst = new;
//   }
// }

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
//     t_list *head;
//     t_list *newhead;

//     head = ft_lstnew("word!");
//     newhead = ft_lstnew("hello ");

//     ft_lstadd_front(&head, newhead);
// 	printf("Count: %d\n", ft_lstsize(head));
// 	return (0);
// }
