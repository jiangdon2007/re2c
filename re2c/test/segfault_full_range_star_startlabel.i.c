re2c: warning: line 3: unreachable rule  [-Wunreachable-rules]
/* Generated by re2c */

{
	YYCTYPE yych;
start:
	goto yy0;
yy1:
	++YYCURSOR;
yy0:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy1;
	{}
}

