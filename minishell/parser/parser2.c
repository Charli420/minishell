/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:15:45 by chabrune          #+#    #+#             */
/*   Updated: 2023/03/14 17:45:21 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_lexer *init_redir_next(t_lexer *curr)
{
    t_lexer *redir;
    redir = malloc(sizeof(t_lexer));
    if(!redir)
        return(NULL);
    redir->token = curr->token;
    if(!curr->next)
        return(NULL);
    else
        redir->str = ft_strdup(curr->next->str);
    redir->next = NULL;
    return(redir);
}

t_lexer *init_redir_prev(t_lexer *curr)
{
    t_lexer *redir;
    redir = malloc(sizeof(t_lexer));
    if(!redir)
        return(NULL);
    redir->token = curr->token;
    if(!curr->prev)
        return(NULL);
    else
        redir->str = ft_strdup(curr->prev->str);
    redir->next = NULL;
    return(redir);
}

void    add_node_redir(t_simple_cmds *curr, t_lexer *redir)
{
    t_lexer *tmp_redir = NULL;
    if(!curr->redirections)
        curr->redirections = redir;
    else
    {
        if(!tmp_redir)
        {
            tmp_redir = curr->redirections;
            while(tmp_redir->next)
                tmp_redir = tmp_redir->next;
        }
        tmp_redir->next = redir;
        redir->prev = tmp_redir;
        tmp_redir = redir;
    }
}

void    add_redir_if_great(t_simple_cmds **head, t_lexer **lexer)
{
    t_simple_cmds *tmpcmd = *head;
    t_lexer *tmplex = *lexer;
    t_lexer *redir;
    while (tmpcmd)
    {
        if(tmplex->token == PIPE)
            tmplex = tmplex->next;
        while(tmplex && tmplex->token != PIPE)
        {
            if(tmplex->token == GREAT || tmplex->token == GREATGREAT)
            {
                redir = init_redir_next(tmplex);
                add_node_redir(tmpcmd, redir);
                del_node(lexer, tmplex->next);
                del_node(lexer, tmplex);
                tmplex = *lexer;
            }
            else
                tmplex = tmplex->next;
        }
        tmpcmd = tmpcmd->next;
    }
}


void    last_lexer_to_strs_cmd(t_lexer **headlex, t_simple_cmds **headcmd)
{
    t_lexer *tmplex;
    t_simple_cmds *tmpcmd;
    tmplex = *headlex;
    tmpcmd = *headcmd;
    int i;

    i = 0;
    while(tmpcmd)
    {
        if(tmplex->token == PIPE)
            tmplex = tmplex->next;
        while(tmplex && tmplex->token != PIPE && tmpcmd->str[i])
        {
            tmpcmd->str[i] = tmplex->str;
            // printf("rest of lexer : %s\n", tmpcmd->str[i]);
            tmplex = tmplex->next;
            i++;
        }
        tmpcmd = tmpcmd->next;
    }
}