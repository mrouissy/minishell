#ifndef PARCING_H
#define PARCING_H


//tokens-----------------------------------------------
#define TOKEN_WORD       0   // Regular word/argument
#define TOKEN_PIPE       1   // |
#define TOKEN_REDIR_OUT  2   // >
#define TOKEN_REDIR_IN   3   // <
#define TOKEN_APPEND     4   // >>
#define TOKEN_HEREDOC    5   // <<
#define TOKEN_DOLLAR     10  // $
#define TOKEN_EOF        11  // End of input
//------------------------------------------------------

typedef struct t_tokens
{
	int type;
	char *value;
	struct t_tokens *next;
} s_toknes;

int count_tokens(char *promt);
bool fill_tokens(char *promt);


#endif
