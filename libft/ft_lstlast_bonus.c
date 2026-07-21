/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:32:51 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/12 20:35:48 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdlib.h>

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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int nb1 = 42;
// 	int nb2 = 21;
// 	int nb3 = 84;

// 	t_list *lst = ft_lstnew(&nb1);
// 	t_list *new_node1 = ft_lstnew(&nb2);
// 	t_list *new_node2 = ft_lstnew(&nb3);

// 	ft_lstadd_front(&lst, new_node1);
// 	ft_lstadd_front(&lst, new_node2);

// 	t_list *last = ft_lstlast(lst);
// 	printf("%d\n", *(int *)last->content);
// 	return (0);
// }
