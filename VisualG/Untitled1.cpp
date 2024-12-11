#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TOKEN_PROGRAM, TOKEN_VAR, TOKEN_BEGIN, TOKEN_END, TOKEN_INTEGER,
    TOKEN_REAL, TOKEN_BOOLEAN, TOKEN_IF, TOKEN_THEN, TOKEN_ELSE,
    TOKEN_WHILE, TOKEN_DO, TOKEN_ASSIGN, TOKEN_SEMICOLON, TOKEN_COLON,
    TOKEN_COMMA, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_PLUS, TOKEN_MINUS,
    TOKEN_MUL, TOKEN_DIV, TOKEN_LT, TOKEN_LE, TOKEN_GT, TOKEN_GE,
    TOKEN_EQ, TOKEN_NE, TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[256];
} Token;

const char *keywords[] = {
    "program", "var", "begin", "end", "integer",
    "real", "boolean", "if", "then", "else",
    "while", "do"
};

Token current_token;
FILE *source_file;

int is_keyword(const char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

TokenType keyword_to_token(const char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return (TokenType)(TOKEN_PROGRAM + i);
        }
    }
    return TOKEN_IDENTIFIER;
}

Token get_next_token() {
    char c;
    while ((c = fgetc(source_file)) != EOF) {
        if (isspace(c)) {
            continue; // Ignorar espaços em branco
        }

        // Identificadores e palavras-chave
        if (isalpha(c)) {
            char lexeme[256];
            int i = 0;
            do {
                lexeme[i++] = c;
                c = fgetc(source_file);
            } while (isalnum(c));
            ungetc(c, source_file);
            lexeme[i] = '\0';
            if (is_keyword(lexeme)) {
                return (Token){keyword_to_token(lexeme), ""};
            } else {
                return (Token){TOKEN_IDENTIFIER, lexeme};
            }
        }

        // Números
        if (isdigit(c)) {
            char lexeme[256];
            int i = 0;
            do {
                lexeme[i++] = c;
                c = fgetc(source_file);
            } while (isdigit(c));
            ungetc(c, source_file);
            lexeme[i] = '\0';
            return (Token){TOKEN_NUMBER, lexeme};
        }

        // Operadores e símbolos
        switch (c) {
            case '+': return (Token){TOKEN_PLUS, "+"};
            case '-': return (Token){TOKEN_MINUS, "-"};
            case '': return (Token){TOKEN_MUL, ""};
            case '/': return (Token){TOKEN_DIV, "/"};
            case '=': return (Token){TOKEN_EQ, "="};
            case '<':
                c = fgetc(source_file);
                if (c == '=') return (Token){TOKEN_LE, "<="};
                if (c == '>') return (Token){TOKEN_NE, "<>"};
                ungetc(c, source_file);
                return (Token){TOKEN_LT, "<"};
            case '>':
                c = fgetc(source_file);
                if (c == '=') return (Token){TOKEN_GE, ">="};
                ungetc(c, source_file);
                return (Token){TOKEN_GT, ">"};
            case ':':
                c = fgetc(source_file);
                if (c == '=') return (Token){TOKEN_ASSIGN, ":="};
                ungetc(c, source_file);
                return (Token){TOKEN_COLON, ":"};
            case ';': return (Token){TOKEN_SEMICOLON, ";"};
            case ',': return (Token){TOKEN_COMMA, ","};
            case '(': return (Token){TOKEN_LPAREN, "("};
            case ')': return (Token){TOKEN_RPAREN, ")"};
            default:
                printf("Erro: símbolo desconhecido '%c'\n", c);
                exit(1);
        }
    }
    return (Token){TOKEN_EOF, ""};
}
