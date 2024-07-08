/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:24:10 by visaienk          #+#    #+#             */
/*   Updated: 2024/07/08 19:56:32 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	q_init(t_queue *q)
{
	q->head = NULL;
	q->tail = NULL;
	q->current = NULL;
}


void	enqueue(t_queue *q, char value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	if (q->head == NULL)
		q->head = node;
	else
		q->tail->next = node;
	q->tail = node;
}

void	del_list(t_queue *q)
{
	t_node	*tmp;

	tmp = q->head;
	while (tmp != NULL)
	{
		tmp = q->head->next;
		free(q->head);
		q->head = tmp;
	}
}

void	del_node(t_queue *q, t_node *node)
{
	t_node	*tmp;

	if (q->head == node)
	{
		if (q->head->next == NULL)
		{
			q->head = NULL;
			q->tail = NULL;
		}
		else
			q->head = q->head->next;
	}
	else
	{
		tmp = q->head;
		while (tmp != NULL && tmp->next != node)
			tmp = tmp->next;
		if (tmp != NULL)
			tmp->next = node->next;
	}
	free(node);
}
