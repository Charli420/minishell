/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:16:17 by chabrune          #+#    #+#             */
/*   Updated: 2023/03/14 15:36:42 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

char            **lexer_to_str_array(t_lexer *curr, t_lexer *stop, int *redir);
t_simple_cmds   *group_command(t_lexer **lexer);
void            print_t_lexer_list(t_simple_cmds *head);
void            find_redir(t_simple_cmds **head, t_lexer **lexer);
void    		del_node(t_lexer **head, t_lexer *delone);
t_lexer 		*init_redir_next(t_lexer *curr);
t_lexer 		*init_redir_prev(t_lexer *curr);
void    		add_node_redir(t_simple_cmds *curr, t_lexer *redir);
void    		add_redir_if_great(t_simple_cmds **head, t_lexer **lexer);
void    		add_redir_if_less(t_simple_cmds **head, t_lexer **lexer);
void    		find_redir(t_simple_cmds **head, t_lexer **lexer);
t_simple_cmds    *new_node();
void    		add_back(t_simple_cmds **head, t_simple_cmds *new);
void 			print_cmd(t_simple_cmds **head);
int 			count_cmd(t_simple_cmds **head);
void    		last_lexer_to_strs_cmd(t_lexer **headlex, t_simple_cmds **headcmd);


#endif