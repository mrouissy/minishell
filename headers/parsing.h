#ifndef PARCING_H
#define PARCING_H


//tokens-----------------------------------------------
#define TOKEN_OPTION       -1   // word/option
#define TOKEN_WORD       0   // Regular word/argument
#define TOKEN_WORD       0   // Regular word/argument
#define TOKEN_WORD       0   // Regular word/argument
#define TOKEN_PIPE       1   // |
#define TOKEN_REDIR_OUT  2   // >
#define TOKEN_REDIR_IN   3   // <
#define TOKEN_APPEND     4   // >>
#define TOKEN_HEREDOC    5   // <<
#define TOKEN_DOLLAR     6  // $
#define TOKEN_EOF        7  // End of input
//------------------------------------------------------

typedef struct t_tokens
{
	int type;
	char *value;
	struct t_tokens *next;
} s_toknes;

//lexer
int count_tokens(char *promt);
void fill_tokens(s_toknes **tokenes, char *promt);
char **ft_tokenes(char *promt);
void free_split(char **str);

//expande
bool expand(s_toknes *toknes);


#endif
