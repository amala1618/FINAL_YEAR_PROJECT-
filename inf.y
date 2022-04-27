start: expr '\n'	{exit(1);}
     ;
expr:  expr '+' expr	{printf("+ ");}
    | expr '*' expr	{printf("* ");}
    | '(' expr ')'
    | DIGIT		{printf("NUM%d ",pos);}
    ;
