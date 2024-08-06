
#include "parsing.h"

int check_redir_syntax1(char *line, int i)
{
  if (line[i] == '>')
  {
    if (line[i + 1] == '>')
      return (error_syntax(">>"));
    if (line[i + 1] == '|')
      return (error_syntax(">|"));
    return (error_syntax(">"));
  }
  if (line[i] == '|')
    return (error_syntax("|"));
  return (0);
}

int check_redir_syntax2(char *line, int *i)
{
  if (line[*i] == '<') {
    while (line[*i] == ' ')
      *i += 1;
    if (line[*i + 1] == '<')
      return (error_syntax("<<<"));
    return (error_syntax("<<"));
  }
  if (line[*i] == '>')
    return (error_syntax("<>"));
  return (error_syntax("<"));
}

int check_redir_syntax3(char *line, int *i)
{
  if (line[*i] == '<') {
    *i += 1;
    return check_redir_syntax2(line, i);
  }
  if (line[*i] == '|')
    return (error_syntax(""));
  return (0);
}

int check_redir_syntax4(char *line, int *i)
{
  if (line[*i + 1] == '<') {
    if (line[*i + 2] == '<') {
      if (line[*i + 3] == '<')
        return (error_syntax("<<<"));
      return (error_syntax("<<"));
    }
    if (line[*i + 2] == '>')
      return (error_syntax("<>"));
    return (error_syntax("<"));
  }
  if (line[*i + 1] == '>')
    return (error_syntax(">"));
  if (line[*i + 1] == '|')
    return (error_syntax("|"));
  return (0);
}