typedef enum {
    WORD,
    ASSIGNMENT_WORD, //lexer or parser ?
    INFILE, 
    OUTFILE, 
    HEREDOC,
    APPEND,
    PIPE,
    OR,
    AND,
    PAREN_OPEN,
    PAREN_CLOSE, 
}   e_token;